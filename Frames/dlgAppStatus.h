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

#include <utility>
//---------------------------------------------------------------------------

class TFormAppStatus : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layMain;
	TLabel *lblApp;
	TLabel *lblTimePlayed;
	TLabel *lblLastSession;
private:	// Benutzer-Deklarationen
	// Data
	TApp *m_pApp;

	// Functions
	std::pair<int, int> GetHoursMinutes(int nSeconds);
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
