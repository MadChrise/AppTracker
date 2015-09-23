#ifndef TAppH
#define TAppH
//---------------------------------------------------------------------------

class TApp
{
	private:
		// Data
		int m_nID = 0;
		int m_nAppTypeID = 0;
		int m_nSecondsPlayed = 0;
		String m_strAppname = "";
		String m_strProcessname = "";
		String m_strAppType = "";
		//
		bool m_bNew = false;
		bool m_bEdited = false;
		bool m_bDeleted = false;

	public:
		// Constructor, Copyconstructor, Destructor
		TApp();
		TApp(int nID, int nAppTypeID, String strAppname, String strProcessname);
		TApp(const TApp &app);
		~TApp();

		// Properties
		__property bool bNew = { read=m_bNew, write=m_bNew };
		__property bool bEdited = { read=m_bEdited, write=m_bEdited };
		__property bool bDeleted = { read=m_bDeleted, write=m_bDeleted };
		__property int nID = { read=m_nID, write=m_nID };
		__property int nAppTypeID = { read=m_nAppTypeID, write=m_nAppTypeID };
		__property int nSecondsPlayed = { read=m_nSecondsPlayed, write=m_nSecondsPlayed };
		__property String strAppname = { read=m_strAppname, write=m_strAppname };
		__property String strProcessname = { read=m_strProcessname, write=m_strProcessname };
		__property String strAppType = { read=m_strAppType };
};
//---------------------------------------------------------------------------
#endif
