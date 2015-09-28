#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgOptions.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------

TFormOptions *FormOptions;
//---------------------------------------------------------------------------

__fastcall TFormOptions::TFormOptions(TComponent* Owner)
	: TForm(Owner)
{
	// Init - Functions
	this->SetFrames();
}
//---------------------------------------------------------------------------

__fastcall TFormOptions::~TFormOptions()
{
	delete this->m_pFormApps;
}
//---------------------------------------------------------------------------

void TFormOptions::SetFrames(void)
{
	// Apps
	this->m_pFormApps = new TFormApps(this);
	this->m_pFormApps->layMain->Parent = this->tiApps;
}
//---------------------------------------------------------------------------
