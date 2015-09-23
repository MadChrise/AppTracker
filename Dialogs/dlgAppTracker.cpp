#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgAppTracker.h"
#include "CreateDatabase.h"
#include "dlgOptions.h"
//---------------------------------------------------------------------------

#include <memory>
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
	delete this->m_pTracker;
}
//---------------------------------------------------------------------------

void __fastcall TFormAppTracker::miCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormAppTracker::miOptionsClick(TObject *Sender)
{
	// Create the Dialog
	std::unique_ptr<TFormOptions> pFormOptions(new TFormOptions(this));
	// Show it
	pFormOptions->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormAppTracker::tiStartTrackingTimer(TObject *Sender)
{
	// Deactivate the timer
	this->tiStartTracking->Enabled = false;
	// Create a new Instance of TTracker
	this->m_pTracker = new TTracker(this->Memo);
	// And start Tracking
	this->m_pTracker->Start();
}
//---------------------------------------------------------------------------

