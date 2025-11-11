#pragma once

/***************************************************************
 * This source files comes from the xLights project
 * https://www.xlights.org
 * https://github.com/xLightsSequencer/xLights
 * See the github commit history for a record of contributing
 * developers.
 * Copyright claimed based on commit dates recorded in Github
 * License: https://github.com/xLightsSequencer/xLights/blob/master/License.txt
 **************************************************************/

#include "RenderableEffect.h"
#include "../UtilFunctions.h"

#define DMXMH_MIN 0
#define DMXMH_MAX 255

constexpr int DMXMH_CHANNELS = 48;

class DMXMHEffect : public RenderableEffect
{
public:
    DMXMHEffect(int id);
    virtual ~DMXMHEffect();
    virtual bool CanBeRandom() override
    {
        return false;
    }
    virtual void Render(Effect* effect, const SettingsMap& settings, RenderBuffer& buffer) override;
    virtual void SetPanelStatus(Model* cls) override;
    virtual void SetDefaultParameters() override;
    virtual bool CanRenderPartialTimeInterval() const override
    {
        return true;
    }
    void RemapSelectedDMXMHEffectValues(Effect* effect, const std::vector<std::tuple<int, int, float, int, wxString>>& dmxmhmappings) const;

    virtual double GetSettingVCMin(const std::string& name) const override
    {
        if (StartsWith(name, "E_VALUECURVE_DMXMH"))
            return DMXMH_MIN;
        return RenderableEffect::GetSettingVCMin(name);
    }
    virtual double GetSettingVCMax(const std::string& name) const override
    {
        if (StartsWith(name, "E_VALUECURVE_DMXMH"))
            return DMXMH_MAX;
        return RenderableEffect::GetSettingVCMax(name);
    }

protected:
    virtual xlEffectPanel* CreatePanel(wxWindow* parent) override;
    virtual bool needToAdjustSettings(const std::string& version) override
    {
        return true;
    };
    virtual void adjustSettings(const std::string& version, Effect* effect, bool removeDefaults = true) override;

private:
    bool SetDMXMHSinglColorPixel(int chan, int num_channels, const SettingsMap& SettingsMap, double eff_pos, xlColor& color, RenderBuffer& buffer);
    bool SetDMXMHRGBNode(int node, int num_channels, const SettingsMap& SettingsMap, double eff_pos, xlColor& color, RenderBuffer& buffer, const std::string& string_type);
    void SetColorBasedOnStringType(int value, int slot, xlColor& color, const std::string& string_type);
};

