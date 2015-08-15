#pragma hdrstop
//---------------------------------------------------------------------------

#include "MyAppList.h"
#include "MyTemplates.h"
#include "MyDBConnection.h"
//---------------------------------------------------------------------------

#include <utility>
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

MyAppList::MyAppList()
{
}
//---------------------------------------------------------------------------

MyAppList::MyAppList(const MyAppList &list)
{
	for(vector<TApp*>::const_iterator cit = list.m_vApps.begin(); cit != list.m_vApps.end(); ++cit)
		this->m_vApps.push_back(new TApp(**cit));
}
//---------------------------------------------------------------------------

MyAppList::~MyAppList()
{
	MyTemplates::ClearVector(this->m_vApps);
}
//---------------------------------------------------------------------------

void MyAppList::ReadAllApps(void)
{
	// get a DB-Connection
	pair<TFDConnection*, TFDQuery*> paConnection = MyDBConnection::GetConnection();
	TFDConnection *pConnection = paConnection.first;
	TFDQuery *pQuery = paConnection.second;

	// read all apps
	pQuery->Open("SELECT * FROM app");
	// first
	pQuery->First();

	// as long as ther is data -> create new App-Object and add it to the vector
	while(pQuery->Eof == false)
	{
				int nID = pQuery->FieldByName("id")->AsInteger;
		int nAppTypeID = pQuery->FieldByName("appTypeID")->AsInteger;
		String strAppname = pQuery->FieldByName("appname")->AsString;
		String strProcessname = pQuery->FieldByName("processname")->AsString;
		// Create new TApp object
		TApp *pApp = new TApp(nID, nAppTypeID, strAppname, strProcessname);
		// Add it to the vector
		this->m_vApps.push_back(pApp);
	}

	MyDBConnection::ClearConnection(paConnection);
}
//---------------------------------------------------------------------------
