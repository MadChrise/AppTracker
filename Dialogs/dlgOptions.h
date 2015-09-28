#ifndef dlgOptionsH
#define dlgOptionsH
//---------------------------------------------------------------------------

#include "dlgApps.h"
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------

class TFormOptions : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TTabControl *tcOptions;
	TTabItem *tiApps;
	TTabItem *tiEinstellungen;
private:	// Benutzer-Deklarationen
	// Data - "Frames"
	TFormApps *m_pFormApps = 0;

	// Functions
	void SetFrames(void);

public:		// Benutzer-Deklarationen
	// Constructor + Destructor
	__fastcall TFormOptions(TComponent* Owner);
	__fastcall ~TFormOptions();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOptions *FormOptions;
//---------------------------------------------------------------------------
#endif
