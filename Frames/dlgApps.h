#ifndef dlgAppsH
#define dlgAppsH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------

class TFormApps : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layMain;
	TListBox *lbApps;
private:	// Benutzer-Deklarationen
	// Functions
	void Set(void);

public:		// Benutzer-Deklarationen
	// Constructor + Destructor
	__fastcall TFormApps(TComponent* Owner);
	__fastcall ~TFormApps();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormApps *FormApps;
//---------------------------------------------------------------------------
#endif
