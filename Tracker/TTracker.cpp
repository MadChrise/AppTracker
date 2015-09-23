#pragma hdrstop
//---------------------------------------------------------------------------

#include "TTracker.h"
#include "MyTemplates.h"
#include "TDBReader.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

TTracker::TTracker()
{
	// Init - Functions
	this->Init();
}
//---------------------------------------------------------------------------

TTracker::~TTracker()
{
	MyTemplates::ClearVector(this->m_vApps);
}
//---------------------------------------------------------------------------

void TTracker::Init(void)
{
	// When the Tracker is created the Apps to be tracked must be read
	this->m_vApps = TDBReader::ReadAllApps();
}
//---------------------------------------------------------------------------

void TTracker::Start(void)
{

}
//---------------------------------------------------------------------------
