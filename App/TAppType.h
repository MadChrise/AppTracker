#ifndef TAppTypeH
#define TAppTypeH
//---------------------------------------------------------------------------

class TAppType
{
	private:
		// Data
		int m_nID;
		String m_strName;

	public:
		// Constructor, Copyconstructor, Destructor
		TAppType(int nID, String strName);
		TAppType(const TAppType &appType);
		~TAppType();

		// Properties
		const int nID() { return m_nID; };
		const String strName() { return m_strName; };
};
//---------------------------------------------------------------------------
#endif
