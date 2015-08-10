#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgAppTracker.h"
#include "CreateDatabase.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------

TFormAppTracker *FormAppTracker;
//---------------------------------------------------------------------------

__fastcall TFormAppTracker::TFormAppTracker(TComponent* Owner)
	: TForm(Owner)
{
	// Check if "AppTracker.sdb" exists and if not -> Create it
	if (FileExists("AppTracker.sdb") == false)
	{
		CreateDatabase cd;
		cd.Create();
	}
}
//---------------------------------------------------------------------------

__fastcall TFormAppTracker::~TFormAppTracker()
{
}
//---------------------------------------------------------------------------
