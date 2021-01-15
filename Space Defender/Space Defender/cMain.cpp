#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain,wxFrame)
	EVT_BUTTON(1, SpaceDefenderOne)
	EVT_BUTTON(2, SpaceDefenderTwo)
	EVT_BUTTON(3, SpaceDefenderThree)
	EVT_BUTTON(4, SpaceDefenderFour)
wxEND_EVENT_TABLE()



cMain::cMain() : wxFrame(nullptr, wxID_ANY,"Space Defender", wxPoint(0,0), wxSize(800,800))
{
	ColorPallate cP;
	SelectionBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	SelectionBar->SetBackgroundColour(cP.LIGHT_PURPLE);
	wxBoxSizer *vSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer *hSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hSizer2 = new wxBoxSizer(wxHORIZONTAL);
	wxFlexGridSizer *gSizer = new wxFlexGridSizer(4, 1,20,20);
	saveData = new SaveState();
	saveData->Initialize();
	wxStaticText *textBx = 
		new 
		wxStaticText(this, wxID_ANY, " Welcome to Space Defender!\n This collection includes several arcade style games that are all playable from one single app.\n Each title in the colection builds and advances on concepts from the previous.\n Controls and other information are listed under the About page.", wxDefaultPosition , wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxFont TitleFont = textBx->GetFont();
	wxButton *settings = new wxButton(SelectionBar,101,"Settings",wxDefaultPosition,wxDefaultSize,0);
	settings->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(settings);
	wxButton *about = new wxButton(SelectionBar, 102, "About", wxDefaultPosition, wxDefaultSize, 0);
	about->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(about);
	wxButton *records = new wxButton(SelectionBar, 103, "Records", wxDefaultPosition, wxDefaultSize, 0);
	records->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cMain::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(records);
	SelectionBar->Realize();
	TitleFont.SetPointSize(24);
	textBx->SetFont(TitleFont);
	TitleFont.SetPointSize(16);
	textBx->Wrap(textBx->GetClientSize().GetWidth());
	m_btn1 = new wxButton(this, 1, "Space Defender 1", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	m_btn2 = new wxButton(this, 2, "Space Defender 2", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	m_btn3 = new wxButton(this, 3, "Space Defender 3", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	m_btn4 = new wxButton(this, 4, "Space Defender 4", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	m_btn1->SetFont(TitleFont);
	m_btn2->SetFont(TitleFont);
	m_btn3->SetFont(TitleFont);
	m_btn4->SetFont(TitleFont);
	vSizer->AddSpacer(100);
	hSizer2->Add(textBx, 1, wxALIGN_CENTER);
	vSizer->Add(hSizer2);
	gSizer->Add(m_btn1, 1, wxEXPAND | wxALL);
	gSizer->Add(m_btn2, 1, wxEXPAND | wxALL);
	gSizer->Add(m_btn3, 1, wxEXPAND | wxALL);
	gSizer->Add(m_btn4, 1, wxEXPAND | wxALL);
	vSizer->AddSpacer(50);
	vSizer->Add(gSizer,1, wxALIGN_CENTRE_HORIZONTAL);
	vSizer->SetMinSize(800,800);
	this->SetSizerAndFit(vSizer);
	vSizer->Layout();
	this->SetBackgroundColour(cP.RED);
	m_btn1->SetBackgroundColour(cP.BLACK);
	m_btn1->SetForegroundColour(cP.WHITE);
	m_btn2->SetBackgroundColour(cP.BLACK);
	m_btn2->SetForegroundColour(cP.WHITE);
	m_btn3->SetBackgroundColour(cP.BLACK);
	m_btn3->SetForegroundColour(cP.WHITE);
	m_btn4->SetBackgroundColour(cP.BLACK);
	m_btn4->SetForegroundColour(cP.WHITE);
	textBx->SetForegroundColour(cP.WHITE);
}

cMain::~cMain()
{
}

void cMain::SpaceDefenderOne(wxCommandEvent & evt)
{
	//Freeze prevents the user from changing any settings in the launcher or starting another game while the current one is running
	this->Freeze();
	s1 = new SpaceShip();
	//Uncomment to Run Space Defender 1 Game when button is pressed
	s1->runSpaceDefender();
	//m_list1->AppendString(m_txt1->GetValue());
	std::string GameOverMessage = " Game Over\n Score: " + std::to_string(s1->score);
	wxMessageBox(GameOverMessage);
	saveData->ScoreSum += s1->score;
	if (s1->score > saveData->highScore) {
		saveData->highScore = s1->score;
	}
	saveData->writeSave();
	delete s1;
	//Thaw counteracts freeze and makes the window usable again
	this->Thaw();
	evt.Skip();
}

void cMain::SpaceDefenderTwo(wxCommandEvent & evt) {
	this->Freeze();
	s2 = new SpaceShipTwo();
	s2->runSpaceDefender();
	std::string GameOverMessage = " Game Over\n Score: " + std::to_string(s2->score) + "\n Kills: " + std::to_string(s2->kills);
	wxMessageBox(GameOverMessage);
	saveData->ScoreSum += s2->score;
	if (s2->score > saveData->highScore) {
		saveData->highScore = s2->score;
	}
	saveData->writeSave();
	delete s2;
	this->Thaw();
	evt.Skip();
}

void cMain::SpaceDefenderThree(wxCommandEvent & evt) {
	this->Freeze();
	s3 = new SpaceShipThree(saveData->difficulty);
	s3->runSpaceDefender();
	std::string GameOverMessage = " Game Over\n Score: " + std::to_string(s3->score) + "\n Kills: " + std::to_string(s3->kills);
	wxMessageBox(GameOverMessage);
	saveData->ScoreSum += s3->score;
	if (s3->score > saveData->highScore) {
		saveData->highScore = s3->score;
	}
	saveData->writeSave();
	delete s3;
	this->Thaw();
	evt.Skip();
}

void cMain::SpaceDefenderFour(wxCommandEvent & evt) {
	this->Freeze();
	s4 = new SpaceShipFour(saveData->difficulty, saveData);
	s4->runSpaceDefender();
	std::string GameOverMessage = " Game Over\n Score: " + std::to_string(s4->score) + "\n Kills: " + std::to_string(s4->kills);
	wxMessageBox(GameOverMessage);
	saveData->ScoreSum += s4->score;
	if (s4->score > saveData->highScore) {
		saveData->highScore = s4->score;
	}
	saveData->writeSave();
	delete s4;
	this->Thaw();
	evt.Skip();
}

void cMain::OnToolBarButtonPress(wxCommandEvent & evt) {
	wxButton *temp = wxDynamicCast(evt.GetEventObject(), wxButton);
	int bID = (int) temp->GetId();
	switch (bID) {
	case 101:{
		cSettings *m_frm2 = new cSettings(saveData);
		this->Destroy();
		m_frm2->Show();
		break;
	}
	case 102: {
		cAbout *m_frm3 = new cAbout(saveData);
		this->Destroy();
		m_frm3->Show();
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