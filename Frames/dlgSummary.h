#ifndef dlgSummaryH
#define dlgSummaryH
//---------------------------------------------------------------------------

#include "dlgAppStatus.h"
#include "TApp.h"
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class TFormSummary : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layMain;
private:	// Benutzer-Deklarationen
	// Data - Vectors
	std::vector<TApp*> m_vApps;
	std::vector<TFormAppStatus*> m_vFrames;

	// Functions
	void Init(void);

public:		// Benutzer-Deklarationen
	// Constructor, Destructor
	__fastcall TFormSummary(TComponent* Owner);
	__fastcall ~TFormSummary();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSummary *FormSummary;
//---------------------------------------------------------------------------
#endif
