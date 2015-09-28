#ifndef dlgAppStatusH
#define dlgAppStatusH
//---------------------------------------------------------------------------

#include "TApp.h"
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------

class TFormAppStatus : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layMain;
	TLabel *lblApp;
	TLabel *lblTimePlayed;
private:	// Benutzer-Deklarationen
	// Data
	TApp *m_pApp;

	// Functions
	void Init(void);
public:		// Benutzer-Deklarationen
	// Constructor, Destructor
	__fastcall TFormAppStatus(TComponent* Owner, TApp *pApp);
	__fastcall ~TFormAppStatus();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAppStatus *FormAppStatus;
//---------------------------------------------------------------------------
#endif
