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
			for(auto it : vec)
				delete it;

			vec.clear();
		}
};
//---------------------------------------------------------------------------
#endif
