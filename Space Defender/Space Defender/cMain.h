#ifndef CMAIN_H
#define CMAIN_H
#include "wx/wx.h"
#include "SpaceShip.h"
#include "SpaceShipTwo.h"
#include "SpaceShipThree.h"
#include "SpaceShipFour.h"
#include "SaveState.h"
#include "cSettings.h"
#include "cAbout.h"
#include "cRecords.h"


struct ColorPallate {
	wxColour RED = wxColour(100, 0, 0, 50);
	wxColour WHITE = wxColour(255, 255, 255, 100);
	wxColour BLACK = wxColour(0, 0, 0, 50);
	wxColour BLUE = wxColour(0, 20, 100, 50);
	wxColour LIGHT_PURPLE = wxColour(219, 171, 218, 50);
};

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:
	wxFrame* passPtr;
	wxToolBar *SelectionBar = nullptr;
	wxButton *m_btn1 = nullptr;
	wxButton *m_btn2 = nullptr;
	wxButton *m_btn3 = nullptr;
	wxButton *m_btn4 = nullptr;
	SpaceShip *s1 = nullptr;
	SpaceShipTwo *s2 = nullptr;
	SpaceShipThree *s3 = nullptr;
	SpaceShipFour *s4 = nullptr;
	SaveState *saveData;
	

	void SpaceDefenderOne(wxCommandEvent &evt);
	void SpaceDefenderTwo(wxCommandEvent &evt);
	void SpaceDefenderThree(wxCommandEvent &evt);
	void SpaceDefenderFour(wxCommandEvent &evt);
	void OnToolBarButtonPress(wxCommandEvent &evt);
	wxDECLARE_EVENT_TABLE();

};

#endif

