#include "cAbout.h"

cAbout::cAbout(SaveState *save) : wxFrame(nullptr, wxID_ANY, "Space Defender", wxPoint(0, 0), wxSize(800, 800)) {
	saveData = save;
	ColorPallate cP;
	wxBoxSizer *vSizerA = new wxBoxSizer(wxVERTICAL);
	SelectionBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	SelectionBar->SetBackgroundColour(cP.LIGHT_PURPLE);
	this->SetBackgroundColour(cP.RED);
	wxButton *menu = new wxButton(SelectionBar, 101, "Main Menu", wxDefaultPosition, wxDefaultSize, 0);
	menu->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cAbout::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(menu);
	wxButton *settings = new wxButton(SelectionBar, 102, "Settings", wxDefaultPosition, wxDefaultSize, 0);
	settings->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cAbout::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(settings);
	wxButton *records = new wxButton(SelectionBar, 103, "Records", wxDefaultPosition, wxDefaultSize, 0);
	records->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cAbout::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(records);
	SelectionBar->Realize();
	wxStaticText *textBx1 =
		new
		wxStaticText(this, wxID_ANY, "Welcome To Space Defender Collection!\nThis Collection contains several arcade-style games which can all be played from one launcher!\nThe objective of the games is to defeat as many enemies as possible.\nIf your ship collides with an enemy or the enmies touch the bottom of ths screen, it's Game Over. ", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxStaticText *textBx2 =
		new
		wxStaticText(this, wxID_ANY, "The original game, Space Defender 1 will have 3 enemies active at one time and will increase in difficulty as your score increases.\nThe controls to the game are WASD for movement and SPACEBAR to fire.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxStaticText *textBx3 =
		new
		wxStaticText(this, wxID_ANY, "Space Defender 2 introduces significant new changes over Space Defender 1.\nThe game implements an algorithm to randomly generate a unique set of enemies for each session of the game, ensuring that no two playthroughs are the same.\nEnemies also have variable health and speed which affects how much score is awarded for a kill.\n Space Defender 2 also adds the ability to switch to a missile weapon for higher damage.\nThe controls to the game are WASD for movement, Z to switch weapons, and SPACEBAR to fire.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxStaticText *textBx4 =
		new
		wxStaticText(this, wxID_ANY, "Space Defender 3 further iterates on Space Defender 2.\nA variable difficulty system is added with the difficulty being set using the settings tab in the launcer.\n Also new to Space Defender 3 are boss fights, which occur after 10 enemies are killed and increase in difficulty as time goes on.\nThe controls to the game are WASD for movement, Z to switch weapons, and SPACEBAR to fire.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxStaticText *textBx6 =
		new
		wxStaticText(this, wxID_ANY, "This project is developed by Yazan Abughazaleh. Credits for the libraries used wxWidgets and glfw as well as OneLoneCoder's GUI tutorials on YouTube.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxStaticText *textBx5 =
		new
		wxStaticText(this, wxID_ANY, "Space Defender 4 adds a massive rework to the fundamentals of the game.\nThe projectile system has been reworked to use a buffer system which allows for a large number of projectiles and an upgrade system which can be accessed under Settings.\n The ship is also customizable and bosses now spawn after 100 kills.\nThe controls to the game are WASD for movement, Z to switch weapons, and SPACEBAR to fire.", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

	vSizerA->AddSpacer(20);
	vSizerA->Add(textBx1,0, wxALIGN_CENTRE_HORIZONTAL);
	vSizerA->AddSpacer(20);
	vSizerA->Add(textBx2,0, wxALIGN_CENTRE_HORIZONTAL);
	vSizerA->AddSpacer(20);
	vSizerA->Add(textBx3,0, wxALIGN_CENTRE_HORIZONTAL);
	vSizerA->AddSpacer(20);
	vSizerA->Add(textBx4,0, wxALIGN_CENTRE_HORIZONTAL);
	vSizerA->AddSpacer(20);
	vSizerA->Add(textBx5, 0, wxALIGN_CENTRE_HORIZONTAL);
	vSizerA->AddSpacer(20);
	vSizerA->Add(textBx6, 0, wxALIGN_CENTRE_HORIZONTAL);
	vSizerA->SetMinSize(wxSize(900, 200));
	this->SetSizerAndFit(vSizerA);
	vSizerA->Layout();
	textBx1->SetForegroundColour(cP.WHITE);
	textBx2->SetForegroundColour(cP.WHITE);
	textBx3->SetForegroundColour(cP.WHITE);
	textBx4->SetForegroundColour(cP.WHITE);
	textBx5->SetForegroundColour(cP.WHITE);
	textBx6->SetForegroundColour(cP.WHITE);
}

cAbout::~cAbout() {

}

void cAbout::OnToolBarButtonPress(wxCommandEvent & evt)
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
		cRecords *m_frm4 = new cRecords(saveData);
		this->Destroy();
		m_frm4->Show();
		break;
	}
	}
}