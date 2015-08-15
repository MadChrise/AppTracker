#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgApps.h"
#include "MyDBConnection.h"
#include "MyTemplates.h"
//---------------------------------------------------------------------------

#include <utility>
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

TFormApps *FormApps;
//---------------------------------------------------------------------------

__fastcall TFormApps::TFormApps(TComponent* Owner)
	: TForm(Owner)
{
	// Init - Functions
	this->Set();
}
//---------------------------------------------------------------------------

__fastcall TFormApps::~TFormApps()
{
	// clear the vector
	MyTemplates::ClearVector(this->m_vApps);
}
//---------------------------------------------------------------------------

void TFormApps::Set(void)
{
	// Get Connection
	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDQuery *pQuery = paConnection.second;

	// Read the apps from the app-Table
	pQuery->Open("SELECT * FROM app");
	// Get first row
	pQuery->First();

	// While there is data
	while(pQuery->Eof == false)
	{
		// Read data
		int nID = pQuery->FieldByName("id")->AsInteger;
		int nAppTypeID = pQuery->FieldByName("appTypeID")->AsInteger;
		String strAppname = pQuery->FieldByName("appname")->AsString;
		String strProcessname = pQuery->FieldByName("processname")->AsString;
		// Create new TApp object
		TApp *pApp = new TApp(nID, nAppTypeID, strAppname, strProcessname);
		// Add it to the vector
		this->m_vApps.push_back(pApp);

		// add the app object to the listbox
		this->lbApps->Items->AddObject(pApp->strAppname(), (TObject*)pApp);

		// Get next row
		pQuery->Next();
	}

	// Clean Connection
	MyDBConnection::ClearConnection(paConnection);
}
//---------------------------------------------------------------------------

void __fastcall TFormApps::lbAppsItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)
{
	// get the selected item
	TApp *pApp = (TApp*)this->lbApps->Items->Objects[this->lbApps->ItemIndex];

	// fill the edits
	this->edtAppID->Text = pApp->nID();
	this->edtAppTypeID->Text = pApp->nAppTypeID();
	this->edtAppname->Text = pApp->strAppname();
	this->edtProcessname->Text = pApp->strProcessname();
	// hide the labels
	this->lblID->Visible = false;
	this->lblAppTypeID->Visible = false;
	this->lblAppname->Visible = false;
	this->lblProcessname->Visible = false;
}
//---------------------------------------------------------------------------

