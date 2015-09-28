#ifndef TAppH
#define TAppH
//---------------------------------------------------------------------------

class TApp
{
	private:
		// Data
		int m_nID;
		int m_nAppTypeID;
		String m_strAppname;
		String m_strProcessname;
		int m_nPlayedSecondsSession = 0;
		int m_nPlayedSeconds;
		String m_strAppType = "";
		//
		bool m_bNew = false;
		bool m_bEdited = false;
		bool m_bDeleted = false;

	public:
		// Constructor, Copyconstructor, Destructor
		TApp();
		TApp(int nID, int nAppTypeID, String strAppname, String strProcessname, int nPlayedSeconds = 0);
		TApp(const TApp &app);
		~TApp();

		// Properties
		__property bool bNew = { read=m_bNew, write=m_bNew };
		__property bool bEdited = { read=m_bEdited, write=m_bEdited };
		__property bool bDeleted = { read=m_bDeleted, write=m_bDeleted };
		__property int nID = { read=m_nID, write=m_nID };
		__property int nAppTypeID = { read=m_nAppTypeID, write=m_nAppTypeID };
		__property String strAppname = { read=m_strAppname, write=m_strAppname };
		__property String strProcessname = { read=m_strProcessname, write=m_strProcessname };
		__property int nPlayedSecondsSession = { read=m_nPlayedSecondsSession, write=m_nPlayedSecondsSession };
		__property int nPlayedSeconds = { read=m_nPlayedSeconds };
		__property String strAppType = { read=m_strAppType };
};
//---------------------------------------------------------------------------
#endif
