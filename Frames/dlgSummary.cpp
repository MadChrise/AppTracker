#include <fmx.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "dlgSummary.h"
#include "MyTemplates.h"
#include "TDBReader.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
//---------------------------------------------------------------------------

TFormSummary *FormSummary;
//---------------------------------------------------------------------------

__fastcall TFormSummary::TFormSummary(TComponent* Owner)
	: TForm(Owner)
{
	// Init - Functions
	this->Init();
}
//---------------------------------------------------------------------------

__fastcall TFormSummary::~TFormSummary()
{
	MyTemplates::ClearVector(this->m_vApps);
	MyTemplates::ClearVector(this->m_vAppTypes);
	MyTemplates::ClearVector(this->m_vFrames);
}
//---------------------------------------------------------------------------

void TFormSummary::SetComboBoxAppType(void)
{
	this->m_vAppTypes = TDBReader::ReadAllAppTypes();

	for(auto pAppType : this->m_vAppTypes)
		this->cbAppType->Items->AddObject(pAppType->strName, (TObject*)pAppType);
}
//---------------------------------------------------------------------------

void TFormSummary::Init(void)
{
	int nCounter = 1, nPosition = this->layFilter->Position->Y + this->layFilter->Height;

	// Fill ComboBox with the AppTypes
	this->SetComboBoxAppType();

	// Read the apps
	this->m_vApps = TDBReader::ReadAllApps();

	for(auto pApp : this->m_vApps)
	{
		TFormAppStatus *pFormAppStatus = new TFormAppStatus(this, pApp);
		pFormAppStatus->Name = "FormAppStatus_" + IntToStr(nCounter++);
		pFormAppStatus->layMain->Parent = this->layMain;
		pFormAppStatus->layMain->Position->Y = nPosition;
		nPosition += pFormAppStatus->layMain->Height;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormSummary::edtAppnameEnter(TObject *Sender)
{
	this->lblAppname->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormSummary::edtAppnameExit(TObject *Sender)
{
	this->lblAppname->Visible = this->edtAppname->Text.Trim() == "" ? true : false;
}
//---------------------------------------------------------------------------

