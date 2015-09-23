#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgApps.h"
#include "MyDBConnection.h"
#include "MyTemplates.h"
#include "TDBReader.h"
#include "TDBWriter.h"
#include "dlgEditApp.h"
//---------------------------------------------------------------------------

#include <utility>
#include <memory>
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

TFormApps *FormApps;
//---------------------------------------------------------------------------

__fastcall TFormApps::TFormApps(TComponent* Owner)
	: TForm(Owner)
{
	// Init - Functions
	this->Set();
}
//---------------------------------------------------------------------------

__fastcall TFormApps::~TFormApps()
{
	// clear the vector
	MyTemplates::ClearVector(this->m_vApps);
}
//---------------------------------------------------------------------------

void TFormApps::Set(void)
{
	this->m_vApps = TDBReader::ReadAllApps();

	for(auto pApp : this->m_vApps)
		this->lbApps->Items->AddObject(pApp->strAppname, (TObject*)pApp);
}
//---------------------------------------------------------------------------

void TFormApps::AddApp(TApp *pApp)
{
	// Save the new App
	TDBWriter::SaveSingleApp(pApp);
	// Add the App to the vector
	this->m_vApps.push_back(pApp);
	// And add the App to the ListBox
	this->lbApps->Items->AddObject(pApp->strAppname, (TObject*)pApp);
}
//---------------------------------------------------------------------------

void __fastcall TFormApps::lbAppsItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)
{
	// get the selected item
	TApp *pApp = (TApp*)this->lbApps->Items->Objects[this->lbApps->ItemIndex];

	// fill the edits
	this->edtAppID->Text = pApp->nID;
	this->edtAppTypeID->Text = pApp->nAppTypeID;
	this->edtAppname->Text = pApp->strAppname;
	this->edtProcessname->Text = pApp->strProcessname;
	// hide the labels
	this->lblID->Visible = false;
	this->lblAppTypeID->Visible = false;
	this->lblAppname->Visible = false;
	this->lblProcessname->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormApps::btnAddClick(TObject *Sender)
{
	// Create a new "TApp"-Object
	TApp *pApp = new TApp();

	void (__closure *pAddApp)(TApp*);
	pAddApp = &this->AddApp;

	shared_ptr<TFormEditApp> pFormEditApp(new TFormEditApp(this, pApp, pAddApp));
	pFormEditApp->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFormApps::btnDeleteClick(TObject *Sender)
{
	// Get the selcted item
	TApp *pApp = (TApp*)this->lbApps->Items->Objects[this->lbApps->ItemIndex];

	// Question if Item should really be deleted
	String strQuestion = L"Wollen Sie >> " + pApp->strAppname + L" << wirklich löschen?";
	TModalResult mr = MessageDlg(strQuestion, TMsgDlgType::mtConfirmation, TMsgDlgButtons() << TMsgDlgBtn::mbYes << TMsgDlgBtn::mbNo, 0, TMsgDlgBtn::mbNo);

	// If Yes -> Delete the App from the Database
	if (mr == mrYes)
	{
		TDBWriter::DeleteApp(pApp->nID);
		pApp->bDeleted = true;
		this->lbApps->Items->Delete(this->lbApps->ItemIndex);
	}

	// At last clear the Editfields
	this->edtAppID->Text = "";
	this->lblID->Visible = true;
	this->edtAppname->Text = "";
	this->lblAppname->Visible = true;
	this->edtAppTypeID->Text = "";
	this->lblAppTypeID->Visible = true;
	this->edtProcessname->Text = "";
	this->lblProcessname->Visible = true;
}
//---------------------------------------------------------------------------

