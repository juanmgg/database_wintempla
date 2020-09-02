#include "stdafx.h"  //_____________________________________________ maestroDlg.cpp
#include "maestroDlg.h"

void maestroDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Maestro";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (maestro_id < 0) return;
		Sys::Format(cmd, L"SELECT nombre, cedula, nss, rfc, domicilio, correo, telefono, usuario_, password_ FROM maestro WHERE maestro_id=%d", maestro_id);
		conn.ExecuteSelect(cmd);
		tbxNombre.MaxTextLength = 60;
		conn.BindColumn(1, tbxNombre, 128);
		tbxCedula.MaxTextLength = 60;
		conn.BindColumn(2, tbxCedula, 128);
		tbxNss.MaxTextLength = 30;
		conn.BindColumn(3, tbxNss, 128);
		tbxRfc.MaxTextLength = 20;
		conn.BindColumn(4, tbxRfc, 128);
		tbxDomicilio.MaxTextLength = 60;
		conn.BindColumn(5, tbxDomicilio, 128);
		tbxCorreo.MaxTextLength = 30;
		conn.BindColumn(6, tbxCorreo, 128);
		tbxTelefono.Number=true;
		conn.BindColumn(7, tbxTelefono, 128);
		tbxUsuario_.MaxTextLength = 15;
		conn.BindColumn(8, tbxUsuario_, 128);
		tbxPassword_.MaxTextLength = 20;
		conn.BindColumn(9, tbxPassword_, 128);
		if (conn.Fetch() == false)
		{
			this->MessageBox(L"No data was returned", L"Error", MB_OK);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
}

void maestroDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	wregex regextbxNombre(L"[A-Za-z0-9]+");
	if (regex_match(tbxNombre.Text, regextbxNombre) == false)
	{
		tbxNombre.ShowBalloonTip(L"Invalid Nombre", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxCedula(L"[A-Za-z0-9]+");
	if (regex_match(tbxCedula.Text, regextbxCedula) == false)
	{
		tbxCedula.ShowBalloonTip(L"Invalid Cedula", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxNss(L"[A-Za-z0-9]+");
	if (regex_match(tbxNss.Text, regextbxNss) == false)
	{
		tbxNss.ShowBalloonTip(L"Invalid Nss", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxRfc(L"[A-Za-z0-9]+");
	if (regex_match(tbxRfc.Text, regextbxRfc) == false)
	{
		tbxRfc.ShowBalloonTip(L"Invalid Rfc", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxDomicilio(L"[A-Za-z0-9]+");
	if (regex_match(tbxDomicilio.Text, regextbxDomicilio) == false)
	{
		tbxDomicilio.ShowBalloonTip(L"Invalid Domicilio", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxCorreo(L"[A-Za-z0-9]+");
	if (regex_match(tbxCorreo.Text, regextbxCorreo) == false)
	{
		tbxCorreo.ShowBalloonTip(L"Invalid Correo", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxUsuario_(L"[A-Za-z0-9]+");
	if (regex_match(tbxUsuario_.Text, regextbxUsuario_) == false)
	{
		tbxUsuario_.ShowBalloonTip(L"Invalid Usuario ", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxPassword_(L"[A-Za-z0-9]+");
	if (regex_match(tbxPassword_.Text, regextbxPassword_) == false)
	{
		tbxPassword_.ShowBalloonTip(L"Invalid Password ", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"maestro", L"maestro_id", maestro_id);
	sb.Bind(L"nombre", tbxNombre);
	sb.Bind(L"cedula", tbxCedula);
	sb.Bind(L"nss", tbxNss);
	sb.Bind(L"rfc", tbxRfc);
	sb.Bind(L"domicilio", tbxDomicilio);
	sb.Bind(L"correo", tbxCorreo);
	sb.Bind(L"telefono", tbxTelefono);
	sb.Bind(L"usuario_", tbxUsuario_);
	sb.Bind(L"password_", tbxPassword_);
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		rows = conn.ExecuteNonQuery(sb.GetString());
		if (rows!=1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of affected rows", MB_OK | MB_ICONERROR);
			return;
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
		return;
	}
	this->EndDialog(TRUE);
}

void maestroDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

