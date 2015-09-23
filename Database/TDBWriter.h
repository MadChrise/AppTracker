#ifndef TDBWriterH
#define TDBWriterH
//---------------------------------------------------------------------------

#include "MyDBConnection.h"
#include "TApp.h"
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class TDBWriter
{
	private:
	public:
		// Constructor + Destructor
		TDBWriter();
		~TDBWriter();

		// Functions
		static int GetNextID(String strTable, TFDConnection *pConnection = 0, TFDQuery *pQuery = 0);
		static int SaveSingleApp(TApp *pApp);
		static void DeleteApp(int nAppID);
		//
		static void AddPlayedTime(std::vector<TApp*> vApps);
};
//---------------------------------------------------------------------------
#endif
