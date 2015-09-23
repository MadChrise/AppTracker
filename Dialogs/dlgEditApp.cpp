#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgEditApp.h"
#include "MyTemplates.h"
#include "TDBReader.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------

TFormEditApp *FormEditApp;
//---------------------------------------------------------------------------

using namespace std;
//---------------------------------------------------------------------------

__fastcall TFormEditApp::TFormEditApp(TComponent* Owner, TApp *pApp, void (__closure* pAddApp)(TApp*))
	: TForm(Owner)
{
	this->m_pApp = pApp;
	this->m_pAddApp = pAddApp;

	// Init - Functions
	this->Set();
}
//---------------------------------------------------------------------------

__fastcall TFormEditApp::~TFormEditApp()
{
	MyTemplates::ClearVector(this->m_vAppTypes);
}
//---------------------------------------------------------------------------

void TFormEditApp::Set(void)
{
	// First -> Read the AppTypes
	this->m_vAppTypes = TDBReader::ReadAllAppTypes();

	// Fill ComboBox
	this->SetComboBoxAppType();
}
//---------------------------------------------------------------------------

void TFormEditApp::SetComboBoxAppType(void)
{
	// First the ComboBox is cleared
	this->cbAppType->Clear();

	// Fill the ComboBox with the AppTypes
	for(auto pAppType : this->m_vAppTypes)
		this->cbAppType->Items->AddObject(pAppType->strName(), (TObject*)pAppType);

	// Select the first Item of the ComboBox
	this->cbAppType->ItemIndex = 0;
}
//---------------------------------------------------------------------------

bool TFormEditApp::CheckRequiredFields(void)
{
	if (this->edtAppname->Text.Trim() == "")
	{
		ShowMessage("Appname ist ein Pflichtfeld!");
		return false;
	}
	if (this->edtProcessname->Text.Trim() == "")
	{
		ShowMessage("Prozessname ist ein Pflichtfeld!");
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------

void TFormEditApp::Get(void)
{
	// Get the needed data
	this->m_pApp->strAppname = this->edtAppname->Text.Trim();
	this->m_pApp->strProcessname = this->edtProcessname->Text.Trim();
	this->m_pApp->nAppTypeID = ((TAppType*)this->cbAppType->Items->Objects[this->cbAppType->ItemIndex])->nID();
	// and Save the new App
	this->m_pAddApp(this->m_pApp);
}
//---------------------------------------------------------------------------

void __fastcall TFormEditApp::btnUebernehmenClick(TObject *Sender)
{
	// Check if all required fields are filled
	if (this->CheckRequiredFields() == true)
	{
		// Get the data, save the new Object
		this->Get();
		// Clear the fields
		this->edtAppname->Text = "";
		this->edtProcessname->Text = "";
		// And create a new TApp-Object
		this->m_pApp = new TApp();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEditApp::btnOkClick(TObject *Sender)
{
	// Check if all required fields are filled
	if (this->CheckRequiredFields() == true)
	{
		// Get the data, save the new Object
		this->Get();
		// ModalResult
		this->ModalResult = mrOk;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormEditApp::btnAbbrechenClick(TObject *Sender)
{
	this->ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

