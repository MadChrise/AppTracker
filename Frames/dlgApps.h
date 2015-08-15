#ifndef dlgAppsH
#define dlgAppsH
//---------------------------------------------------------------------------

#include "TApp.h"
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class TFormApps : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layMain;
	TListBox *lbApps;
	TEdit *edtAppID;
	TEdit *edtAppTypeID;
	TEdit *edtAppname;
	TEdit *edtProcessname;
	TLabel *lblID;
	TLabel *lblAppname;
	TLabel *lblAppTypeID;
	TLabel *lblProcessname;
	void __fastcall lbAppsItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);

private:	// Benutzer-Deklarationen
	// Data - Vector
	std::vector<TApp*> m_vApps;

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
