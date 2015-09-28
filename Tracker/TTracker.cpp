#pragma hdrstop
//---------------------------------------------------------------------------

#include "TTracker.h"
#include "MyTemplates.h"
#include "TDBReader.h"
#include "TDBWriter.h"
//---------------------------------------------------------------------------

#include <TlHelp32.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------

TTracker::TTracker(TMemo *pMemo)
	: m_pMemo(pMemo)
{
	// Init - Functions
	this->Init();
}
//---------------------------------------------------------------------------

TTracker::~TTracker()
{
	TDBWriter::AddPlayedTime(this->m_vApps);
	MyTemplates::ClearVector(this->m_vApps);
	delete this->m_pTimer;
}
//---------------------------------------------------------------------------

void TTracker::Init(void)
{
	// Create a new Timer
	this->m_pTimer = new TTimer(0);
	this->m_pTimer->Enabled = false;
	this->m_pTimer->Interval = 10000;
	this->m_pTimer->OnTimer = this->OnTimerTimer;
	// When the Tracker is created the Apps to be tracked must be read
	this->m_vApps = TDBReader::ReadAllApps();
}
//---------------------------------------------------------------------------

void TTracker::Start(void)
{
	// Just start the Timer
	this->m_pTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TTracker::OnTimerTimer(TObject *Sender)
{
	bool bFound;
	PROCESSENTRY32 process;

	// Create a Snapshot of all running processes
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	for(auto pApp : this->m_vApps)
	{
		Process32First(hSnapshot, &process);

		do
		{
			String strProcess = process.szExeFile;

			// Check if the current process is the one that we search for
			if (strProcess.Trim() == pApp->strProcessname.Trim())
			{
				// If it is -> add the time and break
				pApp->nPlayedSecondsSession += this->m_pTimer->Interval / 1000;
				break;
			}
		}
		while(Process32Next(hSnapshot, &process) == true);
	}

	// Free
	CloseHandle(hSnapshot);

	// Write the new data
	this->m_pMemo->BeginUpdate();
	this->m_pMemo->Lines->Clear();

	for(auto pApp : this->m_vApps)
		this->Write(pApp);

	this->m_pMemo->EndUpdate();
}
//---------------------------------------------------------------------------

void TTracker::Write(TApp *pApp)
{
	this->m_pMemo->Lines->Add(pApp->strAppname + L" läuft seit " + IntToStr(pApp->nPlayedSecondsSession) + L" Sekunden");
}
//---------------------------------------------------------------------------
