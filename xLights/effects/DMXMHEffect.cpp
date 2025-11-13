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

#include "../../include/dmx-16.xpm"
#include "../../include/dmx-24.xpm"
#include "../../include/dmx-32.xpm"
#include "../../include/dmx-48.xpm"
#include "../../include/dmx-64.xpm"
#include "UtilFunctions.h"

DMXMHEffect::DMXMHEffect(int id) : RenderableEffect(id, "DMX MH", dmx_16, dmx_24, dmx_32, dmx_48, dmx_64)
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
    if (dp == nullptr) {
        return;
    }

    dp->ValueCurve_DMXMH1->SetActive(false);
    dp->ValueCurve_DMXMH2->SetActive(false);

    dp->Slider_DMXMH1->SetValue(0);
    dp->Slider_DMXMH2->SetValue(0);

    dp->CheckBox_INVDMXMH1->SetValue(false);
    dp->CheckBox_INVDMXMH2->SetValue(false);
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

    // Pan/Tilt to DMX conversion for channels 1-4
    // Pan and Tilt are 16-bit values (0-65535) representing 0-3600 degrees
    // DMX mapping: Channel 1 = Pan coarse (MSB), Channel 2 = Pan fine (LSB),
    //             Channel 3 = Tilt coarse (MSB), Channel 4 = Tilt fine (LSB)
    
    // Get Pan value (0-65535 representing 0-3600 degrees)
    int pan_16bit = GetValueCurveInt("DMXMH1", 0, SettingsMap, eff_pos, 0, 65535, buffer.GetStartTimeMS(), buffer.GetEndTimeMS());
    int pan_coarse = (pan_16bit >> 8) & 0xFF;  // MSB
    int pan_fine = pan_16bit & 0xFF;            // LSB
    
    // Get Tilt value (0-65535 representing 0-3600 degrees)
    int tilt_16bit = GetValueCurveInt("DMXMH2", 0, SettingsMap, eff_pos, 0, 65535, buffer.GetStartTimeMS(), buffer.GetEndTimeMS());
    int tilt_coarse = (tilt_16bit >> 8) & 0xFF;  // MSB
    int tilt_fine = tilt_16bit & 0xFF;            // LSB
    
    // Apply inversion if needed
    if (SettingsMap.GetBool("CHECKBOX_INVMHDMXMH1", false)) {
        pan_coarse = 255 - pan_coarse;
        pan_fine = 255 - pan_fine;
    }
    if (SettingsMap.GetBool("CHECKBOX_INVMHDMXMH2", false)) {
        tilt_coarse = 255 - tilt_coarse;
        tilt_fine = 255 - tilt_fine;
    }
    
    // Set Pan/Tilt channels
    if (num_channels >= 1) {
        color.red = pan_coarse;
        color.green = 0;
        color.blue = 0;
        buffer.SetPixel(0, 0, color, false, false, true);
    }
    if (num_channels >= 2) {
        color.red = pan_fine;
        color.green = 0;
        color.blue = 0;
        buffer.SetPixel(1, 0, color, false, false, true);
    }
    if (num_channels >= 3) {
        color.red = tilt_coarse;
        color.green = 0;
        color.blue = 0;
        buffer.SetPixel(2, 0, color, false, false, true);
    }
    if (num_channels >= 4) {
        color.red = tilt_fine;
        color.green = 0;
        color.blue = 0;
        buffer.SetPixel(3, 0, color, false, false, true);
    }
    
    // Handle remaining channels (5+) as before
    if (StartsWith(string_type, "Single Color")) {
        // handle channels for single color nodes
        for (uint32_t i = 5; i <= DMXMH_CHANNELS; ++i) {
            if (SetDMXMHSinglColorPixel(i, num_channels, SettingsMap, eff_pos, color, buffer))
                return;
        }
   } else {
        // handle channels for 3 color nodes
       for (uint32_t i = 2; i <= DMXMH_CHANNELS / 3; ++i) {
            if (SetDMXMHRGBNode(i, num_channels, SettingsMap, eff_pos, color, buffer, string_type))
                return;
        }
    }
}

void DMXMHEffect::SetPanelStatus(Model *cls) {
    DMXMHPanel *p = (DMXMHPanel*)panel;
    if (p == nullptr) {
        return;
    }
    if (cls == nullptr) {
        return;
    }

    Model* m = cls;
    if (cls->GetDisplayAs() == "ModelGroup") {
        m = dynamic_cast<ModelGroup*>(cls)->GetFirstModel();
        if (m == nullptr) m = cls;
    }

    int const num_channels = m->GetNumChannels();

    for (int i = 1; i <= DMXMH_CHANNELS; ++i) {
        wxString const label_ctrl = wxString::Format("ID_STATICTEXT_DMXMH%d", i);
        std::string name;
        if (i == 1) {
            name = "Pan (16 bit)";
        } else if (i == 2) {
            name = "Tilt (16 bit)";
        } else {
            name = m->GetNodeName(i - 1);
            if (name.empty()) {
                name = wxString::Format("Channel %d", i).ToStdString();
            }
        }
        wxStaticText* label = (wxStaticText*)(p->FindWindowByName(label_ctrl));
        if( label != nullptr ) {
            label->SetLabel(wxString::Format("%s:", name));
        }
        wxString const slider_ctrl = wxString::Format("ID_SLIDER_DMXMH%d", i);
        wxSlider* slider = (wxSlider*)(p->FindWindowByName(slider_ctrl));
        wxString const vc_ctrl = wxString::Format("ID_VALUECURVE_DMXMH%d", i);
        wxBitmapButton* curve = (wxBitmapButton*)(p->FindWindowByName(vc_ctrl));
        wxString const text_ctrl = wxString::Format("IDD_TEXTCTRL_DMXMH%d", i);
        wxTextCtrl* text = (wxTextCtrl*)(p->FindWindowByName(text_ctrl));
        wxString const inv_ctrl = wxString::Format("ID_CHECKBOX_INVDMXMH%d", i);
        wxCheckBox* inv = (wxCheckBox*)(p->FindWindowByName(inv_ctrl));
        if (i > num_channels) {
            if( label != nullptr ) label->Enable(false);
            if( slider != nullptr ) slider->Enable(false);
            if( curve != nullptr ) curve->Enable(false);
            if( text != nullptr ) text->Enable(false);
            if (inv != nullptr)
                inv->Enable(false);
        } else {
            if( label != nullptr ) label->Enable(true);
            if( slider != nullptr ) slider->Enable(true);
            if( curve != nullptr ) curve->Enable(true);
            if (text != nullptr)
                text->Enable(true);
            if (inv != nullptr)
                inv->Enable(true);
        }
    }
    p->FlexGridSizer_Panel1->Layout();
    p->FlexGridSizer_Main->Layout();
    p->Refresh();
}
