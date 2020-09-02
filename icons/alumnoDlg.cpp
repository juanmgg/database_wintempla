#include "stdafx.h"  //_____________________________________________ alumnoDlg.cpp
#include "alumnoDlg.h"

void alumnoDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Alumno";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (alumno_id < 0) return;
		Sys::Format(cmd, L"SELECT nombre, curp, sexo, f_nacimiento, domicilio, telefono, correo, usuario, password_ FROM alumno WHERE alumno_id=%d", alumno_id);
		conn.ExecuteSelect(cmd);
		tbxNombre.MaxTextLength = 60;
		conn.BindColumn(1, tbxNombre, 128);
		tbxCurp.MaxTextLength = 25;
		conn.BindColumn(2, tbxCurp, 128);
		tbxSexo.MaxTextLength = 10;
		conn.BindColumn(3, tbxSexo, 128);
		dtboxF_nacimiento.SetFormat(L"MMM dd, yyyy"); 
		conn.BindColumn(4, dtboxF_nacimiento);
		tbxDomicilio.MaxTextLength = 60;
		conn.BindColumn(5, tbxDomicilio, 128);
		tbxTelefono.MaxTextLength = 13;
		conn.BindColumn(6, tbxTelefono, 128);
		tbxCorreo.MaxTextLength = 30;
		conn.BindColumn(7, tbxCorreo, 128);
		tbxUsuario.MaxTextLength = 15;
		conn.BindColumn(8, tbxUsuario, 128);
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

void alumnoDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	wregex regextbxNombre(L"[A-Za-z0-9]+");
	if (regex_match(tbxNombre.Text, regextbxNombre) == false)
	{
		tbxNombre.ShowBalloonTip(L"Invalid Nombre", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxCurp(L"[A-Za-z0-9]+");
	if (regex_match(tbxCurp.Text, regextbxCurp) == false)
	{
		tbxCurp.ShowBalloonTip(L"Invalid Curp", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxSexo(L"[A-Za-z0-9]+");
	if (regex_match(tbxSexo.Text, regextbxSexo) == false)
	{
		tbxSexo.ShowBalloonTip(L"Invalid Sexo", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxDomicilio(L"[A-Za-z0-9]+");
	if (regex_match(tbxDomicilio.Text, regextbxDomicilio) == false)
	{
		tbxDomicilio.ShowBalloonTip(L"Invalid Domicilio", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxTelefono(L"[A-Za-z0-9]+");
	if (regex_match(tbxTelefono.Text, regextbxTelefono) == false)
	{
		tbxTelefono.ShowBalloonTip(L"Invalid Telefono", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxCorreo(L"[A-Za-z0-9]+");
	if (regex_match(tbxCorreo.Text, regextbxCorreo) == false)
	{
		tbxCorreo.ShowBalloonTip(L"Invalid Correo", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxUsuario(L"[A-Za-z0-9]+");
	if (regex_match(tbxUsuario.Text, regextbxUsuario) == false)
	{
		tbxUsuario.ShowBalloonTip(L"Invalid Usuario", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	wregex regextbxPassword_(L"[A-Za-z0-9]+");
	if (regex_match(tbxPassword_.Text, regextbxPassword_) == false)
	{
		tbxPassword_.ShowBalloonTip(L"Invalid Password ", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"alumno", L"alumno_id", alumno_id);
	sb.Bind(L"nombre", tbxNombre);
	sb.Bind(L"curp", tbxCurp);
	sb.Bind(L"sexo", tbxSexo);
	sb.BindMicrosoft(L"f_nacimiento", dtboxF_nacimiento);
	sb.Bind(L"domicilio", tbxDomicilio);
	sb.Bind(L"telefono", tbxTelefono);
	sb.Bind(L"correo", tbxCorreo);
	sb.Bind(L"usuario", tbxUsuario);
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

void alumnoDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

