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
		String m_strAppType;

	public:
		// Constructor, Copyconstructor, Destructor
		TApp(int nID, int nAppTypeID, String strAppname, String strProcessname);
		TApp(const TApp &app);
		~TApp();

		// Properties
		const int nID() { return m_nID; }
		const int nAppTypeID() { return m_nAppTypeID; }
		const String &strAppname() { return m_strAppname; };
		const String &strProcessname() { return m_strProcessname; };
		const String &strAppType() { return m_strAppType; };
};
//---------------------------------------------------------------------------
#endif
