#pragma once   //_____________________________________________ AboudDlg.h  
#include "resource.h"

class AboudDlg: public Win::Dialog
{
public:
	AboudDlg()
	{
	}
	~AboudDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lb1;
	Win::Button btOK;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(6.69396);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(3.65125);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lb1.CreateX(NULL, L"About ths Proyect", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 2.64583, 1.69333, 3.86292, 0.60854, hWnd, 1000);
		btOK.CreateX(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 3.49250, 2.77812, 2.16958, 0.68792, hWnd, 1001);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lb1.Font = fontArial009A;
		btOK.Font = fontArial009A;
	}
	//_________________________________________________
	void btOK_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btOK.IsEvent(e, BN_CLICKED)) {btOK_Click(e); return true;}
		return false;
	}
};
