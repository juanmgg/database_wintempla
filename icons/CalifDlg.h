#pragma once   //_____________________________________________ CalifDlg.h  
#include "resource.h"

class CalifDlg: public Win::Dialog
{
public:
	CalifDlg()
	{
		calificacion_id = -1;
	}
	~CalifDlg()
	{
	}
	int calificacion_id = 0;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbAlumno;
	Win::DropDownList ddAlumno;
	Win::Label lbMateria;
	Win::DropDownList ddMateria;
	Win::Label lbMaestro;
	Win::DropDownList ddMaestro;
	Win::Label lbCalificacion_1;
	Win::Textbox tbxCalificacion_1;
	Win::Label lbCalificacion_2;
	Win::Textbox tbxCalificacion_2;
	Win::Label lbCalificacion_3;
	Win::Textbox tbxCalificacion_3;
	Win::Button btOK;
	Win::Button btCancel;
	Win::Label lb7;
	Win::Textbox tbxPromedio;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(8.65188);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(8.41375);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbAlumno.CreateX(NULL, L"Alumno", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 1.16417, 2.64583, 0.60854, hWnd, 1000);
		ddAlumno.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.17500, 1.11125, 5.29167, 0.60854, hWnd, 1001);
		lbMateria.CreateX(NULL, L"Materia", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 2.01083, 2.64583, 0.60854, hWnd, 1002);
		ddMateria.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.17500, 1.95792, 5.29167, 0.60854, hWnd, 1003);
		lbMaestro.CreateX(NULL, L"Maestro", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 2.85750, 2.64583, 0.60854, hWnd, 1004);
		ddMaestro.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 3.17500, 2.80458, 5.29167, 0.60854, hWnd, 1005);
		lbCalificacion_1.CreateX(NULL, L"Calificacion 1", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 3.70417, 2.64583, 0.60854, hWnd, 1006);
		tbxCalificacion_1.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 3.65125, 5.29167, 0.60854, hWnd, 1007);
		lbCalificacion_2.CreateX(NULL, L"Calificacion 2", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 4.55083, 2.64583, 0.60854, hWnd, 1008);
		tbxCalificacion_2.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 4.49792, 5.29167, 0.60854, hWnd, 1009);
		lbCalificacion_3.CreateX(NULL, L"Calificacion 3", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 5.39750, 2.64583, 0.60854, hWnd, 1010);
		tbxCalificacion_3.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 5.34458, 5.29167, 0.60854, hWnd, 1011);
		btOK.CreateX(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 1.50812, 7.54062, 2.11667, 0.68792, hWnd, 1012);
		btCancel.CreateX(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 4.49792, 7.54062, 2.11667, 0.68792, hWnd, 1013);
		lb7.CreateX(NULL, L"Promedio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 6.19125, 2.64583, 0.60854, hWnd, 1014);
		tbxPromedio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 3.14854, 6.21771, 5.31813, 0.63500, hWnd, 1015);
		this->SetDefaultButton(btOK);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbAlumno.Font = fontArial009A;
		ddAlumno.Font = fontArial009A;
		lbMateria.Font = fontArial009A;
		ddMateria.Font = fontArial009A;
		lbMaestro.Font = fontArial009A;
		ddMaestro.Font = fontArial009A;
		lbCalificacion_1.Font = fontArial009A;
		tbxCalificacion_1.Font = fontArial009A;
		lbCalificacion_2.Font = fontArial009A;
		tbxCalificacion_2.Font = fontArial009A;
		lbCalificacion_3.Font = fontArial009A;
		tbxCalificacion_3.Font = fontArial009A;
		btOK.Font = fontArial009A;
		btCancel.Font = fontArial009A;
		lb7.Font = fontArial009A;
		tbxPromedio.Font = fontArial009A;
	}
	//_________________________________________________
	void btOK_Click(Win::Event& e);
	void btCancel_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btOK.IsEvent(e, BN_CLICKED)) {btOK_Click(e); return true;}
		if (btCancel.IsEvent(e, BN_CLICKED)) {btCancel_Click(e); return true;}
		return false;
	}
};
