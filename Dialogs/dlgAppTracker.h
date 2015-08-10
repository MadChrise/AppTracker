#ifndef dlgAppTrackerH
#define dlgAppTrackerH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
//---------------------------------------------------------------------------

class TFormAppTracker : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	// Constructor + Destructor
	__fastcall TFormAppTracker(TComponent* Owner);
	__fastcall ~TFormAppTracker();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAppTracker *FormAppTracker;
//---------------------------------------------------------------------------
#endif
