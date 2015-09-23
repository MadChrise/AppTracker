#ifndef TTrackerH
#define TTrackerH
//---------------------------------------------------------------------------

#include <TApp.h>
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class TTracker
{
	private:
		// Data - vectors
		std::vector<TApp*> m_vApps;

		// Functions
		void Init(void);

	public:
		// Constructor, Destructor
		TTracker();
		TTracker(const TTracker &tracker) = delete;
		~TTracker();

		// Functions
		void Start(void);
};
//---------------------------------------------------------------------------
#endif
