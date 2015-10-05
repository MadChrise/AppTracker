#ifndef dlgSummaryH
#define dlgSummaryH
//---------------------------------------------------------------------------

#include "dlgAppStatus.h"
#include "TApp.h"
#include "TAppType.h"
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class TFormSummary : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layMain;
	TLayout *layFilter;
	TEdit *edtAppname;
	TLabel *lblAppname;
	TComboBox *cbAppType;
	TLabel *lblAppType;
	void __fastcall edtAppnameEnter(TObject *Sender);
	void __fastcall edtAppnameExit(TObject *Sender);
private:	// Benutzer-Deklarationen
	// Data - Vectors
	std::vector<TApp*> m_vApps;
	std::vector<TAppType*> m_vAppTypes;
	std::vector<TFormAppStatus*> m_vFrames;

	// Functions
	void SetComboBoxAppType(void);
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
