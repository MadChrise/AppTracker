#pragma hdrstop
//---------------------------------------------------------------------------

#include "MyDBConnection.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

MyDBConnection::MyDBConnection()
{
}
//---------------------------------------------------------------------------

MyDBConnection::~MyDBConnection()
{
}
//---------------------------------------------------------------------------

pair<TFDConnection*, TFDQuery*> MyDBConnection::GetConnection()
{
	TFDConnection *pConnection = new TFDConnection(0);
	pConnection->DriverName = "SQLite";
	pConnection->Params->Database = "AppTracker.sdb";
	TFDQuery *pQuery = new TFDQuery(0);
	pQuery->Connection = pConnection;

	return pair<TFDConnection*, TFDQuery*>(pConnection, pQuery);
}
//---------------------------------------------------------------------------

void MyDBConnection::ClearConnection(TFDConnection *pConnection, TFDQuery *pQuery)
{
	pQuery->Close();
	pConnection->Close();
	delete pQuery;
	delete pConnection;
}
//---------------------------------------------------------------------------
