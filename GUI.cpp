///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));

	bSizer2->Add(panel, 2, wxEXPAND | wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer1->Add(bSizer2, 2, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer(wxVERTICAL);

	text = new wxStaticText(this, wxID_ANY, wxT("Legenda"), wxDefaultPosition, wxDefaultSize, 0);
	text->Wrap(-1);
	bSizer8->Add(text, 0, wxALL, 5);


	bSizer3->Add(bSizer8, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer(wxHORIZONTAL);

	check = new wxButton(this, wxID_ANY, wxT("Sprawdź"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(check, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	random = new wxButton(this, wxID_ANY, wxT("Losuj"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer9->Add(random, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	bSizer3->Add(bSizer9, 0, wxEXPAND, 5);


	bSizer1->Add(bSizer3, 0, wxALIGN_CENTER_HORIZONTAL | wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	panel->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelOnKeyDown), NULL, this);
	panel->Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_MIDDLE_UP, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_RIGHT_UP, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_MOTION, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::panelOnUpdateUI), NULL, this);
	check->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::checkOnButtonClick), NULL, this);
	random->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::randomOnButtonClick), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	panel->Disconnect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyFrame1::panelOnKeyDown), NULL, this);
	panel->Disconnect(wxEVT_LEFT_DOWN, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_LEFT_UP, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_MIDDLE_DOWN, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_MIDDLE_UP, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_RIGHT_UP, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_MOTION, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_LEFT_DCLICK, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_MIDDLE_DCLICK, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_RIGHT_DCLICK, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_MOUSEWHEEL, wxMouseEventHandler(MyFrame1::panelOnMouseEvents), NULL, this);
	panel->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::panelOnUpdateUI), NULL, this);
	check->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::checkOnButtonClick), NULL, this);
	random->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::randomOnButtonClick), NULL, this);

}