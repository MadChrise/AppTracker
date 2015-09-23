//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Dialogs\dlgEditApp.cpp", FormEditApp);
USEFORM("Dialogs\dlgAppTracker.cpp", FormAppTracker);
USEFORM("Frames\dlgApps.cpp", FormApps);
USEFORM("Dialogs\dlgOptions.cpp", FormOptions);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TFormAppTracker), &FormAppTracker);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
