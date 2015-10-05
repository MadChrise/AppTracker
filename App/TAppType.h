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
		__property int nID = { read=m_nID };
		__property String strName = { read=m_strName };
};
//---------------------------------------------------------------------------
#endif
