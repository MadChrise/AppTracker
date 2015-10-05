#pragma hdrstop
//---------------------------------------------------------------------------

#include "TDBReader.h"
#include "MyDBConnection.h"
#include "TApp.h"
//---------------------------------------------------------------------------

#include <utility>
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

TDBReader::TDBReader()
{

}
//---------------------------------------------------------------------------

TDBReader::~TDBReader()
{

}
//---------------------------------------------------------------------------

vector<TApp*> TDBReader::ReadAllApps(void)
{
	vector<TApp*> vApps;

	// get a new databaseconnection
	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDConnection *pConnection = paConnection.first;
	TFDQuery *pQuery = paConnection.second;

	// select statement
	String strSQL = "SELECT a.id, a.appTypeID, a.appname, a.processname, SUM(p.playedSeconds) AS playedSeconds";
	strSQL += " FROM app a";
	strSQL += " LEFT OUTER JOIN playtime p ON p.appID = a.id";
	strSQL += " GROUP BY a.id, a.appTypeID, a.appname, a.processname";

	pQuery->Open(strSQL);
	pQuery->First();

	// as long as there is data
	while(pQuery->Eof == false)
	{
		// get the data
		int nID = pQuery->FieldByName("id")->AsInteger;
		int nAppTypeID = pQuery->FieldByName("appTypeID")->AsInteger;
		String strAppname = pQuery->FieldByName("appname")->AsString;
		String strProcessname = pQuery->FieldByName("processname")->AsString;
		int nPlayedSeconds = pQuery->FieldByName("playedSeconds")->AsInteger;

		// create a new Object of type "TApp"
		TApp *pApp = new TApp(nID, nAppTypeID, strAppname, strProcessname, nPlayedSeconds);

		// add the Object to the vector
		vApps.push_back(pApp);

		// next row
		pQuery->Next();
	}

	// close connection
	MyDBConnection::ClearConnection(paConnection);

	// return vector
	return vApps;
}
//---------------------------------------------------------------------------

int TDBReader::ReadLastSession(int nAppID)
{
	int nPlaytime = 0;

	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDConnection *pConnection = paConnection.first;
	TFDQuery *pQuery = paConnection.second;

	String strSQL = "SELECT playedSeconds";
	strSQL += " FROM playtime";
	strSQL += " WHERE appID = " + IntToStr(nAppID);
	strSQL += " ORDER BY id DESC LIMIT 1";

	pQuery->Open(strSQL);
	pQuery->First();

	if (pQuery->Eof == false)
		nPlaytime = pQuery->FieldByName("playedSeconds")->AsInteger;

	return nPlaytime;
}
//---------------------------------------------------------------------------

vector<TAppType*> TDBReader::ReadAllAppTypes(void)
{
	vector<TAppType*> vAppTypes;

	// get a new databaseconnection
	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDConnection *pConnection = paConnection.first;
	TFDQuery *pQuery = paConnection.second;

	// select statement
	pQuery->Open("SELECT * FROM appType ORDER BY name");
	pQuery->First();

	// as long as there is data
	while(pQuery->Eof == false)
	{
		// get the data
		int nID = pQuery->FieldByName("id")->AsInteger;
		String strName = pQuery->FieldByName("name")->AsString;

		// create a new Object of type "TAppType"
		TAppType *pAppType = new TAppType(nID, strName);

		// add the Object to the vector
		vAppTypes.push_back(pAppType);

		// next row
		pQuery->Next();
	}

	// close connection
	MyDBConnection::ClearConnection(paConnection);

	// return vector
	return vAppTypes;
}
//---------------------------------------------------------------------------
