#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "TDBWriter.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

TDBWriter::TDBWriter()
{

}
//---------------------------------------------------------------------------

TDBWriter::~TDBWriter()
{

}
//---------------------------------------------------------------------------

int TDBWriter::GetNextID(String strTable, TFDConnection *pConnection, TFDQuery *pQuery)
{
	int nID = 0;
	bool bNewConnectionCreated = false;
	pair<TFDConnection*, TFDQuery*> paConnection;

	// If no connection was assigned -> create a new one
	if (pConnection == 0)
	{
		// get a new databaseconnection
		paConnection = MyDBConnection::GetConnection();
		TFDConnection *pConnection = paConnection.first;
		TFDQuery *pQuery = paConnection.second;
		// Set flag
		bNewConnectionCreated = true;
	}

	// Read the data record with the highest id
	pQuery->Open("SELECT id FROM " + strTable + " ORDER BY ID DESC LIMIT 1");

	// If there is no data in the table yet -> ID = 1
	if (pQuery->RecordCount == 0)
		nID = 1;
	// Else get the last ID and increment it by 1
	else
		nID = pQuery->FieldByName("id")->AsInteger + 1;

	// If a new Connection was created -> Clear it
	if (bNewConnectionCreated == true)
		MyDBConnection::ClearConnection(paConnection);
	else
		pQuery->SQL->Clear();
}
//---------------------------------------------------------------------------

int TDBWriter::SaveSingleApp(TApp *pApp)
{
	// get a new Database connection
	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDConnection *pConnection = paConnection.first;
	TFDQuery *pQuery = paConnection.second;

	// If it is a new App
	if (pApp->bNew == true)
	{
		// Get the next ID
		pApp->nID = TDBWriter::GetNextID("app", pConnection, pQuery);
		// Insert Statemant
		String strSQL = "INSERT INTO app VALUES(" + IntToStr(pApp->nID);
		strSQL += ", " + IntToStr(pApp->nAppTypeID);
		strSQL += ", " + QuotedStr(pApp->strAppname);
		strSQL += ", " + QuotedStr(pApp->strProcessname) + ");";
		// Execute the Statement
		pQuery->SQL->Add(strSQL);
		pQuery->ExecSQL();

		// Reset the flag
		pApp->bNew = false;
	}

	// Clear the Database connection
	MyDBConnection::ClearConnection(paConnection);
}
//---------------------------------------------------------------------------

void TDBWriter::DeleteApp(int nAppID)
{
	// Get a new Database connection
	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDConnection *pConnection = paConnection.first;
	TFDQuery *pQuery = paConnection.second;

	pQuery->SQL->Add("DELETE FROM app WHERE ID = " + IntToStr(nAppID) + ";");
	pQuery->ExecSQL();

	// Clear the Database connection
	MyDBConnection::ClearConnection(paConnection);
}
//---------------------------------------------------------------------------
