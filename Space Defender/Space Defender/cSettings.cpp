#include "cSettings.h"


cSettings::cSettings(SaveState *save):wxFrame(nullptr, wxID_ANY, "Space Defender", wxPoint(0, 0), wxSize(800, 800))
{
	saveData = save;
	ColorPallate cP;
	wxFlexGridSizer *gSizerA = new wxFlexGridSizer(3, 3, 20, 20);
	wxBoxSizer *hSizerA = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hSizerB = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *hSizerC = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer *vSizerA = new wxBoxSizer(wxVERTICAL);
	SelectionBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
	SelectionBar->SetBackgroundColour(cP.LIGHT_PURPLE);
	wxButton *menu = new wxButton(SelectionBar, 101, "Main Menu", wxDefaultPosition, wxDefaultSize, 0);
	menu->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(menu);
	wxButton *about = new wxButton(SelectionBar, 102, "About", wxDefaultPosition, wxDefaultSize, 0);
	about->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(about);
	wxButton *records = new wxButton(SelectionBar, 103, "Records", wxDefaultPosition, wxDefaultSize, 0);
	records->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnToolBarButtonPress), nullptr, this);
	SelectionBar->AddControl(records);
	SelectionBar->Realize();
	this->SetBackgroundColour(cP.RED);
	wxStaticText *textBxA = new wxStaticText(this, wxID_ANY, "Red Color Adjustment", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxStaticText *textBxB = new wxStaticText(this, wxID_ANY, "Green Color Adjustment", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxStaticText *textBxC = new wxStaticText(this, wxID_ANY, "Blue Color Adjustment", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
	wxString startVal;
	startVal << saveData->r;
	textBxA1 = new wxStaticText(this, wxID_ANY, startVal, wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	startVal = "";
	startVal << saveData->g;
	textBxB1 = new wxStaticText(this, wxID_ANY, startVal, wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	startVal = "";
	startVal << saveData->b;
	textBxC1 = new wxStaticText(this, wxID_ANY, startVal, wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
	RedSlider = new wxSlider(this, 1, saveData->r, 0, 255);
	RedSlider->Connect(wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(cSettings::OnSliderDelta), nullptr, this);
	GreenSlider = new wxSlider(this, 2, saveData->g, 0, 255);
	GreenSlider->Connect(wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(cSettings::OnSliderDelta), nullptr, this);
	BlueSlider = new wxSlider(this, 3, saveData->b, 0, 255);
	BlueSlider->Connect(wxEVT_COMMAND_SLIDER_UPDATED, wxScrollEventHandler(cSettings::OnSliderDelta), nullptr, this);
	colorPreview = new wxStaticText(this, wxID_ANY, "\n\n\nColor Preview", wxDefaultPosition, wxSize(110, 110), wxALIGN_CENTRE_HORIZONTAL);
	saveButton = new wxButton(this, wxID_ANY, "Save Settings", wxDefaultPosition, wxSize(90, 20), wxBORDER_NONE);
	saveButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnSaveButtonPress), nullptr, this);
	resetButton = new wxButton(this, wxID_ANY, "Delete Data", wxDefaultPosition, wxSize(90, 20), wxBORDER_NONE);
	resetButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnSaveButtonResetPress), nullptr, this);
	eButton = new wxButton(this, 201, "EASY", wxDefaultPosition, wxSize(90, 30), wxBORDER_NONE);
	mButton = new wxButton(this, 202, "MEDIUM", wxDefaultPosition, wxSize(90, 30), wxBORDER_NONE);
	hButton = new wxButton(this, 203, "HARD", wxDefaultPosition, wxSize(90, 30), wxBORDER_NONE);
	eButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnDiffButtonPress), nullptr, this);
	mButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnDiffButtonPress), nullptr, this);
	hButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnDiffButtonPress), nullptr, this);
	upBUS = new wxButton(this, 301, "Upgrade Bullet Fire Speed",wxDefaultPosition,wxSize(180,30),wxBORDER_NONE);
	upBUD = new wxButton(this, 302, "Upgrade Bullet Damage", wxDefaultPosition, wxSize(180, 30), wxBORDER_NONE);
	upMIS = new wxButton(this, 303, "Upgrade Missile Fire Speed", wxDefaultPosition, wxSize(180, 30), wxBORDER_NONE);
	upMID = new wxButton(this, 304, "Upgrade Missile Damage", wxDefaultPosition, wxSize(180, 30), wxBORDER_NONE);
	upSPD = new wxButton(this, 305, "Upgrade Ship Speed", wxDefaultPosition, wxSize(180, 30), wxBORDER_NONE);
	upBUS->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnUpgradeButtonPress), nullptr, this);
	upBUD->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnUpgradeButtonPress), nullptr, this);
	upMIS->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnUpgradeButtonPress), nullptr, this);
	upMID->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnUpgradeButtonPress), nullptr, this);
	upSPD->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(cSettings::OnUpgradeButtonPress), nullptr, this);
	wxFont fSizeSwitch = eButton->GetFont();
	fSizeSwitch.SetPointSize(16);
	eButton->SetFont(fSizeSwitch);
	mButton->SetFont(fSizeSwitch);
	hButton->SetFont(fSizeSwitch);
	fSizeSwitch.SetPointSize(10);
	upBUD->SetFont(fSizeSwitch);
	upBUS->SetFont(fSizeSwitch);
	upMIS->SetFont(fSizeSwitch);
	upMID->SetFont(fSizeSwitch);
	upSPD->SetFont(fSizeSwitch);
	hSizerB->AddSpacer(50);
	hSizerB->Add(eButton);
	hSizerB->AddSpacer(50);
	hSizerB->Add(mButton);
	hSizerB->AddSpacer(50);
	hSizerB->Add(hButton);
	hSizerC->AddSpacer(50);
	hSizerC->Add(upBUS);
	hSizerC->AddSpacer(50);
	hSizerC->Add(upBUD);
	hSizerC->AddSpacer(50);
	hSizerC->Add(upMIS);
	hSizerC->AddSpacer(50);
	hSizerC->Add(upMID);
	hSizerC->AddSpacer(50);
	hSizerC->Add(upSPD);
	hSizerC->AddSpacer(50);
	gSizerA->Add(textBxA);
	gSizerA->Add(RedSlider);
	gSizerA->Add(textBxA1);
	gSizerA->Add(textBxB);
	gSizerA->Add(GreenSlider);
	gSizerA->Add(textBxB1);
	gSizerA->Add(textBxC);
	gSizerA->Add(BlueSlider);
	gSizerA->Add(textBxC1);
	hSizerA->AddSpacer(50);
	hSizerA->Add(gSizerA);
	hSizerA->AddSpacer(50);
	hSizerA->Add(colorPreview);
	hSizerA->AddSpacer(50);
	hSizerA->Add(saveButton);
	hSizerA->AddSpacer(50);
	hSizerA->Add(resetButton);
	hSizerA->AddSpacer(50);
	hSizerA->SetMinSize(wxSize(400, 150));
	vSizerA->AddSpacer(50);
	vSizerA->Add(hSizerA);
	vSizerA->Add(hSizerB);
	vSizerA->AddSpacer(20);
	vSizerA->Add(hSizerC);
	vSizerA->AddSpacer(50);
	this->SetSizerAndFit(vSizerA);
	vSizerA->Layout();
	colorPreview->SetBackgroundColour(wxColour(saveData->r, saveData->g, saveData->b, 255));
	colorPreview->SetForegroundColour(wxColour(255 - saveData->r, 255 - saveData->g, 255 - saveData->b, 255));
	textBxA->SetForegroundColour(cP.WHITE);
	textBxB->SetForegroundColour(cP.WHITE);
	textBxC->SetForegroundColour(cP.WHITE);
	textBxA1->SetForegroundColour(cP.WHITE);
	textBxB1->SetForegroundColour(cP.WHITE);
	textBxC1->SetForegroundColour(cP.WHITE);
	RedSlider->SetForegroundColour(cP.BLACK);
	GreenSlider->SetForegroundColour(cP.BLACK);
	BlueSlider->SetForegroundColour(cP.BLACK);
	saveButton->SetBackgroundColour(cP.BLACK);
	saveButton->SetForegroundColour(cP.WHITE);
	eButton->SetBackgroundColour(cP.BLACK);
	eButton->SetForegroundColour(cP.WHITE);
	mButton->SetBackgroundColour(cP.BLACK);
	mButton->SetForegroundColour(cP.WHITE);
	hButton->SetBackgroundColour(cP.BLACK);
	hButton->SetForegroundColour(cP.WHITE);
	upBUS->SetBackgroundColour(cP.BLACK);
	upBUS->SetForegroundColour(cP.WHITE);
	upBUD->SetBackgroundColour(cP.BLACK);
	upBUD->SetForegroundColour(cP.WHITE);
	upMIS->SetBackgroundColour(cP.BLACK);
	upMIS->SetForegroundColour(cP.WHITE);
	upMID->SetBackgroundColour(cP.BLACK);
	upMID->SetForegroundColour(cP.WHITE);
	upSPD->SetBackgroundColour(cP.BLACK);
	upSPD->SetForegroundColour(cP.WHITE);
	resetButton->SetBackgroundColour(cP.BLACK);
	resetButton->SetForegroundColour(cP.WHITE);

	
}

cSettings::~cSettings()
{
}

void cSettings::OnToolBarButtonPress(wxCommandEvent & evt)
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

void cSettings::OnSliderDelta(wxScrollEvent & evt)
{
	ColorPallate cP;
	wxSlider *temp = wxDynamicCast(evt.GetEventObject(), wxSlider);
	int sID = (int)temp->GetId();
	switch (sID) {
	case 1: {
		textBxA1->SetLabel(std::to_string(RedSlider->GetValue()));
		break;
	}
	case 2: {
		textBxB1->SetLabel(std::to_string(GreenSlider->GetValue()));
		break;
	}
	case 3: {
		textBxC1->SetLabel(std::to_string(BlueSlider->GetValue()));
		break;
	}
	}
	colorPreview->SetBackgroundColour(wxColour(RedSlider->GetValue(), GreenSlider->GetValue(), BlueSlider->GetValue(), 100));
	colorPreview->SetForegroundColour(wxColour(255 - RedSlider->GetValue(), 255 - GreenSlider->GetValue(), 255 - BlueSlider->GetValue(), 100));
	colorPreview->Refresh();
}

void cSettings::OnDiffButtonPress(wxCommandEvent & evt)
{
	wxButton *temp = wxDynamicCast(evt.GetEventObject(), wxButton);
	int bID = (int)temp->GetId();
	switch (bID)
	{
	case 201: {
		saveData->difficulty = 1;
		saveData->writeSave();
		wxMessageBox("Easy Difficulty Selected");
		break;
	}
	case 202: {
		saveData->difficulty = 2;
		saveData->writeSave();
		wxMessageBox("Medium Difficulty Selected");
		break;
	}
	case 203: {
		saveData->difficulty = 3;
		saveData->writeSave();
		wxMessageBox("Hard Difficulty Selected");
		break;
	}
	}
}

void cSettings::OnSaveButtonPress(wxCommandEvent & evt)
{
	saveData->r = RedSlider->GetValue();
	saveData->g = GreenSlider->GetValue();
	saveData->b = BlueSlider->GetValue();
	saveData->writeSave();
	wxMessageBox("Save Successful");
}

void cSettings::OnUpgradeButtonPress(wxCommandEvent &evt) {
	wxButton *temp = wxDynamicCast(evt.GetEventObject(), wxButton);
	int bID = (int)temp->GetId();
	if (saveData->ScoreSum - 10000 < 0) {
		wxMessageBox("You do not have enough accumulated score to afford this upgrade.");
	}
	else {
		switch (bID)
		{
		case 301: {
			if (saveData->bulletFireInt == 50) {
				wxMessageBox("You have upgraded bullet fire speed to the maximum level.");
			}
			else {
				int yes = wxMessageBox("Upgrade bullet fire speed? This costs 10000 score points.","Upgrade?", wxYES_NO|wxCENTRE);
				if (yes == wxYES) {
					saveData->bulletFireInt -= 5;
					saveData->ScoreSum -= 10000;
					saveData->writeSave();
					wxMessageBox("Bullet fire speed has been upgraded.");
				}
			}
			break;
		}
		case 302: {
			if (saveData->bulletDamage == 128) {
				wxMessageBox("You have upgraded bullet damage to the maximum level.");
			}
			else {
				int yes = wxMessageBox("Upgrade bullet damage? This costs 10000 score points.", "Upgrade?", wxYES_NO | wxCENTRE);
				if (yes == wxYES) {
					saveData->bulletDamage *= 2;
					saveData->ScoreSum -= 10000;
					saveData->writeSave();
					wxMessageBox("Bullet damage has been upgraded.");
				}
			}
			
			break;
		}
		case 303: {
			if (saveData->missileFireInt == 200) {
				wxMessageBox("You have upgraded missile fire speed to the maximum level.");
			}
			else {
				int yes = wxMessageBox("Upgrade missile fire speed? This costs 10000 score points.", "Upgrade?", wxYES_NO | wxCENTRE);
				if (yes == wxYES) {
					saveData->missileFireInt -= 50;
					saveData->ScoreSum -= 10000;
					saveData->writeSave();
					wxMessageBox("Missile fire speed has been upgraded.");
				}
			}
			break;
		}
		case 304: {
			if (saveData->missileDamage == 960) {
				wxMessageBox("You have upgraded missile damage to the maximum level.");
			}
			else {
				int yes = wxMessageBox("Upgrade missile damage? This costs 10000 score points.", "Upgrade?", wxYES_NO | wxCENTRE);
				if (yes == wxYES) {
					saveData->missileDamage *= 2;
					saveData->ScoreSum -= 10000;
					saveData->writeSave();
					wxMessageBox("Missile damage has been upgraded.");
				}
			}
			
			break;
		}
		case 305: {
			if (saveData->moveInc == .05f) {
				wxMessageBox("You have upgraded ship speed to the maximum level.");
			}
			else {
				int yes = wxMessageBox("Upgrade ship speed? This costs 10000 score points.", "Upgrade?", wxYES_NO | wxCENTRE);
				if (yes == wxYES) {
					saveData->moveInc +=.001f;
					saveData->ScoreSum -= 10000;
					saveData->writeSave();
					wxMessageBox("Ship speed has been upgraded.");
				}
			}

			break;
		}
		}
	}
}

void cSettings::OnSaveButtonResetPress(wxCommandEvent &evt) {
	int yes = wxMessageBox("Warning. Once saved data is deleted, it cannot be recovered. Continue?", "Warning!", wxYES_NO | wxCENTRE);
	if (yes == wxYES) {
		saveData->restoreToDefault();
		wxMessageBox("Data has been deleted");
	}
}
