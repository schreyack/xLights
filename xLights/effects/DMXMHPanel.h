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

 //(*Headers(DMXMHPanel)
 #include <wx/panel.h>
 class wxBitmapButton;
 class wxButton;
 class wxCheckBox;
 class wxFlexGridSizer;
 class wxNotebook;
 class wxNotebookEvent;
 class wxSlider;
 class wxStaticText;
 class wxTextCtrl;
 //*)

#include "../BulkEditControls.h"
#include "EffectPanelUtils.h"

class Model;

class DMXMHPanel: public xlEffectPanel
{
	std::list<Model*> GetActiveModels();

	public:

		DMXMHPanel(wxWindow* parent);
		virtual ~DMXMHPanel();
		virtual void ValidateWindow() override;

		//(*Declarations(DMXMHPanel)
		BulkEditCheckBox* CheckBox_INVDMXMH1;
		BulkEditCheckBox* CheckBox_INVDMXMH2;
		BulkEditSlider* Slider_DMXMH1;
		BulkEditSlider* Slider_DMXMH2;
		BulkEditValueCurveButton* ValueCurve_DMXMH1;
		BulkEditValueCurveButton* ValueCurve_DMXMH2;
		wxButton* ButtonRemap;
		wxButton* Button_Load_State;
		wxButton* Button_SaveAsState;
		wxFlexGridSizer* FlexGridSizer_Main;
		wxFlexGridSizer* FlexGridSizer_Panel1;
		wxNotebook* Notebook7;
		wxPanel* ChannelPanelMH1;
		wxStaticText* Label_DMXMH1;
		wxStaticText* Label_DMXMH2;
		//*)

	protected:

		//(*Identifiers(DMXMHPanel)
		static const wxWindowID ID_STATICTEXT_DMXMH1;
		static const wxWindowID ID_SLIDER_DMXMH1;
		static const wxWindowID ID_VALUECURVE_DMXMH1;
		static const wxWindowID IDD_TEXTCTRL_DMXMH1;
		static const wxWindowID ID_CHECKBOX_INVDMXMH1;
		static const wxWindowID ID_STATICTEXT_DMXMH2;
		static const wxWindowID ID_SLIDER_DMXMH2;
		static const wxWindowID ID_VALUECURVE_DMXMH2;
		static const wxWindowID IDD_TEXTCTRL_DMXMH2;
		static const wxWindowID ID_CHECKBOX_INVDMXMH2;
		static const wxWindowID ID_PANEL6;
		static const wxWindowID ID_PANEL3;
		static const wxWindowID ID_NOTEBOOK1;
		static const wxWindowID ID_BUTTON1;
		static const wxWindowID ID_BUTTON2;
		static const wxWindowID ID_BUTTON_LOAD_STATE;
		//*)

	public:

		//(*Handlers(DMXMHPanel)
		void OnButtonRemapClick(wxCommandEvent& event);
		void OnButton_SaveAsStateClick(wxCommandEvent& event);
		void OnButton_Load_StateClick(wxCommandEvent& event);
		void OnNotebook7PageChanged(wxNotebookEvent& event);
		//*)

        void OnButtonRemapRClick(wxCommandEvent& event);
        void OnChoicePopup(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};
