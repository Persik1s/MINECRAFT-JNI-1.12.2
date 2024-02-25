#include "hook.h"

void Hook::HookMethode(LPVOID addresMethode,LPVOID pointerFunc,LPVOID* originalFunction) {
	MH_CreateHook(addresMethode, pointerFunc, originalFunction);
	MH_EnableHook(addresMethode);
}