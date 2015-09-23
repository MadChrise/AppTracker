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
		// Data - Components
		TMemo *m_pMemo;
		TTimer *m_pTimer = 0;

		// Functions
		void Init(void);
		void Write(TApp *pApp);
		// Functions - Events
		void __fastcall OnTimerTimer(TObject *Sender);

	public:
		// Constructor, Destructor
		TTracker(TMemo *pMemo);
		TTracker(const TTracker &tracker) = delete;
		~TTracker();

		// Functions
		void Start(void);
};
//---------------------------------------------------------------------------
#endif
