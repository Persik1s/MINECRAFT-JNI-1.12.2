#pragma once
#include  "include.h"

class Hook
{
public:
	Hook() {
		MH_Initialize();
	}
	~Hook() {
		MH_DisableHook(MH_ALL_HOOKS);
	}

	void HookMethode(LPVOID addresMethode, LPVOID pointerFunc, LPVOID* originalFunction);

};
static Hook* hook = new Hook();

