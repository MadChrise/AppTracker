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

void TFormAppStatus::Init(void)
{
	// Read Playtime of the last Session
	int nLastSession = TDBReader::ReadLastSession(this->m_pApp->nID);

	this->lblApp->Text = this->m_pApp->strAppname;
	this->lblLastSession->Text = IntToStr(nLastSession / 60 / 60) + L" Stunden";
	this->lblTimePlayed->Text = IntToStr(this->m_pApp->nPlayedSeconds / 60 / 60) + L" Stunden";
}
//---------------------------------------------------------------------------
