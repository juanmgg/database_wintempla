#include "stdafx.h"  //_____________________________________________ CalifDlg.cpp
#include "CalifDlg.h"

void CalifDlg::Window_Open(Win::Event& e)
{
	this->Text=L"Calificacion";
	Sql::SqlConnection conn;
	wstring cmd;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		conn.ExecuteSelect(L"SELECT alumno_id, calificacion_id FROM alumno", 100, ddAlumno);
		conn.ExecuteSelect(L"SELECT materia_id, calificacion_id FROM materia", 100, ddMateria);
		conn.ExecuteSelect(L"SELECT maestro_id, calificacion_id FROM maestro", 100, ddMaestro);
		if ( calificacion_id < 0) return;
		Sys::Format(cmd, L"SELECT alumno_id, materia_id, maestro_id, calificacion_1, calificacion_2, calificacion_3 FROM calificacion WHERE =%d", calificacion_id);
		conn.ExecuteSelect(cmd);
		conn.BindColumn(1, ddAlumno);
		conn.BindColumn(2, ddMateria);
		conn.BindColumn(3, ddMaestro);
		conn.BindColumn(4, tbxCalificacion_1, 128);
		conn.BindColumn(5, tbxCalificacion_2, 128);
		conn.BindColumn(6, tbxCalificacion_3, 128);
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

void CalifDlg::btOK_Click(Win::Event& e)
{
	//_____________________________________________________________ Validate
	wregex regexDouble(L"[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?");
	if (regex_match(tbxCalificacion_1.Text, regexDouble) == false)
	{
		tbxCalificacion_1.ShowBalloonTip(L"Invalid Calificacion 1", L"Please provide a floating point value", TTI_ERROR);
		return;
	}
	if (regex_match(tbxCalificacion_2.Text, regexDouble) == false)
	{
		tbxCalificacion_2.ShowBalloonTip(L"Invalid Calificacion 2", L"Please provide a floating point value", TTI_ERROR);
		return;
	}
	if (regex_match(tbxCalificacion_3.Text, regexDouble) == false)
	{
		tbxCalificacion_3.ShowBalloonTip(L"Invalid Calificacion 3", L"Please provide a floating point value", TTI_ERROR);
		return;
	}
	wregex regextbxPromedio(L"[A-Za-z0-9]+");
	if (regex_match(tbxPromedio.Text, regextbxPromedio) == false)
	{
		tbxPromedio.ShowBalloonTip(L"Invalid ", L"Please provide one or more characters", TTI_ERROR);
		return;
	}
	Sql::StringBuilder sb(L"calificacion", L"calificacion_id", calificacion_id);
	sb.Bind(L"alumno_id", ddAlumno);
	sb.Bind(L"materia_id", ddMateria);
	sb.Bind(L"maestro_id", ddMaestro);
	sb.Bind(L"calificacion_1", tbxCalificacion_1);
	sb.Bind(L"calificacion_2", tbxCalificacion_2);
	sb.Bind(L"calificacion_3", tbxCalificacion_3);
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

void CalifDlg::btCancel_Click(Win::Event& e)
{
	this->EndDialog(FALSE);
}

