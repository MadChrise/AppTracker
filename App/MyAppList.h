#ifndef MyAppListH
#define MyAppListH
//---------------------------------------------------------------------------

#include "TApp.h"
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class MyAppList
{
	private:
		// Data - Vector
		std::vector<TApp*> m_vApps;

	public:
		// Constructor, Copyconstructor, Destructor
		MyAppList();
		MyAppList(const MyAppList &list);
		~MyAppList();

		// Functions
		void ReadAllApps(void);
};
//---------------------------------------------------------------------------
#endif
