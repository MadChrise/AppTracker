#ifndef dlgOptionsH
#define dlgOptionsH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
//---------------------------------------------------------------------------

class TFormOptions : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	// Constructor + Destructor
	__fastcall TFormOptions(TComponent* Owner);
	__fastcall ~TFormOptions();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOptions *FormOptions;
//---------------------------------------------------------------------------
#endif
