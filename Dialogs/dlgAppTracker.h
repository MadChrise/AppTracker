#ifndef dlgAppTrackerH
#define dlgAppTrackerH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
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
