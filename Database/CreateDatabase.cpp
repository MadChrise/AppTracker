#pragma hdrstop
//---------------------------------------------------------------------------

#include "CreateDatabase.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

CreateDatabase::CreateDatabase()
	: m_pConnection(new TFDConnection(0)),
	m_pQuery(new TFDQuery(0))
{
	// Init DB Connection
	this->m_pConnection->DriverName = "SQLite";
	this->m_pConnection->Params->Database = "AppTracker.sdb";
	this->m_pQuery->Connection = this->m_pConnection;
}
//---------------------------------------------------------------------------

CreateDatabase::~CreateDatabase()
{
}
//---------------------------------------------------------------------------

void CreateDatabase::CreateTables(void)
{
	String strSQL;

	// Create the required Tables
	// appType (i. e. Game, Production, etc.)
	strSQL = "CREATE TABLE appType(";
	strSQL += "id INTEGER PRIMARY KEY";
	strSQL += ", name varchar(100) NOT NULL);";

	// app
	// holds the name, processname, etc. of the app that should be tracked
	strSQL += "CREATE TABLE app(";
	strSQL += "id INTEGER PRIMARY KEY";
	strSQL += ", appTypeID INTEGER";
	strSQL += ", appname varchar(100) NOT NULL";
	strSQL += ", processname varchar(100) NOT NULL";
	strSQL += ", FOREIGN KEY(appTypeID) REFERENCES appType(id));";

	// playtime
	// stores the "played" time of the apps
	strSQL += "CREATE TABLE playtime(";
	strSQL += "id INTEGER PRIMARY KEY";
	strSQL += ", appID INTEGER NOT NULL";
	strSQL += ", date INTEGER";
	strSQL += ", playedSeconds INTEGER";
	strSQL += ", FOREIGN KEY(appID) REFERENCES app(id));";

	// Insert initial data for appType and app
	strSQL += "INSERT INTO appType VALUES(NULL, 'Spiel');";
	strSQL += "INSERT INTO appType VALUES(NULL, 'Arbeit');";
	strSQL += "INSERT INTO appType VALUES(NULL, 'Sonstiges');";
	strSQL += "INSERT INTO app VALUES(NULL, 2, 'Rad Studio', 'bds.exe');";
	strSQL += "INSERT INTO app VALUES(NULL, 2, 'SQL Server Management Studio', 'Ssms.exe');";
	strSQL += "INSERT INTO app VALUES(NULL, 3, 'Chrome', 'chrome.exe');";
	strSQL += "INSERT INTO app VALUES(NULL, 1, 'World of Tanks', 'WorldOfTanks.exe');";

	// Now create the Database itself
	this->m_pQuery->SQL->Add(strSQL);
	this->m_pQuery->ExecSQL();
	this->m_pQuery->SQL->Clear();
	this->m_pQuery->Close();
	this->m_pConnection->Close();
}
//---------------------------------------------------------------------------

void CreateDatabase::Create(void)
{
	this->CreateTables();
}
//---------------------------------------------------------------------------