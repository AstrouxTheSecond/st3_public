#include "../Utilities/Globalize.hpp"

namespace Hooks
{ 
	float(__fastcall* get_fieldOfView_org)(DWORD*, DWORD*);
	float __stdcall get_fieldOfView(DWORD* __this, DWORD* method);
}