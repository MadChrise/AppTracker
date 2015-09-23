#ifndef dlgEditAppH
#define dlgEditAppH
//---------------------------------------------------------------------------

#include "TApp.h"
#include "TAppType.h"
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class TFormEditApp : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layOk;
	TButton *btnAbbrechen;
	TButton *btnOk;
	TButton *btnUebernehmen;
	TComboBox *cbAppType;
	TLabel *lblTyp;
	TEdit *edtAppname;
	TEdit *edtProcessname;
	TLabel *lblAppname;
	TLabel *lblProcessname;
	void __fastcall btnUebernehmenClick(TObject *Sender);
	void __fastcall btnOkClick(TObject *Sender);
	void __fastcall btnAbbrechenClick(TObject *Sender);
private:	// Benutzer-Deklarationen
	// Data
	TApp *m_pApp;
	// Data - Vector
	std::vector<TAppType*> m_vAppTypes;
	// Data - Function pointers
	void (__closure* m_pAddApp)(TApp*);

	// Functions
	void Set(void);
	void SetComboBoxAppType(void);
	bool CheckRequiredFields(void);
	void Get(void);

public:		// Benutzer-Deklarationen
	// Constructor + Destructor
	__fastcall TFormEditApp(TComponent* Owner, TApp *pApp, void (__closure* pAddApp)(TApp*));
	__fastcall ~TFormEditApp();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditApp *FormEditApp;
//---------------------------------------------------------------------------
#endif
