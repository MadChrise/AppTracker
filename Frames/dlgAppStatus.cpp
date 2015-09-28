#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgAppStatus.h"
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
	this->lblApp->Text = this->m_pApp->strAppname;
	this->lblTimePlayed->Text = IntToStr(this->m_pApp->nPlayedSeconds / 60 / 60) + L" Stunden gespielt";
}
//---------------------------------------------------------------------------
