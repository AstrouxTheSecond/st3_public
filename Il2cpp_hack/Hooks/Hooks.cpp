#include "Hooks.hpp"

float __stdcall Hooks::get_fieldOfView(DWORD* __this, DWORD* method)
{
	if (Variables::Hacks::FOVChanger)
		return 120.f;
	else
	    return get_fieldOfView_org(__this, method);
}
