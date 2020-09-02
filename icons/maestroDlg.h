#pragma once   //_____________________________________________ maestroDlg.h  
#include "resource.h"

class maestroDlg: public Win::Dialog
{
public:
	maestroDlg()
	{
		maestro_id = -1;
	}
	~maestroDlg()
	{
	}
	int maestro_id = 0;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbNombre;
	Win::Textbox tbxNombre;
	Win::Label lbCedula;
	Win::Textbox tbxCedula;
	Win::Label lbNss;
	Win::Textbox tbxNss;
	Win::Label lbRfc;
	Win::Textbox tbxRfc;
	Win::Label lbDomicilio;
	Win::Textbox tbxDomicilio;
	Win::Label lbCorreo;
	Win::Textbox tbxCorreo;
	Win::Label lbTelefono;
	Win::Textbox tbxTelefono;
	Win::Label lbUsuario_;
	Win::Textbox tbxUsuario_;
	Win::Label lbPassword_;
	Win::Textbox tbxPassword_;
	Win::Button btOK;
	Win::Button btCancel;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(11.03313);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(7.88458);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbNombre.CreateX(NULL, L"Nombre", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 0.31750, 2.64583, 0.60854, hWnd, 1000);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 0.26458, 5.29167, 0.60854, hWnd, 1001);
		lbCedula.CreateX(NULL, L"Cedula", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 1.16417, 2.64583, 0.60854, hWnd, 1002);
		tbxCedula.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 1.11125, 5.29167, 0.60854, hWnd, 1003);
		lbNss.CreateX(NULL, L"Nss", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 2.01083, 2.64583, 0.60854, hWnd, 1004);
		tbxNss.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 1.95792, 5.29167, 0.60854, hWnd, 1005);
		lbRfc.CreateX(NULL, L"Rfc", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 2.85750, 2.64583, 0.60854, hWnd, 1006);
		tbxRfc.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 2.80458, 5.29167, 0.60854, hWnd, 1007);
		lbDomicilio.CreateX(NULL, L"Domicilio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 3.70417, 2.64583, 0.60854, hWnd, 1008);
		tbxDomicilio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 3.65125, 5.29167, 0.60854, hWnd, 1009);
		lbCorreo.CreateX(NULL, L"Correo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 4.55083, 2.64583, 0.60854, hWnd, 1010);
		tbxCorreo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 4.49792, 5.29167, 0.60854, hWnd, 1011);
		lbTelefono.CreateX(NULL, L"Telefono", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 5.39750, 2.64583, 0.60854, hWnd, 1012);
		tbxTelefono.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 5.34458, 5.29167, 0.60854, hWnd, 1013);
		lbUsuario_.CreateX(NULL, L"Usuario ", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 6.24417, 2.64583, 0.60854, hWnd, 1014);
		tbxUsuario_.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 6.19125, 5.29167, 0.60854, hWnd, 1015);
		lbPassword_.CreateX(NULL, L"Password ", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 7.09083, 2.64583, 0.60854, hWnd, 1016);
		tbxPassword_.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 7.03792, 5.29167, 0.60854, hWnd, 1017);
		btOK.CreateX(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.73125, 0.26458, 2.11667, 0.68792, hWnd, 1018);
		btCancel.CreateX(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.73125, 1.21708, 2.11667, 0.68792, hWnd, 1019);
		this->SetDefaultButton(btOK);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbNombre.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		lbCedula.Font = fontArial009A;
		tbxCedula.Font = fontArial009A;
		lbNss.Font = fontArial009A;
		tbxNss.Font = fontArial009A;
		lbRfc.Font = fontArial009A;
		tbxRfc.Font = fontArial009A;
		lbDomicilio.Font = fontArial009A;
		tbxDomicilio.Font = fontArial009A;
		lbCorreo.Font = fontArial009A;
		tbxCorreo.Font = fontArial009A;
		lbTelefono.Font = fontArial009A;
		tbxTelefono.Font = fontArial009A;
		lbUsuario_.Font = fontArial009A;
		tbxUsuario_.Font = fontArial009A;
		lbPassword_.Font = fontArial009A;
		tbxPassword_.Font = fontArial009A;
		btOK.Font = fontArial009A;
		btCancel.Font = fontArial009A;
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
