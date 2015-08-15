#ifndef MyTemplatesH
#define MyTemplatesH
//---------------------------------------------------------------------------

#include <vector>
//---------------------------------------------------------------------------

class MyTemplates
{
	public:
		template<typename T>
		static void ClearVector(std::vector<T*> vec)
		{
			for(typename std::vector<T*>::iterator it = vec.begin(); it != vec.end(); ++it)
				delete (*it);

			vec.clear();
		}
};
//---------------------------------------------------------------------------
#endif
