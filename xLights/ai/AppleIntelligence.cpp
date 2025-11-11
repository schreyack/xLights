#include "AppleIntelligence.h"
#include "ServiceManager.h"
#include "utils/Curl.h"
#include "UtilFunctions.h"
#include <nlohmann/json.hpp>

#include <wx/propgrid/propgrid.h>

#include <vector>
#include <string>

#include <log4cpp/Category.hh>

#include "xLights-Swift.h"


bool AppleIntelligence::IsAvailable() const {
    return _enabled;
}

void AppleIntelligence::SaveSettings() const {
    _sm->setServiceSetting("appleAIEnable", _enabled);
}

void AppleIntelligence::LoadSettings() {
    _enabled = _sm->getServiceSetting("appleAIEnable", _enabled);
}

void AppleIntelligence::PopulateLLMSettings(wxPropertyGrid* page) {
    page->Append(new wxPropertyCategory("Apple Intelligence"));
    auto p = page->Append(new wxBoolProperty("Enabled", "AppleIntelligence.Enabled", _enabled));
    p->SetEditor("CheckBox");
}

void AppleIntelligence::SetSetting(const std::string& key, const wxVariant& value) {
	if (key == "AppleIntelligence.Enabled") {
		_enabled = value.GetBool();
	}
}

std::pair<std::string, bool> AppleIntelligence::CallLLM(const std::string& prompt) const {
    // Apple Intelligence is disabled for this build
    std::string s = "";
    
    return {s, !s.empty()};
}

aiBase::AIColorPalette AppleIntelligence::GenerateColorPalette(const std::string &prompt) const {
    aiBase::AIColorPalette ret;
    
    // Apple Intelligence is disabled for this build
    ret.error = "Apple Intelligence is not available";
    
    return ret;
}
