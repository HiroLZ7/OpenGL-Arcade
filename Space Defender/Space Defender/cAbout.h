#pragma once
#include "wx/wx.h"
#include "SaveState.h"
#include "cMain.h"
#include "cApp.h"
#include "cSettings.h"
#include "cRecords.h"
class cAbout : public wxFrame {
public:
	cAbout(SaveState *save);
	~cAbout();
	wxToolBar *SelectionBar = nullptr;
	void OnToolBarButtonPress(wxCommandEvent &evt);
	SaveState *saveData;

};
