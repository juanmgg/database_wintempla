#pragma once   //_____________________________________________ alumnoDlg.h  
#include "resource.h"

class alumnoDlg: public Win::Dialog
{
public:
	alumnoDlg()
	{
		alumno_id = -1;
	}
	~alumnoDlg()
	{
	}
	int alumno_id;
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbNombre;
	Win::Textbox tbxNombre;
	Win::Label lbCurp;
	Win::Textbox tbxCurp;
	Win::Label lbSexo;
	Win::Textbox tbxSexo;
	Win::Label lbF_nacimiento;
	Win::DateTimeBox dtboxF_nacimiento;
	Win::Label lbDomicilio;
	Win::Textbox tbxDomicilio;
	Win::Label lbTelefono;
	Win::Textbox tbxTelefono;
	Win::Label lbCorreo;
	Win::Textbox tbxCorreo;
	Win::Label lbUsuario;
	Win::Textbox tbxUsuario;
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
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_MULTILINE | ES_LEFT | ES_WINNORMALCASE, 3.17500, 0.26458, 5.29167, 0.60854, hWnd, 1001);
		lbCurp.CreateX(NULL, L"Curp", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 1.16417, 2.64583, 0.60854, hWnd, 1002);
		tbxCurp.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 1.11125, 5.29167, 0.60854, hWnd, 1003);
		lbSexo.CreateX(NULL, L"Sexo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 2.01083, 2.64583, 0.60854, hWnd, 1004);
		tbxSexo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 1.95792, 5.29167, 0.60854, hWnd, 1005);
		lbF_nacimiento.CreateX(NULL, L"F nacimiento", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 2.85750, 2.64583, 0.60854, hWnd, 1006);
		dtboxF_nacimiento.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | DTS_RIGHTALIGN, 3.17500, 2.80458, 5.29167, 0.60854, hWnd, 1007);
		lbDomicilio.CreateX(NULL, L"Domicilio", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 3.70417, 2.64583, 0.60854, hWnd, 1008);
		tbxDomicilio.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 3.65125, 5.29167, 0.60854, hWnd, 1009);
		lbTelefono.CreateX(NULL, L"Telefono", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 4.55083, 2.64583, 0.60854, hWnd, 1010);
		tbxTelefono.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 4.49792, 5.29167, 0.60854, hWnd, 1011);
		lbCorreo.CreateX(NULL, L"Correo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 5.39750, 2.64583, 0.60854, hWnd, 1012);
		tbxCorreo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 5.34458, 5.29167, 0.60854, hWnd, 1013);
		lbUsuario.CreateX(NULL, L"Usuario", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 6.24417, 2.64583, 0.60854, hWnd, 1014);
		tbxUsuario.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 6.19125, 5.29167, 0.60854, hWnd, 1015);
		lbPassword_.CreateX(NULL, L"Password ", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.26458, 7.09083, 2.64583, 0.60854, hWnd, 1016);
		tbxPassword_.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.17500, 7.03792, 5.29167, 0.60854, hWnd, 1017);
		btOK.CreateX(NULL, L"OK", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.73125, 0.26458, 2.11667, 0.68792, hWnd, 1018);
		btCancel.CreateX(NULL, L"Cancel", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.73125, 1.21708, 2.11667, 0.68792, hWnd, 1019);
		this->SetDefaultButton(btOK);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbNombre.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		lbCurp.Font = fontArial009A;
		tbxCurp.Font = fontArial009A;
		lbSexo.Font = fontArial009A;
		tbxSexo.Font = fontArial009A;
		lbF_nacimiento.Font = fontArial009A;
		dtboxF_nacimiento.Font = fontArial009A;
		lbDomicilio.Font = fontArial009A;
		tbxDomicilio.Font = fontArial009A;
		lbTelefono.Font = fontArial009A;
		tbxTelefono.Font = fontArial009A;
		lbCorreo.Font = fontArial009A;
		tbxCorreo.Font = fontArial009A;
		lbUsuario.Font = fontArial009A;
		tbxUsuario.Font = fontArial009A;
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
