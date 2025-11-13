/***************************************************************
 * This source files comes from the xLights project
 * https://www.xlights.org
 * https://github.com/xLightsSequencer/xLights
 * See the github commit history for a record of contributing
 * developers.
 * Copyright claimed based on commit dates recorded in Github
 * License: https://github.com/xLightsSequencer/xLights/blob/master/License.txt
 **************************************************************/

#include "DMXMHEffect.h"
#include "DMXMHPanel.h"
#include "../sequencer/Effect.h"
#include "../RenderBuffer.h"
#include "../UtilClasses.h"
#include "../models/Model.h"
#include "../models/ModelGroup.h"

#include "../models/DMX/DmxMovingHeadComm.h"
#include "../models/DMX/DmxMotor.h"

#include "wx/slider.h"
#include "wx/stattext.h"
#include "wx/textctrl.h"
#include "wx/checkbox.h"
#include <wx/bmpbuttn.h>
#include <wx/panel.h>
#include <wx/window.h>

#include "../../include/dmxmh-16.xpm"
#include "../../include/dmxmh-24.xpm"
#include "../../include/dmxmh-32.xpm"
#include "../../include/dmxmh-48.xpm"
#include "../../include/dmxmh-64.xpm"
#include "UtilFunctions.h"

DMXMHEffect::DMXMHEffect(int id) : RenderableEffect(id, "DMX MH", dmxmh_16, dmxmh_24, dmxmh_32, dmxmh_48, dmxmh_64)
{
    //ctor
}

DMXMHEffect::~DMXMHEffect()
{
    //dtor
}

void DMXMHEffect::RemapSelectedDMXMHEffectValues(Effect* effect, const std::vector<std::tuple<int, int, float, int, wxString>>& dmxmappings) const {
    SettingsMap &settings = effect->GetSettings();
    SettingsMap const oldSettings = settings;
    for (auto const& [fromi, toi, scale, offset, inv] : dmxmappings) {
        auto const froms = wxString::Format("%d", fromi);
        auto const tos = wxString::Format("%d", toi);
        auto const slider = oldSettings.Get("E_SLIDER_DMXMH" + froms, "NOTTHERE");
        auto const vc = oldSettings.Get("E_VALUECURVE_DMXMH" + froms, "NOTTHERE");
        auto invert_chbx = oldSettings.Get("E_CHECKBOX_INVMHDMXMH" + froms, "NOTTHERE");

        if (slider != "NOTTHERE") {
            int const new_value = ((float)std::stoi(slider) * scale) + offset;
            settings["E_SLIDER_DMXMH" + tos] = std::to_string( new_value);
        } else {
            settings.erase("E_SLIDER_DMXMH" + tos);
        }

        if (vc != "NOTTHERE") {
            ValueCurve valc;
            valc.SetDivisor(1.0F);
            valc.SetLimits(DMXMH_MIN, DMXMH_MAX);
            valc.Deserialise(vc);
            valc.ScaleAndOffsetValues(scale, offset);
            settings["E_VALUECURVE_DMXMH" + tos] = valc.Serialise();
        } else {
            settings.erase("E_VALUECURVE_DMXMH" + tos);
        }

        if (inv == "Check") {
            invert_chbx = "1";
        } else if (inv == "Uncheck") {
            invert_chbx = "0";
        }

        if (invert_chbx != "NOTTHERE") {
            settings["E_CHECKBOX_INVMHDMXMH" + tos] = invert_chbx;
        } else {
            settings.erase("E_CHECKBOX_INVMHDMXMH" + tos);
        }
    }
}

xlEffectPanel *DMXMHEffect::CreatePanel(wxWindow *parent) {
    return new DMXMHPanel(parent);
}

static int GetPctMH(wxString const& val)
{
    int value = wxAtoi(val);
    return (value * 100) / 255;
}

void DMXMHEffect::SetDefaultParameters() {
    DMXMHPanel *dp = (DMXMHPanel*)panel;
    if (!dp) return;

    if (dp->ValueCurve_DMXMH1) dp->ValueCurve_DMXMH1->SetActive(false);
    if (dp->ValueCurve_DMXMH2) dp->ValueCurve_DMXMH2->SetActive(false);

    if (dp->CheckBox_INVDMXMH1) static_cast<wxCheckBox*>(dp->CheckBox_INVDMXMH1)->SetValue(false);
    if (dp->CheckBox_INVDMXMH2) static_cast<wxCheckBox*>(dp->CheckBox_INVDMXMH2)->SetValue(false);
}

void DMXMHEffect::adjustSettings(const std::string &version, Effect *effect, bool removeDefaults)
{
    // give the base class a chance to adjust any settings
    if (RenderableEffect::needToAdjustSettings(version))
    {
        RenderableEffect::adjustSettings(version, effect, removeDefaults);
    }

    SettingsMap &settings = effect->GetSettings();

    if (IsVersionOlder("2016.39", version))
    {
        if (settings.GetBool("E_CHECKBOX_Use_Dmx_Ramps")) {
            settings["E_VALUECURVE_DMXMH1"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMXMH1|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|RV=TRUE|", GetPctMH(settings["E_SLIDER_DMXMH1"]), GetPctMH(settings["E_SLIDER_DMXMH1_Ramp"]));
            settings["E_VALUECURVE_DMXMH2"] = wxString::Format("Active=TRUE|Id=ID_VALUECURVE_DMXMH2|Type=Ramp|Min=0.00|Max=255.00|P1=%d|P2=%d|RV=TRUE|", GetPctMH(settings["E_SLIDER_DMXMH2"]), GetPctMH(settings["E_SLIDER_DMXMH2_Ramp"]));
            settings.erase("E_SLIDER_DMXMH1");
            settings.erase("E_SLIDER_DMXMH2");
        } else {
            // No DMXMH16 for 2-channel setup
        }
        settings.erase("E_CHOICE_Num_Dmx_Channels");
        settings.erase("E_CHECKBOX_Use_Dmx_Ramps");
        settings.erase("E_SLIDER_DMXMH1_Ramp");
        settings.erase("E_SLIDER_DMXMH2_Ramp");
    }
}

bool DMXMHEffect::SetDMXMHSinglColorPixel(int chan, int num_channels, const SettingsMap &SettingsMap, double eff_pos, xlColor& color, RenderBuffer &buffer)
{
    if( num_channels >= chan ) {
        std::string const name = wxString::Format("DMXMH%d", chan).ToStdString();
        int value = GetValueCurveInt(name, 0, SettingsMap, eff_pos, DMXMH_MIN, DMXMH_MAX, buffer.GetStartTimeMS(), buffer.GetEndTimeMS());

        if (SettingsMap.GetBool("CHECKBOX_INVMH" + name, false))
        {
            value = 255 - value;
        }

        color.red = value;
        color.green = value;
        color.blue = value;
        buffer.SetPixel(chan-1, 0, color, false, false, true);
        return false;
    } 
    return true;
}

void DMXMHEffect::SetColorBasedOnStringType(int value, int slot, xlColor& color, const std::string& string_type)
{
    const char which_color = string_type[slot-1];
    if( which_color == 'R' ) {
        color.red = value;
    } else if( which_color == 'G' ) {
        color.green = value;
    } else if( which_color == 'B' ) {
        color.blue = value;
    }
}

bool DMXMHEffect::SetDMXMHRGBNode(int node, int num_channels, const SettingsMap &SettingsMap, double eff_pos, xlColor& color, RenderBuffer &buffer, const std::string& string_type)
{
    bool return_val = false;
    color = xlBLACK;
    int const base_chan = ((node - 1) * 3 + 1);
    if( num_channels >= base_chan || buffer.BufferWi < node) {
        std::string name = wxString::Format("DMXMH%d", base_chan).ToStdString();
        int value = GetValueCurveInt(name, 0, SettingsMap, eff_pos, DMXMH_MIN, DMXMH_MAX, buffer.GetStartTimeMS(), buffer.GetEndTimeMS());

        if (SettingsMap.GetBool("CHECKBOX_INVMH" + name, false)) {
            value = 255 - value;
        }

        SetColorBasedOnStringType(value, 1, color, string_type);
        if( num_channels >= base_chan + 1 ) {
            name = wxString::Format("DMXMH%d", base_chan+1);
            value = GetValueCurveInt(name, 0, SettingsMap, eff_pos, DMXMH_MIN, DMXMH_MAX, buffer.GetStartTimeMS(), buffer.GetEndTimeMS());

            if (SettingsMap.GetBool("CHECKBOX_INVMH" + name, false)) {
                value = 255 - value;
            }

            SetColorBasedOnStringType(value, 2, color, string_type);
            if( num_channels >= base_chan + 2 ) {
                name = wxString::Format("DMXMH%d", base_chan + 2);
                value = GetValueCurveInt(name, 0, SettingsMap, eff_pos, DMXMH_MIN, DMXMH_MAX, buffer.GetStartTimeMS(), buffer.GetEndTimeMS());

                if (SettingsMap.GetBool("CHECKBOX_INVMH" + name, false)) {
                    value = 255 - value;
                }

                SetColorBasedOnStringType(value, 3, color, string_type);
            } else {
                return_val = true;
            }
        } else {
            return_val = true;
        }
        buffer.SetPixel(node-1, 0, color, false, false, true);
    } else {
        return_val = true;
    }
    return return_val;
}

void DMXMHEffect::Render(Effect *effect, const SettingsMap &SettingsMap, RenderBuffer &buffer) {
    double const eff_pos = buffer.GetEffectTimeIntervalPosition();

    if (buffer.cur_model.empty()) {
        return;
    }
    const Model* model_info = buffer.GetModel();
    if (model_info == nullptr) {
        return;
    }

    int const num_channels = model_info->GetNumChannels();
    const std::string& string_type = model_info->GetStringType();
    xlColor color = xlBLACK;

    // Get pan range from model (degrees)
    int pan_range = wxAtoi(model_info->GetModelXml()->GetAttribute("RangeOfMotion", "540"));
    float pan_pos = GetValueCurveInt("DMXMH1", 0, SettingsMap, eff_pos, 0, pan_range * 10, buffer.GetStartTimeMS(), buffer.GetEndTimeMS()) / 10.0f;
    float tilt_pos = GetValueCurveInt("DMXMH2", 0, SettingsMap, eff_pos, -1800, 1800, buffer.GetStartTimeMS(), buffer.GetEndTimeMS()) / 10.0f;

    // Apply inversion if needed
    if (SettingsMap.GetBool("CHECKBOX_INVMHDMXMH1", false)) {
        pan_pos = -pan_pos;
    }
    if (SettingsMap.GetBool("CHECKBOX_INVMHDMXMH2", false)) {
        tilt_pos = -tilt_pos;
    }

    // --- Begin self-contained motor logic ---
    // Example: Assume pan uses channels 1/2, tilt uses channels 3/4 (coarse/fine)
    auto WriteCmdToPixel = [](int coarse, int fine, int cmd, RenderBuffer& buffer) {
        uint8_t msb = (cmd >> 8) & 0xFF;
        uint8_t lsb = cmd & 0xFF;
        xlColor msb_c = xlBLACK;
        msb_c.red = msb;
        msb_c.green = msb;
        msb_c.blue = msb;
        xlColor lsb_c = xlBLACK;
        lsb_c.red = lsb;
        lsb_c.green = lsb;
        lsb_c.blue = lsb;
        if (coarse > 0) buffer.SetPixel(coarse - 1, 0, msb_c, false, false, true);
        if (fine > 0) buffer.SetPixel(fine - 1, 0, lsb_c, false, false, true);
    };

    // Conversion: map 0 to 540 degrees to 0-65535 DMX
    auto ConvertDegreesToDMX = [](float degrees, float min_deg, float max_deg) {
        float clamped = std::max(min_deg, std::min(max_deg, degrees));
        float norm = (clamped - min_deg) / (max_deg - min_deg);
        return static_cast<int>(norm * 65535.0f + 0.5f);
    };

    int pan_cmd = ConvertDegreesToDMX(pan_pos, 0.0f, static_cast<float>(pan_range));
    int tilt_cmd = ConvertDegreesToDMX(tilt_pos, -180.0f, 180.0f);
    // Channels: pan coarse=1, pan fine=2; tilt coarse=3, tilt fine=4
    WriteCmdToPixel(1, 2, pan_cmd, buffer);
    WriteCmdToPixel(3, 4, tilt_cmd, buffer);
    // --- End self-contained motor logic ---

    // Handle remaining channels as before
    if (StartsWith(string_type, "Single Color")) {
        for (uint32_t i = 5; i <= DMXMH_CHANNELS; ++i) {
            if (SetDMXMHSinglColorPixel(i, num_channels, SettingsMap, eff_pos, color, buffer))
                return;
        }
    } else {
        for (uint32_t i = 2; i <= DMXMH_CHANNELS / 3; ++i) {
            if (SetDMXMHRGBNode(i, num_channels, SettingsMap, eff_pos, color, buffer, string_type))
                return;
        }
    }
}

void DMXMHEffect::SetPanelStatus(Model *cls) {
    DMXMHPanel *p = (DMXMHPanel*)panel;
    if (!p || !cls) return;
    Model* m = cls;
    if (cls->GetDisplayAs() == "ModelGroup") {
        m = dynamic_cast<ModelGroup*>(cls)->GetFirstModel();
        if (!m) m = cls;
    }
    // Only update pan/tilt labels for now
    // No SetLabel needed for wxStaticText, as label is set in constructor
    if (p->CheckBox_INVDMXMH1) p->CheckBox_INVDMXMH1->SetValue(false);
    if (p->CheckBox_INVDMXMH2) p->CheckBox_INVDMXMH2->SetValue(false);
    if (p->FlexGridSizer_Panel1) p->FlexGridSizer_Panel1->Layout();
    if (p->FlexGridSizer_Main) p->FlexGridSizer_Main->Layout();
}
