#pragma once
#include "wx/wx.h"
#include "SaveState.h"
#include "cMain.h"
#include "cApp.h"
#include "cAbout.h"
#include "cRecords.h"
class cSettings : public wxFrame {
public :
	cSettings(SaveState *save);
	~cSettings();
	wxToolBar *SelectionBar = nullptr;
	void OnToolBarButtonPress(wxCommandEvent &evt);
	void OnSliderDelta(wxScrollEvent &evt);
	void OnDiffButtonPress(wxCommandEvent &evt);
	void OnSaveButtonPress(wxCommandEvent &evt);
	void OnSaveButtonResetPress(wxCommandEvent &evt);
	void OnUpgradeButtonPress(wxCommandEvent &evt);
	SaveState *saveData;
private:
	wxSlider *RedSlider;
	wxSlider *BlueSlider;
	wxSlider *GreenSlider;
	wxStaticText *textBxA1;
	wxStaticText *textBxB1;
	wxStaticText *textBxC1;
	wxStaticText *colorPreview;
	wxButton *eButton, *mButton, *hButton;
	wxButton *upBUS, *upBUD, *upMIS, *upMID, *upSPD;
	wxButton *saveButton, *resetButton;
};