#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgAppStatus.h"
#include "TDBReader.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------

TFormAppStatus *FormAppStatus;
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

__fastcall TFormAppStatus::TFormAppStatus(TComponent* Owner, TApp *pApp)
	: TForm(Owner)
{
	this->m_pApp = pApp;

	// Init - Functions
	this->Init();
}
//---------------------------------------------------------------------------

__fastcall TFormAppStatus::~TFormAppStatus()
{

}
//---------------------------------------------------------------------------

pair<int, int> TFormAppStatus::GetHoursMinutes(int nSeconds)
{
	int nHours = nSeconds / 60 / 60;
	int nMinutes = nSeconds / 60;

	nMinutes -= (nHours * 60);

	pair<int, int> pa(nHours, nMinutes);

	return pa;
}
//---------------------------------------------------------------------------

void TFormAppStatus::Init(void)
{
	// Read Playtime of the last Session
	int nLastSession = TDBReader::ReadLastSession(this->m_pApp->nID);

	pair<int, int> paLastSession = this->GetHoursMinutes(nLastSession);
	pair<int, int> paOverall = this->GetHoursMinutes(this->m_pApp->nPlayedSeconds);

	this->lblApp->Text = this->m_pApp->strAppname;
	this->lblLastSession->Text = IntToStr(paLastSession.first) + L" Stunden und " + IntToStr(paLastSession.second) + L" Minuten";
	this->lblTimePlayed->Text = IntToStr(paOverall.first) + L" Stunden und " + IntToStr(paOverall.second) + L" Minuten";
}
//---------------------------------------------------------------------------
