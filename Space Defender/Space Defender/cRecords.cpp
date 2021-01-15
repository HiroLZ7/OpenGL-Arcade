#include "cRecords.h"

cRecords::cRecords(SaveState *save) : wxFrame(nullptr, wxID_ANY, "Space Defender", wxPoint(0, 0), wxSize(800, 800)) {
	saveData = save;
	ColorPallate cP;
	wxFlexGridSizer *gSizerA = new wxFlexGridSizer(2, 2, 30, 30);
	SelectionBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	SelectionBar->SetBackgroundColour(cP.LIGHT_PURPLE);
	this->SetBackgroundColour(cP.RED);
	wxButton *menu = new wxButton(SelectionBar, 101, "Main Menu", wxDefaultPosition, wxDefaultSize, 0);
	menu->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cRecords::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(menu);
	wxButton *settings = new wxButton(SelectionBar, 102, "Settings", wxDefaultPosition, wxDefaultSize, 0);
	settings->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cRecords::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(settings);
	wxButton *about = new wxButton(SelectionBar, 103, "About", wxDefaultPosition, wxDefaultSize, 0);
	about->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cRecords::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(about);
	SelectionBar->Realize();
	std::vector<wxStaticText*> recordsDisplay;
	recordsDisplay.push_back(new wxStaticText(this, wxID_ANY, "Total Score: ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL));
	recordsDisplay.push_back(new wxStaticText(this, wxID_ANY, std::to_string(saveData->ScoreSum), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL));
	recordsDisplay.push_back(new wxStaticText(this, wxID_ANY, "High Score: ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL));
	recordsDisplay.push_back(new wxStaticText(this, wxID_ANY, std::to_string(saveData->highScore), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL));
	for (size_t i = 0; i < recordsDisplay.size(); i++) {
		wxStaticText* temp = recordsDisplay.at(i);
		temp->SetForegroundColour(cP.WHITE);
		wxFont tFont = temp->GetFont();
		tFont.SetPointSize(24);
		temp->SetFont(tFont);
		gSizerA->Add(temp, 1, wxEXPAND | wxALL);
	}
	gSizerA->SetMinSize(wxSize(300, 200));
	this->SetSizerAndFit(gSizerA);
	gSizerA->Layout();
}

cRecords::~cRecords() {

}

void cRecords::OnToolBarButtonPress(wxCommandEvent & evt)
{
	wxButton *temp = wxDynamicCast(evt.GetEventObject(), wxButton);
	int bID = (int)temp->GetId();
	switch (bID) {
	case 101: {
		cMain *m_frm1 = new cMain();
		m_frm1->saveData = saveData;
		this->Destroy();
		m_frm1->Show();
		break;
	}
	case 102: {
		cSettings *m_frm2 = new cSettings(saveData);
		this->Destroy();
		m_frm2->Show();
		break;
	}
	case 103: {
		cAbout *m_frm3 = new cAbout(saveData);
		this->Destroy();
		m_frm3->Show();
		break;
	}
	}
}