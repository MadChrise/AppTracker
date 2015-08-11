#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgApps.h"
#include "MyDBConnection.h"
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
}
//---------------------------------------------------------------------------

void TFormApps::Set(void)
{
	// Get Connection
	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDQuery *pQuery = paConnection.second;

	// Read the apps from the app-Table
	pQuery->Open("SELECT appname FROM app");
	// Get first row
	pQuery->First();

	// While there is data
	while(pQuery->Eof == false)
	{
		// Add it to the ListBox
		this->lbApps->Items->Add(pQuery->FieldByName("appname")->AsString);
		// Get next row
		pQuery->Next();
	}

	// Clean Connection
	MyDBConnection::ClearConnection(paConnection);
}
//---------------------------------------------------------------------------
