/***************************************************************
 * This source files comes from the xLights project
 * https://www.xlights.org
 * https://github.com/xLightsSequencer/xLights
 * See the github commit history for a record of contributing
 * developers.
 * Copyright claimed based on commit dates recorded in Github
 * License: https://github.com/xLightsSequencer/xLights/blob/master/License.txt
 **************************************************************/

 //(*InternalHeaders(DMXMHPanel)
 #include <wx/bitmap.h>
 #include <wx/bmpbuttn.h>
 #include <wx/button.h>
 #include <wx/checkbox.h>
 #include <wx/image.h>
 #include <wx/intl.h>
 #include <wx/notebook.h>
 #include <wx/sizer.h>
 #include <wx/slider.h>
 #include <wx/stattext.h>
 #include <wx/string.h>
 #include <wx/textctrl.h>
 //*)

#include <wx/textentry.h>

#include "DMXMHPanel.h"
#include "DMXMHEffect.h"
#include "DMXEffect.h"
#include "../xLightsMain.h"
#include "../sequencer/MainSequencer.h"
#include "../sequencer/Effect.h"
#include "../sequencer/Element.h"
#include "../models/ModelGroup.h"
#include "RemapDMXChannelsDialog.h"
#include "xLightsApp.h"
#include "EffectPanelUtils.h"
#include "../UtilFunctions.h"

//(*IdInit(DMXMHPanel)
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH1 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH1 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH1 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH1 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH1 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH2 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH2 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH2 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH2 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH2 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH3 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH3 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH3 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH3 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH3 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH4 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH4 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH4 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH4 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH4 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH5 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH5 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH5 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH5 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH5 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH6 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH6 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH6 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH6 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH6 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH7 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH7 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH7 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH7 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH7 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH8 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH8 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH8 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH8 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH8 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH9 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH9 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH9 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH9 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH9 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH10 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH10 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH10 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH10 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH10 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH11 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH11 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH11 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH11 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH11 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH12 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH12 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH12 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH12 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH12 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH13 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH13 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH13 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH13 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH13 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH14 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH14 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH14 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH14 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH14 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH15 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH15 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH15 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH15 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH15 = wxNewId();
const wxWindowID DMXMHPanel::ID_STATICTEXT_DMXMH16 = wxNewId();
const wxWindowID DMXMHPanel::ID_SLIDER_DMXMH16 = wxNewId();
const wxWindowID DMXMHPanel::ID_VALUECURVE_DMXMH16 = wxNewId();
const wxWindowID DMXMHPanel::IDD_TEXTCTRL_DMXMH16 = wxNewId();
const wxWindowID DMXMHPanel::ID_CHECKBOX_INVDMXMH16 = wxNewId();
const wxWindowID DMXMHPanel::ID_PANEL6 = wxNewId();
const wxWindowID DMXMHPanel::ID_PANEL3 = wxNewId();
const wxWindowID DMXMHPanel::ID_NOTEBOOK1 = wxNewId();
const wxWindowID DMXMHPanel::ID_BUTTON1 = wxNewId();
const wxWindowID DMXMHPanel::ID_BUTTON2 = wxNewId();
const wxWindowID DMXMHPanel::ID_BUTTON_LOAD_STATE = wxNewId();
//*)

BEGIN_EVENT_TABLE(DMXMHPanel,wxPanel)
	//(*EventTable(DMXMHPanel)
	//*)
END_EVENT_TABLE()

DMXMHPanel::DMXMHPanel(wxWindow* parent) : xlEffectPanel(parent)
{
	//(*Initialize(DMXMHPanel)
	BulkEditTextCtrl* TextCtrl1_DMX1;
	BulkEditTextCtrl* TextCtrl1_DMX2;
	BulkEditTextCtrl* TextCtrl1_DMX3;
	BulkEditTextCtrl* TextCtrl1_DMX5;
	BulkEditTextCtrl* TextCtrl1_DMX6;
	BulkEditTextCtrl* TextCtrl1_DMX7;
	BulkEditTextCtrl* TextCtrl1_DMX8;
	BulkEditTextCtrl* TextCtrl_DMX10;
	BulkEditTextCtrl* TextCtrl_DMX11;
	BulkEditTextCtrl* TextCtrl_DMX12;
	BulkEditTextCtrl* TextCtrl_DMX13;
	BulkEditTextCtrl* TextCtrl_DMX14;
	BulkEditTextCtrl* TextCtrl_DMX15;
	BulkEditTextCtrl* TextCtrl_DMX16;
	BulkEditTextCtrl* TextCtrl_DMX17;
	BulkEditTextCtrl* TextCtrl_DMX18;
	BulkEditTextCtrl* TextCtrl_DMX19;
	BulkEditTextCtrl* TextCtrl_DMX20;
	BulkEditTextCtrl* TextCtrl_DMX21;
	BulkEditTextCtrl* TextCtrl_DMX22;
	BulkEditTextCtrl* TextCtrl_DMX23;
	BulkEditTextCtrl* TextCtrl_DMX24;
	BulkEditTextCtrl* TextCtrl_DMX25;
	BulkEditTextCtrl* TextCtrl_DMX26;
	BulkEditTextCtrl* TextCtrl_DMX27;
	BulkEditTextCtrl* TextCtrl_DMX28;
	BulkEditTextCtrl* TextCtrl_DMX29;
	BulkEditTextCtrl* TextCtrl_DMX30;
	BulkEditTextCtrl* TextCtrl_DMX31;
	BulkEditTextCtrl* TextCtrl_DMX32;
	BulkEditTextCtrl* TextCtrl_DMX33;
	BulkEditTextCtrl* TextCtrl_DMX34;
	BulkEditTextCtrl* TextCtrl_DMX35;
	BulkEditTextCtrl* TextCtrl_DMX36;
	BulkEditTextCtrl* TextCtrl_DMX37;
	BulkEditTextCtrl* TextCtrl_DMX38;
	BulkEditTextCtrl* TextCtrl_DMX39;
	BulkEditTextCtrl* TextCtrl_DMX40;
	BulkEditTextCtrl* TextCtrl_DMX41;
	BulkEditTextCtrl* TextCtrl_DMX42;
	BulkEditTextCtrl* TextCtrl_DMX43;
	BulkEditTextCtrl* TextCtrl_DMX44;
	BulkEditTextCtrl* TextCtrl_DMX45;
	BulkEditTextCtrl* TextCtrl_DMX46;
	BulkEditTextCtrl* TextCtrl_DMX47;
	BulkEditTextCtrl* TextCtrl_DMX48;
	BulkEditTextCtrl* TextCtrl_DMX4;
	BulkEditTextCtrl* TextCtrl_DMX9;
	wxFlexGridSizer* FlexGridSizer3;

	Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
	FlexGridSizer_Main = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer_Main->AddGrowableCol(0);
	Notebook7 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
	ChannelPanelMH1 = new wxPanel(Notebook7, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
	FlexGridSizer_Panel1 = new wxFlexGridSizer(0, 5, 0, 0);
	FlexGridSizer_Panel1->AddGrowableCol(1);
	Label_DMXMH1 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH1, _("Pan (16 bit):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH1"));
	FlexGridSizer_Panel1->Add(Label_DMXMH1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH1 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH1, 0, 0, 3600, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH1"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH1, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH1 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH1, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH1"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl1_DMX1 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH1, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH1"));
	FlexGridSizer_Panel1->Add(TextCtrl1_DMX1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH1 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH1, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH1"));
	CheckBox_INVDMXMH1->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH1, 1, wxALL|wxEXPAND, 2);
	Label_DMXMH2 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH2, _("Tilt (16 bit):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH2"));
	FlexGridSizer_Panel1->Add(Label_DMXMH2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH2 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH2, 0, 0, 3600, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH2"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH2, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH2 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH2, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH2"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl1_DMX2 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH2, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH2"));
	FlexGridSizer_Panel1->Add(TextCtrl1_DMX2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH2 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH2, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH2"));
	CheckBox_INVDMXMH2->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH3 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH3, _("Channel 3:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH3"));
	FlexGridSizer_Panel1->Add(Label_DMXMH3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH3 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH3, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH3"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH3, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH3 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH3, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH3"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl1_DMX3 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH3, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH3"));
	FlexGridSizer_Panel1->Add(TextCtrl1_DMX3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH3 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH3, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH3"));
	CheckBox_INVDMXMH3->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH4 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH4, _("Channel 4:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH4"));
	FlexGridSizer_Panel1->Add(Label_DMXMH4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH4 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH4, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH4"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH4, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH4 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH4, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH4"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX4 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH4, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH4"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH4 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH4, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH4"));
	CheckBox_INVDMXMH4->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH5 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH5, _("Channel 5:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH5"));
	FlexGridSizer_Panel1->Add(Label_DMXMH5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH5 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH5, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH5"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH5, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH5 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH5, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH5"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl1_DMX5 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH5, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH5"));
	FlexGridSizer_Panel1->Add(TextCtrl1_DMX5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH5 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH5, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH5"));
	CheckBox_INVDMXMH5->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH6 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH6, _("Channel 6:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH6"));
	FlexGridSizer_Panel1->Add(Label_DMXMH6, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH6 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH6, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH6"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH6, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH6 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH6, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH6"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl1_DMX6 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH6, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH6"));
	FlexGridSizer_Panel1->Add(TextCtrl1_DMX6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH6 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH6, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH6"));
	CheckBox_INVDMXMH6->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH7 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH7, _("Channel 7:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH7"));
	FlexGridSizer_Panel1->Add(Label_DMXMH7, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH7 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH7, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH7"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH7, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH7 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH7, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH7"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl1_DMX7 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH7, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH7"));
	FlexGridSizer_Panel1->Add(TextCtrl1_DMX7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH7 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH7, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH7"));
	CheckBox_INVDMXMH7->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH8 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH8, _("Channel 8:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH8"));
	FlexGridSizer_Panel1->Add(Label_DMXMH8, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH8 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH8, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH8"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH8, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH8 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH8, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH8"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl1_DMX8 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH8, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH8"));
	FlexGridSizer_Panel1->Add(TextCtrl1_DMX8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH8 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH8, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH8"));
	CheckBox_INVDMXMH8->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH9 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH9, _("Channel 9:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH9"));
	FlexGridSizer_Panel1->Add(Label_DMXMH9, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH9 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH9, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH9"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH9, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH9 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH9, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH9"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX9 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH9, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH9"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH9 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH9, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH9"));
	CheckBox_INVDMXMH9->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH10 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH10, _("Channel 10:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH10"));
	FlexGridSizer_Panel1->Add(Label_DMXMH10, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH10 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH10, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH10"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH10, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH10 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH10, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH10"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX10 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH10, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH10"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH10 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH10, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH10"));
	CheckBox_INVDMXMH10->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH11 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH11, _("Channel 11:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH11"));
	FlexGridSizer_Panel1->Add(Label_DMXMH11, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH11 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH11, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH11"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH11, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH11 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH11, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH11"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX11 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH11, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH11"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX11, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH11 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH11, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH11"));
	CheckBox_INVDMXMH11->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH12 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH12, _("Channel 12:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH12"));
	FlexGridSizer_Panel1->Add(Label_DMXMH12, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH12 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH12, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH12"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH12, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH12 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH12, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH12"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX12 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH12, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH12"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX12, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH12 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH12, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH12"));
	CheckBox_INVDMXMH12->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH13 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH13, _("Channel 13:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH13"));
	FlexGridSizer_Panel1->Add(Label_DMXMH13, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH13 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH13, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH13"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH13, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH13 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH13, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH13"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX13 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH13, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH13"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX13, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH13 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH13, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH13"));
	CheckBox_INVDMXMH13->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH14 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH14, _("Channel 14:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH14"));
	FlexGridSizer_Panel1->Add(Label_DMXMH14, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH14 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH14, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH14"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH14, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH14 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH14, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH14"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX14 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH14, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH14"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX14, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH14 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH14, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH14"));
	CheckBox_INVDMXMH14->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH15 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH15, _("Channel 15:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH15"));
	FlexGridSizer_Panel1->Add(Label_DMXMH15, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH15 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH15, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH15"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH15, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH15 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH15, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH15"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX15 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH15, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH15"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH15 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH15, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH15"));
	CheckBox_INVDMXMH15->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	Label_DMXMH16 = new wxStaticText(ChannelPanelMH1, ID_STATICTEXT_DMXMH16, _("Channel 16:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT_DMXMH16"));
	FlexGridSizer_Panel1->Add(Label_DMXMH16, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	Slider_DMXMH16 = new BulkEditSlider(ChannelPanelMH1, ID_SLIDER_DMXMH16, 0, 0, 255, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER_DMXMH16"));
	FlexGridSizer_Panel1->Add(Slider_DMXMH16, 1, wxALL|wxEXPAND, 2);
	ValueCurve_DMXMH16 = new BulkEditValueCurveButton(ChannelPanelMH1, ID_VALUECURVE_DMXMH16, GetValueCurveNotSelectedBitmap(), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_VALUECURVE_DMXMH16"));
	FlexGridSizer_Panel1->Add(ValueCurve_DMXMH16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	TextCtrl_DMX16 = new BulkEditTextCtrl(ChannelPanelMH1, IDD_TEXTCTRL_DMXMH16, _T("0"), wxDefaultPosition, wxDLG_UNIT(ChannelPanelMH1,wxSize(20,-1)), wxTE_PROCESS_ENTER, wxDefaultValidator, _T("IDD_TEXTCTRL_DMXMH16"));
	FlexGridSizer_Panel1->Add(TextCtrl_DMX16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CheckBox_INVDMXMH16 = new BulkEditCheckBox(ChannelPanelMH1, ID_CHECKBOX_INVDMXMH16, _("Inv"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX_INVDMXMH16"));
	CheckBox_INVDMXMH16->SetValue(false);
	FlexGridSizer_Panel1->Add(CheckBox_INVDMXMH16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
	ChannelPanelMH1->SetSizer(FlexGridSizer_Panel1);
	Notebook7->AddPage(ChannelPanelMH1, _("Channels 1-16"), false);
	
	FlexGridSizer_Main->Add(Notebook7, 1, wxALL|wxEXPAND, 2);
	FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
	ButtonRemap = new wxButton(this, ID_BUTTON1, _("Remap Channels"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(ButtonRemap, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_SaveAsState = new wxButton(this, ID_BUTTON2, _("Save As State"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(Button_SaveAsState, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button_Load_State = new wxButton(this, ID_BUTTON_LOAD_STATE, _("Load From State"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_LOAD_STATE"));
	FlexGridSizer3->Add(Button_Load_State, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer_Main->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Show(false);
	SetSizer(FlexGridSizer_Main);

	Connect(ID_VALUECURVE_DMXMH1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH3, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH4, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH5, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH6, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH7, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH8, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH9, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH10, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH11, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH12, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH13, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH14, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH15, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_VALUECURVE_DMXMH16, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnVCButtonClick);
	Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnButtonRemapClick);
	Connect(ID_BUTTON2, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnButton_SaveAsStateClick);
	Connect(ID_BUTTON_LOAD_STATE, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&DMXMHPanel::OnButton_Load_StateClick);
	//*)
    SetName("ID_PANEL_DMX");

    Connect(wxID_ANY, EVT_VC_CHANGED, (wxObjectEventFunction)&DMXMHPanel::OnVCChanged, 0, this);
	Connect(wxID_ANY, EVT_VALIDATEWINDOW, (wxObjectEventFunction)&DMXMHPanel::OnValidateWindow, 0, this);
	Connect(ID_BUTTON1, wxEVT_CONTEXT_MENU, (wxObjectEventFunction)&DMXMHPanel::OnButtonRemapRClick);

    // DMXMH1 is Pan (16-bit, 0-3600 degrees)
    ValueCurve_DMXMH1->GetValue()->SetLimits(0, 3600);
    // DMXMH2 is Tilt (16-bit, 0-3600 degrees)
    ValueCurve_DMXMH2->GetValue()->SetLimits(0, 3600);
    ValueCurve_DMXMH3->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH4->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH5->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH6->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH7->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH8->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH9->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH10->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH11->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH12->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH13->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH14->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH15->GetValue()->SetLimits(DMX_MIN, DMX_MAX);
    ValueCurve_DMXMH16->GetValue()->SetLimits(DMX_MIN, DMX_MAX);

	ValidateWindow();
}

DMXMHPanel::~DMXMHPanel()
{
	//(*Destroy(DMXMHPanel)
	//*)
}

void DMXMHPanel::OnButtonRemapClick(wxCommandEvent& event)
{
    RemapDMXChannelsDialog dlg(this);
    if (dlg.ShowModal() == wxID_OK)
    {
        std::vector<int> sliders(DMXMH_CHANNELS);
        std::vector<std::string> curves(DMXMH_CHANNELS);
        std::vector<bool> checks(DMXMH_CHANNELS);

        // save the current values
        for (int i = 0; i < DMXMH_CHANNELS; i++)
        {
            wxString slider_ctrl = wxString::Format("ID_SLIDER_DMXMH%d", i+1);
            wxSlider* slider = (wxSlider*)(this->FindWindowByName(slider_ctrl));
            wxASSERT(slider != nullptr);
            wxString vc_ctrl = wxString::Format("ID_VALUECURVE_DMXMH%d", i+1);
            ValueCurveButton* curve = (ValueCurveButton*)(this->FindWindowByName(vc_ctrl));
            wxASSERT(curve != nullptr);
            wxString ckbx_ctrl = wxString::Format("ID_CHECKBOX_INVDMXMH%d", i + 1);
            wxCheckBox* check_box = (wxCheckBox*)(this->FindWindowByName(ckbx_ctrl));
            wxASSERT(check_box != nullptr);
            sliders[i] = slider->GetValue();
            curves[i] = curve->GetValue()->Serialise();
            checks[i] = check_box->GetValue();
        }

        for (int i = 0; i < DMXMH_CHANNELS; i++)
        {
            if (dlg.DoMapping(i))
            {
                int from = i;
                int to = dlg.GetToChannel(i);
                wxString slider_ctrl = wxString::Format("ID_SLIDER_DMXMH%d", to);
                wxSlider* slider = (wxSlider*)(this->FindWindowByName(slider_ctrl));
                wxASSERT(slider != nullptr);
                wxString vc_ctrl = wxString::Format("ID_VALUECURVE_DMXMH%d", to);
                ValueCurveButton* curve = (ValueCurveButton*)(this->FindWindowByName(vc_ctrl));
                wxASSERT(curve != nullptr);
                wxString text_ctrl = wxString::Format("IDD_TEXTCTRL_DMXMH%d", to);
                wxTextCtrl* text = (wxTextCtrl*)(this->FindWindowByName(text_ctrl));
                wxASSERT(text != nullptr);

                wxString check_ctrl = wxString::Format("ID_CHECKBOX_INVDMXMH%d", to);
                wxCheckBox* check_box = (wxCheckBox*)(this->FindWindowByName(check_ctrl));
                wxASSERT(check_box != nullptr);

                double scale {dlg.GetChanScale(i)};
                int offset {dlg.GetChanOffset(i)};
                int new_value = ((double)sliders[from] * scale) + offset;

                auto const& inv = dlg.GetChanInvert(i);
                if (inv == "Check") {
                    checks[from] = true;
                } else if (inv == "Uncheck") {
                    checks[from] = false;
                }

                text->SetValue(wxString::Format("%d", new_value));
                slider->SetValue(new_value);
                check_box->SetValue(checks[from]);
                curve->GetValue()->Deserialise(curves[from]);
                curve->GetValue()->ScaleAndOffsetValues(scale, offset);
                wxCommandEvent vcevent;
                vcevent.SetEventObject(curve);
                OnVCChanged(vcevent);
                curve->UpdateState();
            }
        }
    }
    FireChangeEvent();
}

void DMXMHPanel::OnButtonRemapRClick(wxCommandEvent& event)
{
    if (xLightsApp::GetFrame()->GetMainSequencer() == nullptr) {
        return;
    }

    // i should only display the menu if at least one effect is selected
    int alleffects = xLightsApp::GetFrame()->GetMainSequencer()->GetSelectedEffectCount("");
    if (alleffects < 1)
    {
        return;
    }

    wxMenu mnu;
    mnu.Append(wxID_ANY, "Bulk Edit");
    mnu.Connect(wxEVT_MENU, (wxObjectEventFunction)&DMXMHPanel::OnChoicePopup, nullptr, this);
    PopupMenu(&mnu);
}

void DMXMHPanel::OnChoicePopup(wxCommandEvent& event)
{
    RemapDMXChannelsDialog dlg(this);
    if (dlg.ShowModal() == wxID_OK)
    {
        std::vector<std::tuple<int, int, float, int, wxString>> dmxmappings;

        for (int i = 0; i < DMXMH_CHANNELS; i++)
        {
            if (dlg.DoMapping(i))
            {
                dmxmappings.push_back(std::make_tuple(i + 1, dlg.GetToChannel(i), dlg.GetChanScale(i), dlg.GetChanOffset(i), dlg.GetChanInvert(i)));
            }
        }

        if (dmxmappings.size() > 0)
        {
            xLightsApp::GetFrame()->GetMainSequencer()->RemapSelectedDMXEffectValues(dmxmappings);
            // unselect and select effect to update the panel
            auto effect = xLightsApp::GetFrame()->GetMainSequencer()->GetSelectedEffect();
            if (effect != nullptr)
            {
                xLightsApp::GetFrame()->GetMainSequencer()->PanelEffectGrid->RaiseSelectedEffectChanged(effect, true, true);
            }
        }
    }
}

void DMXMHPanel::ValidateWindow()
{
    bool vc = false;

	auto models = GetActiveModels();
	if (models.size() == 0) {
		vc = true;
	}

	for (int i = 0; i < DMXMH_CHANNELS && !vc; i++)
    {
        wxString vc_ctrl = wxString::Format("ID_VALUECURVE_DMXMH%d", i+1);
        ValueCurveButton* curve = (ValueCurveButton*)(this->FindWindowByName(vc_ctrl));
        wxASSERT(curve != nullptr);
        if (curve->GetValue()->IsActive())
        {
            vc = true;
        }
    }

    if (vc)
    {
        Button_SaveAsState->Enable(false);
    }
    else
    {
        Button_SaveAsState->Enable();
    }
}

std::list<Model*> DMXMHPanel::GetActiveModels()
{
	std::list<Model*> res;

	if (xLightsApp::GetFrame()->GetMainSequencer() == nullptr) {
        return res;
    }

	auto effect = xLightsApp::GetFrame()->GetMainSequencer()->GetSelectedEffect();
	if (effect != nullptr) {
		if (effect->GetParentEffectLayer() != nullptr) {
			Element* element = effect->GetParentEffectLayer()->GetParentElement();
			if (element != nullptr) {
				ModelElement* me = dynamic_cast<ModelElement*>(element);
				if (me != nullptr) {
					auto model = xLightsApp::GetFrame()->AllModels[me->GetModelName()];
					if (model != nullptr) {
						if (model->GetDisplayAs() == "ModelGroup") {
							auto mg = dynamic_cast<ModelGroup*>(model);
							if (mg != nullptr) {
								for (const auto& it : mg->GetFlatModels(true, false)) {
									if (it->GetDisplayAs() != "ModelGroup" && it->GetDisplayAs() != "SubModel") {
										res.push_back(it);
									}
								}
							}
						}
						else if (model->GetDisplayAs() == "SubModel") {
							// don't add SubModels
						}
						else {
							res.push_back(model);
						}
					}
				}
			}
		}
	}

	return res;
}

void DMXMHPanel::OnButton_SaveAsStateClick(wxCommandEvent& event)
{
	uint32_t maxChannels = 0;

	auto models = GetActiveModels();
	std::string stateName;
	while (stateName == "") {
		wxTextEntryDialog dlg(this, "Enter name for the state", "State Name");
		if (dlg.ShowModal() == wxID_OK) {
			stateName = dlg.GetValue();
			stateName = ::Lower(stateName);
			stateName = StripAllBut(stateName, "abcdefghijklmnopqrstuvwxyz0123456789-_/\\|#");
			for (const auto& it : models) {
				if (it->GetChanCount() > maxChannels) maxChannels = it->GetChanCount();
				if (it->HasState(stateName)) {
                    if (wxMessageBox("A State With Same Name Already Exists\nOverride it?", "Override State", wxYES_NO | wxICON_QUESTION, this) == wxNO) {
                        stateName = "";
                    }
					break;
				}
			}
		}
		else {
			return;
		}
	}

	// <stateInfo Name="ST" CustomColors="1" Type="SingleNode" s1="Node 2" s1-Color="#979797" s1-Name="st1" s10="" s10-Color="" s10-Name="" s11="" s11-Color="" s11-Name="" s12="" s12-Color="" s12-Name="" s13="" s13-Color="" s13-Name="" s14="" s14-Color="" s14-Name="" s15="" s15-Color="" s15-Name="" s16="" s16-Color="" s16-Name="" s17="" s17-Color="" s17-Name="" s18="" s18-Color="" s18-Name="" s19="" s19-Color="" s19-Name="" s2="Node 4" s2-Color="#c0c0c0" s2-Name="st1" s20="" s20-Color="" s20-Name="" s21="" s21-Color="" s21-Name="" s22="" s22-Color="" s22-Name="" s23="" s23-Color="" s23-Name="" s24="" s24-Color="" s24-Name="" s25="" s25-Color="" s25-Name="" s26="" s26-Color="" s26-Name="" s27="" s27-Color="" s27-Name="" s28="" s28-Color="" s28-Name="" s29="" s29-Color="" s29-Name="" s3="Node 5" s3-Color="" s3-Name="st2" s30="" s30-Color="" s30-Name="" s31="" s31-Color="" s31-Name="" s32="" s32-Color="" s32-Name="" s33="" s33-Color="" s33-Name="" s34="" s34-Color="" s34-Name="" s35="" s35-Color="" s35-Name="" s36="" s36-Color="" s36-Name="" s37="" s37-Color="" s37-Name="" s38="" s38-Color="" s38-Name="" s39="" s39-Color="" s39-Name="" s4="" s4-Color="" s4-Name="" s40="" s40-Color="" s40-Name="" s5="" s5-Color="" s5-Name="" s6="" s6-Color="" s6-Name="" s7="" s7-Color="" s7-Name="" s8="" s8-Color="" s8-Name="" s9="" s9-Color="" s9-Name=""/>
	wxXmlNode* n = new wxXmlNode(wxXmlNodeType::wxXML_ELEMENT_NODE, "stateInfo");
	n->AddAttribute("CustomColors", "1");
	n->AddAttribute("Name", stateName);
	n->AddAttribute("Type", "SingleNode");
	for (uint32_t i = 0; i < DMXMH_CHANNELS; i++) {
		if (i < maxChannels) {
			auto attr = wxString::Format("s%d-Name", i + 1);
			n->AddAttribute(attr, stateName);
			attr = wxString::Format("s%d", i + 1);

			wxString label_ctrl = wxString::Format("ID_STATICTEXT_DMXMH%d", i + 1);
			wxStaticText* label = (wxStaticText*)(this->FindWindowByName(label_ctrl));
			wxASSERT(label != nullptr);

			auto l = label->GetLabelText();
			l = l.substr(0, l.size() - 1); // remove the :

			if (StartsWith(l, "Channel")) {
				l = wxString::Format("Node %d", i + 1);
			}
			n->AddAttribute(attr, l);

			attr = wxString::Format("s%d-Color", i + 1);

			wxString slider_ctrl = wxString::Format("ID_SLIDER_DMXMH%d", i+1);
			wxSlider* slider = (wxSlider*)(this->FindWindowByName(slider_ctrl));
			wxASSERT(slider != nullptr);

			auto val = wxString::Format("#%02x%02x%02x", slider->GetValue(), slider->GetValue(), slider->GetValue());
			n->AddAttribute(attr, val);
		}
		else {
			auto attr = wxString::Format("s%d-Name", i + 1);
			n->AddAttribute(attr, "");
			attr = wxString::Format("s%d", i + 1);
			n->AddAttribute(attr, "");
			attr = wxString::Format("s%d-Color", i + 1);
			n->AddAttribute(attr, "");
		}
	}

	for (auto& it : models) {
		it->AddState(n);
		// rgb effects is changed so we need to save
	}
	wxPostEvent(xLightsApp::GetFrame(), wxCommandEvent(EVT_RGBEFFECTS_CHANGED));
}

void DMXMHPanel::OnButton_Load_StateClick(wxCommandEvent& event)
{
    uint32_t maxChannels{ DMXMH_CHANNELS };

    auto models = GetActiveModels();
    if (models.size() < 1) {
        return;
    }

    auto m = models.front();
    if (nullptr == m) {
        return;
    }
    maxChannels = std::min(maxChannels, m->GetChanCount());
    wxArrayString choices;
    std::transform(m->GetStateInfo().begin(), m->GetStateInfo().end(), std::back_inserter(choices),
                   [](auto const& key) { return key.first; });
    wxSingleChoiceDialog dlg(this, "Select State", "Select State", choices);

    if (dlg.ShowModal() != wxID_OK) {
        return;
    }
    std::string stateName = dlg.GetStringSelection();
    auto states = m->GetStateInfo().at(stateName);

    if (states["CustomColors"] != "1" || states["Type"] != "SingleNode") {
        DisplayError("State does not have Force Custom Colors or Single Node Type");
        return;
    }

    for (size_t i = 0; i < maxChannels; ++i) {
        auto attr = wxString::Format("s%d-Name", (int)i + 1);
        if (states.count(attr) != 0) {
            auto colattr = wxString::Format("s%d-Color", (int)i + 1);
            xlColor dmxValue(states[colattr]);
            wxString slider_ctrl = wxString::Format("ID_SLIDER_DMXMH%d", (int)i + 1);
            wxSlider* slider = (wxSlider*)(this->FindWindowByName(slider_ctrl));
            wxASSERT(slider != nullptr);
            slider->SetValue(dmxValue.red);

            wxString text_ctrl = wxString::Format("IDD_TEXTCTRL_DMXMH%d", (int)i + 1);
            wxTextCtrl* text = (wxTextCtrl*)(this->FindWindowByName(text_ctrl));
            wxASSERT(text != nullptr);
            text->SetValue(wxString::Format("%d", dmxValue.red));
        }
    }
    FireChangeEvent();
}

void DMXMHPanel::OnNotebook7PageChanged(wxNotebookEvent& event)
{
}
