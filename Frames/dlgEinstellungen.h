#ifndef dlgEinstellungenH
#define dlgEinstellungenH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------

class TFormEinstellungen : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TLayout *layMain;
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TFormEinstellungen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEinstellungen *FormEinstellungen;
//---------------------------------------------------------------------------
#endif
