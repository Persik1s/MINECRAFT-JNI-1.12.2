#define _CRT_SECURE_NO_WARNINGS
#include "include.h"
#include "openGl.hpp"
#include "hook.h"
#include "function.hpp"


JNIEnv* env;
JavaVM* vm;

extern WNDPROC wndProcMinecraft;



DWORD MainThread() {
	bool init = false;

	do {
		if (!init) {
			if (JNI_GetCreatedJavaVMs(&vm, 1, nullptr) != JNI_OK) {
				return 0;
			}
			vm->AttachCurrentThread((void**)&env, nullptr);

			wndProcMinecraft = (WNDPROC)SetWindowLongPtrW(FindWindowA(nullptr, mc->nameWindow), GWLP_WNDPROC, (LONG_PTR)WndProc);
			hook->HookMethode((void*)GetProcAddress(GetModuleHandleA("opengl32.dll"), "wglSwapBuffers"), &openGl::wglSwapBufferMethode, (LPVOID*)&buffer);
			
			init = true;
		}	

		Function::GlowESP();
		//Function::Sprint();
	
	}
	while (1);
}

BOOL WINAPI DllMain(
	HINSTANCE hInstance,
	DWORD fdwReason,
	LPVOID lpReserved
) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
	}

	return TRUE;
}