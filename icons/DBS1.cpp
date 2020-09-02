#include "stdafx.h"  //________________________________________ DBS1.cpp
#include "DBS1.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	DBS1 app;
	return app.BeginDialog(IDI_DBS1, hInstance);
}

void DBS1::Window_Open(Win::Event& e)
{
	//________________________________________________________ lvData
	//lvData.Cols.Add(0, LVCFMT_LEFT, 100, L"Day");
	//lvData.Cols.Add(1, LVCFMT_RIGHT, 200, L"Activity");
	//lvData.Items.Add(0, L"Monday");
	//lvData.Items[0][1].Text = L"Math Class";
	//________________________________________________________ tabSelection
	//tabSelection.Items.Add(0, L"First Tab");
	//tabSelection.Items.Add(1, L"Second Tab");
	//________________________________________________________ toolbMain
	TBBUTTON tbButton[9];//<< EDIT HERE THE NUMBER OF BUTTONS

	int iconSizes[] ={16, 20, 24, 32, 40, 48, 64};
	const int pixelsIconSize = Sys::Metrics::GetBestIconSize(iconSizes, 7, Sys::Convert::CentimetersToScreenPixels(0.42333));
	const int pixelsButtonSize = pixelsIconSize + Sys::Convert::CentimetersToScreenPixels(0.1);
	toolbMain.imageList.Create(pixelsIconSize, pixelsIconSize, 7);//<< EDIT HERE THE NUMBER OF IMAGES
	toolbMain.imageList.AddIcon(this->hInstance, IDI_SAVE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_COPY);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_ADD);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_EDIT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_DELETE);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_PRINT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_MSEXCEL);
	toolbMain.SendMessage(TB_BUTTONSTRUCTSIZE, (WPARAM)(int)sizeof(TBBUTTON), 0); 
	toolbMain.SetImageList(toolbMain.imageList);
	//_____________________________________
	tbButton[0].iBitmap=MAKELONG(0, 0); //<< IMAGE INDEX
	tbButton[0].idCommand=IDM_SAVE;
	tbButton[0].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[0].fsStyle=BTNS_BUTTON;
	tbButton[0].dwData=0L; 
	tbButton[0].iString= (LONG_PTR)L"Save";
	//________________________ A separator
	tbButton[1].iBitmap=-1;
	tbButton[1].idCommand=0;  
	tbButton[1].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[1].fsStyle=BTNS_SEP;  
	tbButton[1].dwData=0L;  
	tbButton[1].iString=0;  
	//_____________________________________
	tbButton[2].iBitmap=MAKELONG(1, 0); //<< IMAGE INDEX
	tbButton[2].idCommand=IDM_COPY;
	tbButton[2].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[2].fsStyle=BTNS_BUTTON;
	tbButton[2].dwData=0L; 
	tbButton[2].iString= (LONG_PTR)L"Copy";
	//_____________________________________
	tbButton[3].iBitmap=MAKELONG(2, 0); //<< IMAGE INDEX
	tbButton[3].idCommand=IDM_ADD;
	tbButton[3].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[3].fsStyle=BTNS_BUTTON;
	tbButton[3].dwData=0L; 
	tbButton[3].iString= (LONG_PTR)L"Add";
	//_____________________________________
	tbButton[4].iBitmap=MAKELONG(3, 0); //<< IMAGE INDEX
	tbButton[4].idCommand=IDM_EDIT;
	tbButton[4].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[4].fsStyle=BTNS_BUTTON;
	tbButton[4].dwData=0L; 
	tbButton[4].iString= (LONG_PTR)L"Edit";
	//_____________________________________
	tbButton[5].iBitmap=MAKELONG(4, 0); //<< IMAGE INDEX
	tbButton[5].idCommand=IDM_DELETE;
	tbButton[5].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[5].fsStyle=BTNS_BUTTON;
	tbButton[5].dwData=0L; 
	tbButton[5].iString= (LONG_PTR)L"Delete";
	//________________________ A separator
	tbButton[6].iBitmap=-1;
	tbButton[6].idCommand=0;  
	tbButton[6].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[6].fsStyle=BTNS_SEP;  
	tbButton[6].dwData=0L;  
	tbButton[6].iString=0;  
	//_____________________________________
	tbButton[7].iBitmap=MAKELONG(5, 0); //<< IMAGE INDEX
	tbButton[7].idCommand=IDM_PRINT;
	tbButton[7].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[7].fsStyle=BTNS_BUTTON;
	tbButton[7].dwData=0L; 
	tbButton[7].iString= (LONG_PTR)L"Print";
	//_____________________________________
	tbButton[8].iBitmap=MAKELONG(6, 0); //<< IMAGE INDEX
	tbButton[8].idCommand=IDM_MSEXCEL;
	tbButton[8].fsState=TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[8].fsStyle=BTNS_BUTTON;
	tbButton[8].dwData=0L; 
	tbButton[8].iString= (LONG_PTR)L"Export to Microsoft Excel";

	toolbMain.SetBitmapSize(pixelsIconSize, pixelsIconSize);
	toolbMain.SetButtonSize(pixelsButtonSize, pixelsButtonSize);
	toolbMain.AddButtons(tbButton, 9);// << EDIT HERE THE NUMBER OF BUTTONS
	toolbMain.SendMessage(TB_AUTOSIZE, 0, 0);
	toolbMain.SetMaxTextRows(0);// EDIT HERE TO DISPLAY THE BUTTON TEXT
	toolbMain.Show(SW_SHOWNORMAL);
//	toolbMain.ResizeToFit();


	wstring cmd;
	//Sys::Format(sqlCmd, L"SELECT type_user_maestro FROM maestro WHERE usuario=\'%s\'", dlg.tbxUsername.Text.c_str());
	//Sys::Format(cmd, L"SELECT type_user_alumno FROM alumno WHERE usuario=\'%s\' AND password_ = \'%s\'", dlg.tbxUsername.Text.c_str(), dlg.tbxPassword.Text.c_str());

	//Sys::Format(cmd, L"SELECT type_user_alumno FROM alumno WHERE usuario =\'%s\' AND password_ = \'%s\'", dlg.tbxUsername.Text.c_str(), dlg.tbxPassword.Text.c_str());
	/*alumno_id = conn.GetInt(cmd);
	EndDialog(TRUE);
	return;*/

	Sql::SqlConnection conn;
	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		type_user_alumno = conn.GetInt(cmd);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
	}


	/*
	wstring cmd1;
	//Sys::Format(Cmd, L"SELECT type_user_alumno FROM alumno WHERE usuario=\'%s\'", dlg.tbxUsername.Text.c_str());
	Sys::Format(cmd1, L"SELECT type_user_maestro FROM maestro WHERE usuario_=\'%s\'", dlg.tbxUsername.Text.c_str());
	//Sql::SqlConnection conn;
	try {
		conn.OpenSession(hWnd, CONNECTION_STRING);
		type_user_maestro = conn.GetInt(cmd1);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
	}
	*/


	//wstring Cmd1;
	////Sys::Format(Cmd, L"SELECT type_user_alumno FROM alumno WHERE usuario=\'%s\'", dlg.tbxUsername.Text.c_str());
	//Sys::Format(Cmd1, L"SELECT type_user_adm FROM administrador WHERE usuario=\'%s\'", dlg.tbxUsername.Text.c_str());
	//Sql::SqlConnection conn;
	//try {
	//	conn.OpenSession(hWnd, CONNECTION_STRING);
	//	type_user_adm = conn.GetInt(Cmd1);
	//}
	//catch (Sql::SqlException e)
	//{
	//	this->MessageBox(e.GetDescription(), L"ERROR", MB_OK | MB_ICONERROR);
	//}
	//



	//vistas para cada usuario
	if (type_user_alumno == 1)
	{
		CreateToolbar_alumno();
		tabSelection.Items.Add(0, L"Calificacion", VIEW_CAL);

	}
	else if (type_user_maestro == 2)
	{

		tabSelection.Items.Add(1, L"Maestro", VIEW_CAL);

	}
	else if (type_user_adm == 3)
	{

		tabSelection.Items.Add(0, L"Alumno", VIEW_ALUMNO);
		tabSelection.Items.Add(1, L"Maestro", VIEW_MAESTRO);
		tabSelection.Items.Add(2, L"Administradores", VIEW_ADM);
		//tabSelection.Items.Add(3, L"Calificacion", VIEW_CAL);

	}
	else
	{

		tabSelection.Items.Add(0, L"Alumno", VIEW_ALUMNO);
		tabSelection.Items.Add(1, L"Maestro", VIEW_MAESTRO);
		tabSelection.Items.Add(2, L"Administradores", VIEW_ADM);
		tabSelection.Items.Add(3, L"Calificacion", VIEW_CAL);
	}

	RefreshView();
}

void DBS1::Cmd_Add(Win::Event& e)
{
	const int view = tabSelection.SelectedData;
	if (view == VIEW_ALUMNO)
	{
		alumnoDlg dlg;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
	else if (view == VIEW_MAESTRO)
	{
		maestroDlg dlg;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
	else if (view == VIEW_ADM)
	{
		admDlg dlg;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
	else if (view == VIEW_CAL)
	{
		CalifDlg dlg;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
}

void DBS1::RefreshView()
{
	Win::HourGlassCursor hgc(true);
	this->toolbMain.EnableButton(IDM_DELETE, false);
	lvData.SetRedraw(false);
	const int view = tabSelection.SelectedData;

	//________________________________________________ Columns
	lvData.Cols.DeleteAll();
	switch (view)
	{
	case VIEW_ALUMNO:
		lvData.Cols.Add(0, LVCFMT_LEFT, 160, L"Nombre");
		lvData.Cols.Add(1, LVCFMT_LEFT, 160, L"Curp");
		lvData.Cols.Add(2, LVCFMT_LEFT, 160, L"Sexo");
		lvData.Cols.Add(3, LVCFMT_LEFT, 160, L"Fecha");
		lvData.Cols.Add(4, LVCFMT_LEFT, 160, L"Domicilio");
		lvData.Cols.Add(5, LVCFMT_LEFT, 160, L"Telefono");
		lvData.Cols.Add(6, LVCFMT_LEFT, 160, L"Correo");
		lvData.Cols.Add(7, LVCFMT_LEFT, 160, L"Usuario");
		lvData.Cols.Add(8, LVCFMT_LEFT, 160, L"Contraseña");
		lvData.Cols.Add(9, LVCFMT_LEFT, 120, L"type_user");
		break;
	case VIEW_MAESTRO:
		lvData.Cols.Add(0, LVCFMT_LEFT, 150, L"Nombre");
		lvData.Cols.Add(1, LVCFMT_LEFT, 150, L"Cedula");
		lvData.Cols.Add(2, LVCFMT_LEFT, 150, L"NSS");
		lvData.Cols.Add(3, LVCFMT_LEFT, 150, L"RFC");
		lvData.Cols.Add(4, LVCFMT_LEFT, 150, L"Domicilio");
		lvData.Cols.Add(5, LVCFMT_LEFT, 150, L"Correo");
		lvData.Cols.Add(6, LVCFMT_LEFT, 150, L"Telefono");
		lvData.Cols.Add(7, LVCFMT_LEFT, 150, L"Usuario");
		lvData.Cols.Add(8, LVCFMT_LEFT, 150, L"Contraseña");
		lvData.Cols.Add(9, LVCFMT_LEFT, 120, L"type_user");
		break;
	case VIEW_ADM:
		lvData.Cols.Add(0, LVCFMT_LEFT, 150, L"Nombre");
		lvData.Cols.Add(1, LVCFMT_LEFT, 150, L"Cedula");
		lvData.Cols.Add(2, LVCFMT_LEFT, 150, L"NSS");
		lvData.Cols.Add(3, LVCFMT_LEFT, 150, L"RFC");
		lvData.Cols.Add(4, LVCFMT_LEFT, 150, L"Domicilio");
		lvData.Cols.Add(5, LVCFMT_LEFT, 150, L"Correo");
		lvData.Cols.Add(6, LVCFMT_LEFT, 150, L"Telefono");
		lvData.Cols.Add(7, LVCFMT_LEFT, 150, L"Usuario");
		lvData.Cols.Add(8, LVCFMT_LEFT, 150, L"Contraseña");
		lvData.Cols.Add(9, LVCFMT_LEFT, 120, L"type_user");
		break;
	case VIEW_CAL:
		lvData.Cols.Add(0, LVCFMT_LEFT, 150, L"Alumno");
		lvData.Cols.Add(1, LVCFMT_LEFT, 150, L"Materia");
		lvData.Cols.Add(2, LVCFMT_LEFT, 150, L"Maestro");
		lvData.Cols.Add(3, LVCFMT_LEFT, 150, L"Parcial_1");
		lvData.Cols.Add(4, LVCFMT_LEFT, 150, L"Parcial_2");
		lvData.Cols.Add(5, LVCFMT_LEFT, 150, L"Parcial_3");
		lvData.Cols.Add(6, LVCFMT_LEFT, 150, L"Promedio");
		break;
	}
	//________________________________________________ Items
	lvData.Items.DeleteAll();
	wstring text;
	switch (view)
	{
	case VIEW_ALUMNO:
		text = L"SELECT alumno_id, nombre, curp, sexo, f_nacimiento, domicilio, telefono, correo, usuario, password_, type_user_alumno FROM alumno";
		break;
	case VIEW_MAESTRO:
		text = L"SELECT maestro_id, nombre, cedula, nss, rfc, domicilio, correo, telefono, usuario_, password_, type_user_maestro FROM maestro";
		break;
	case VIEW_ADM:
		text = L"SELECT administrador_id, nombre, cedula, nss, rfc, domicilio, correo, telefono, usuario, password_, type_user_adm FROM administrador";
		break;
	case VIEW_CAL:
		//text = L"SELECT Nombre, Materia, Maestro, Parcial_1, Parcial_2, Parcial_3, Promedio FROM vw_calificacion";
		text = L"SELECT calificacion_id, a.nombre as Nombre,ma.nombre as Materia,m.nombre as Maestro,c.calificacion_1 as Parcial_1,c.calificacion_2 as Parcial_2,c.calificacion_3 as Parcial_3,c.promedio as Promedio FROM calificacion c, alumno a, maestro m, materia ma WHERE a.alumno_id = c.alumno_id and c.materia_id = ma.materia_id and c.maestro_id = m.maestro_id";
		break;

	}

	if (text.empty() == true)
	{
		lvData.SetRedraw(true);
		return;
	}
	Sql::SqlConnection conn;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		conn.ExecuteSelect(text.c_str(), 100, lvData);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	lvData.SetRedraw(true);
}

void DBS1::Cmd_Delete(Win::Event& e)
{
	Delete();
}

void DBS1::Cmd_Edit(Win::Event& e)
{
	Edit();
}

void DBS1::Cmd_Copy(Win::Event& e)
{
	lvData.CopyToClipboard();
}

void DBS1::Cmd_Msexcel(Win::Event& e)
{
	Win::FileDlg dlg;
	dlg.Clear();
	dlg.SetFilter(L"MS Excel files (*.xlsx)\0*.xlsx\0\0", 0, L"xlsx");
	if (dlg.BeginDialog(hWnd, L"Save", true))
	{
		lvData.ExportToMsExcel(dlg.GetFileNameFullPath());
	}
}

void DBS1::Cmd_Print(Win::Event& e)
{
	lvData.Print();
}

void DBS1::tabSelection_SelChange(Win::Event& e)
{
	toolbMain.EnableButton(IDM_DELETE, lvData.GetSelectedCount() == 1);
}

void DBS1::lvData_ItemActivate(Win::Event& e)
{
	Edit();
}

void DBS1::lvData_ItemChanged(Win::Event& e)
{
	RefreshView();
}

void DBS1::lvData_KeyDown(Win::Event& e)
{
	LPNMLVKEYDOWN p = (LPNMLVKEYDOWN) e.lParam;
	if (p->wVKey == VK_DELETE)
	{
	}
}



void DBS1::Window_Paint(Win::Event& e)
{
	CG::Gdi gdi(hWnd, true, false);
}

void DBS1::Edit()
{
	const int view = tabSelection.SelectedData;
	//_______________________________________________________ Extract id from list view control
	const int index = lvData.GetSelectedIndex();
	if (index < 0) return;
	const int id = lvData.Items[index].Data;

	if (view == VIEW_ALUMNO)
	{
		alumnoDlg dlg;
		dlg.alumno_id = id;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
	else if (view == VIEW_MAESTRO)
	{
		maestroDlg dlg;
		dlg.maestro_id = id;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
	else if (view == VIEW_ADM)
	{
		admDlg dlg;
		dlg.administrador_id = id;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
	else if (view == VIEW_CAL)
	{
		CalifDlg dlg;
		dlg.calificacion_id = id;
		if (dlg.BeginDialog(hWnd) == TRUE)
		{
			RefreshView();
		}
	}
}

void DBS1::Delete()
{
	if (this->MessageBox(L"Are you sure?", L"DBS", MB_YESNO | MB_ICONQUESTION) != IDYES) return;

	const int view = tabSelection.SelectedData;

	//_______________________________________________________ Extract id from lvData
	const int index = lvData.GetSelectedIndex();
	if (index < 0) return;
	const int id = lvData.Items[index].Data;

	Sql::SqlConnection conn;
	wstring cmd;
	int rows = 0;

	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(hWnd, CONNECTION_STRING);
		if (view == VIEW_ALUMNO)
		{
			Sys::Format(cmd, L"DELETE FROM alumno WHERE alumno_id=%d", id);
		}
		else if (view == VIEW_MAESTRO)
		{
			Sys::Format(cmd, L"DELETE FROM maestro WHERE maestro_id=%d", id);
		}
		else if (view == VIEW_ADM)
		{
			Sys::Format(cmd, L"DELETE FROM administrador WHERE administrador_id=%d", id);
		}
		else if (view == VIEW_CAL)
		{
			Sys::Format(cmd, L"DELETE FROM calificacion WHERE calificacion_id=%d", id);
		}

		rows = conn.ExecuteNonQuery(cmd);
		if (rows != 1)
		{
			this->MessageBox(L"Edit Here", L"DBS", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"DBS", MB_OK | MB_ICONERROR);
	}
	RefreshView();
}


void DBS1::CreateToolbar_alumno()
{
	int i = 0;
	//________________________________________________________ toolbMain
	TBBUTTON tbButton[10];//<< EDIT HERE THE NUMBER OF BUTTONS
	int iconSizes[] = { 16, 20, 24, 32, 40, 48, 64 };
	const int pixelsIconSize = Sys::Metrics::GetBestIconSize(iconSizes, 7, Sys::Convert::CentimetersToScreenPixels(0.42333));
	const int pixelsButtonSize = pixelsIconSize + Sys::Convert::CentimetersToScreenPixels(0.1);

	toolbMain.imageList.Create(pixelsIconSize, pixelsIconSize, 8);//<< EDIT HERE THE NUMBER OF IMAGES															
	toolbMain.imageList.AddIcon(this->hInstance, IDI_COPY);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_PRINT);
	toolbMain.imageList.AddIcon(this->hInstance, IDI_MSEXCEL);
	toolbMain.SendMessage(TB_BUTTONSTRUCTSIZE, (WPARAM)(int)sizeof(TBBUTTON), 0);
	toolbMain.SetImageList(toolbMain.imageList);
	//_____________________________________
	tbButton[i].iBitmap = MAKELONG(0, 0); //<< IMAGE INDEX
	tbButton[i].idCommand = IDM_COPY;
	tbButton[i].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[i].fsStyle = BTNS_BUTTON;
	tbButton[i].dwData = 0L;
	tbButton[i++].iString = (LONG_PTR)L"Copy";
	//________________________ A separator
	tbButton[i].iBitmap = -1;
	tbButton[i].idCommand = 0;
	tbButton[i].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[i].fsStyle = BTNS_SEP;
	tbButton[i].dwData = 0L;
	tbButton[i++].iString = 0;
	//_____________________________________
	tbButton[i].iBitmap = MAKELONG(1, 0); //<< IMAGE INDEX
	tbButton[i].idCommand = IDM_PRINT;
	tbButton[i].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[i].fsStyle = BTNS_BUTTON;
	tbButton[i].dwData = 0L;
	tbButton[i++].iString = (LONG_PTR)L"Print";
	//_____________________________________
	tbButton[i].iBitmap = MAKELONG(2, 0); //<< IMAGE INDEX
	tbButton[i].idCommand = IDM_MSEXCEL;
	tbButton[i].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[i].fsStyle = BTNS_BUTTON;
	tbButton[i].dwData = 0L;
	tbButton[i++].iString = (LONG_PTR)L"Export to Microsoft Excel";
	//________________________ A separator
	tbButton[i].iBitmap = -1;
	tbButton[i].idCommand = 0;
	tbButton[i].fsState = TBSTATE_ENABLED; // | TBSTATE_WRAP
	tbButton[i].fsStyle = BTNS_SEP;
	tbButton[i].dwData = 0L;
	tbButton[i++].iString = 0;
	//_____________________________________
	toolbMain.SetBitmapSize(pixelsIconSize, pixelsIconSize);
	toolbMain.SetButtonSize(pixelsButtonSize, pixelsButtonSize);
	toolbMain.AddButtons(tbButton, i);// << EDIT HERE THE NUMBER OF BUTTONS
	toolbMain.SendMessage(TB_AUTOSIZE, 0, 0);
	toolbMain.SetMaxTextRows(0);// EDIT HERE TO DISPLAY THE BUTTON TEXT
	toolbMain.Show(SW_SHOWNORMAL);
}


