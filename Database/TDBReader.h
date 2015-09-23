#ifndef TDBReaderH
#define TDBReaderH
//---------------------------------------------------------------------------

#include "TApp.h"
#include "TAppType.h"
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class TDBReader
{
	private:
	public:
		// Constructor + Destructor
		TDBReader();
		~TDBReader();

		// Functions
		static std::vector<TApp*> ReadAllApps(void);
		static std::vector<TAppType*> ReadAllAppTypes(void);
};
//---------------------------------------------------------------------------
#endif
