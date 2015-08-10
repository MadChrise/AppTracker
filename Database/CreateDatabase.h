#ifndef CreateDatabaseH
#define CreateDatabaseH
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

class CreateDatabase
{
	private:
		// Data
		TFDConnection *m_pConnection;
		TFDQuery *m_pQuery;
	
		// Functions
		void CreateTables(void);
		
	public:
		// Constructor, Copyconstructor, Destructor
		CreateDatabase();
		CreateDatabase(const CreateDatabase &) = delete;
		~CreateDatabase();

		// Functions
		void Create(void);
};
//---------------------------------------------------------------------------
#endif
