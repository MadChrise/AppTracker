#ifndef MyDBConnectionH
#define MyDBConnectionH
//---------------------------------------------------------------------------

#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.FMXUI.Wait.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
//---------------------------------------------------------------------------

#include <utility>
//---------------------------------------------------------------------------

class MyDBConnection
{
	private:
	public:
		// Constructor + Destructor
		MyDBConnection();
		MyDBConnection(const MyDBConnection&) = delete;
		~MyDBConnection();

		// Function
		static std::pair<TFDConnection*, TFDQuery*> GetConnection(void);
		static void ClearConnection(std::pair<TFDConnection*, TFDQuery*> paConnection);
};
//---------------------------------------------------------------------------
#endif
