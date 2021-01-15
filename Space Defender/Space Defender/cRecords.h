#pragma once
#include "wx/wx.h"
#include <vector>
#include "SaveState.h"
#include "cMain.h"
#include "cApp.h"
#include "cSettings.h"
#include "cAbout.h"
class cRecords : public wxFrame {
public:
	cRecords(SaveState *save);
	~cRecords();
	wxToolBar *SelectionBar = nullptr;
	void OnToolBarButtonPress(wxCommandEvent &evt);
	SaveState *saveData;
};
