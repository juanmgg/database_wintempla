#pragma once  //______________________________________ DBS1.h  
#include "Resource.h"
#include "alumnoDlg.h"
#include "CalifDlg.h"
#include "MaestroDlg.h"
#include "admDlg.h"



#define VIEW_ALUMNO 0
#define VIEW_MAESTRO 1
#define VIEW_ADM 2
#define VIEW_CAL 3

class DBS1: public Win::Dialog
{
public:
	DBS1()
	{
		type_user_alumno = 0;
		type_user_maestro = 0;
		type_user_adm = 0;
		type_user_cal = 0;
	}
	~DBS1()
	{
	}
	//void CreateToolbar();
	void CreateToolbar_alumno();
	void Edit();
	void Delete();
	int type_user_alumno;
	int type_user_maestro;
	int type_user_adm;
	int type_user_cal;
	int alumno_id;
	void RefreshView();
	const wchar_t * GetClassName() { return L"DBS"; }
	
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lvData;
	Win::Tab tabSelection;
	Win::Toolbar toolbMain;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(14.31396);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(11.37708);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"DBS1";
		lvData.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.34396, 4.28625, 13.78479, 6.90563, hWnd, 1000);
		tabSelection.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | TCS_SINGLELINE | TCS_TABS | TCS_RAGGEDRIGHT | TCS_FIXEDWIDTH, 0.34396, 2.77812, 13.73188, 1.58750, hWnd, 1001);
		toolbMain.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | CCS_NORESIZE | CCS_NOPARENTALIGN | CCS_ADJUSTABLE | CCS_NODIVIDER | TBSTYLE_FLAT | TBSTYLE_TOOLTIPS, 0.37042, 1.11125, 13.70542, 1.42875, hWnd, 1002);
		lvData.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lvData.Font = fontArial009A;
		tabSelection.Font = fontArial009A;
	}
	//_________________________________________________
	void lvData_ItemActivate(Win::Event& e);
	void lvData_ItemChanged(Win::Event& e);
	void lvData_KeyDown(Win::Event& e);
	void tabSelection_SelChange(Win::Event& e);
	void Window_Open(Win::Event& e);
	void Window_Paint(Win::Event& e);
	void Cmd_Add(Win::Event& e);
	void Cmd_Copy(Win::Event& e);
	void Cmd_Delete(Win::Event& e);
	void Cmd_Edit(Win::Event& e);
	void Cmd_Msexcel(Win::Event& e);
	void Cmd_Print(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvData.IsEvent(e, LVN_ITEMACTIVATE)) {lvData_ItemActivate(e); return true;}
		if (lvData.IsEvent(e, LVN_ITEMCHANGED)) {lvData_ItemChanged(e); return true;}
		if (lvData.IsEvent(e, LVN_KEYDOWN)) {lvData_KeyDown(e); return true;}
		if (tabSelection.IsEvent(e, TCN_SELCHANGE)) {tabSelection_SelChange(e); return true;}
		if (this->IsEvent(e, IDM_ADD)) {Cmd_Add(e); return true;}
		if (this->IsEvent(e, IDM_COPY)) {Cmd_Copy(e); return true;}
		if (this->IsEvent(e, IDM_DELETE)) {Cmd_Delete(e); return true;}
		if (this->IsEvent(e, IDM_EDIT)) {Cmd_Edit(e); return true;}
		if (this->IsEvent(e, IDM_MSEXCEL)) {Cmd_Msexcel(e); return true;}
		if (this->IsEvent(e, IDM_PRINT)) {Cmd_Print(e); return true;}
		return false;
	}
};
