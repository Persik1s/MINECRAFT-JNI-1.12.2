#include "include.h"
#include "menu.h"



bool initGL = false;
namespace openGl {
	bool __stdcall wglSwapBufferMethode(HDC hDc) {
		if (!initGL)
		{
			//InitImgui
			ImGui::CreateContext();
			ImGui::StyleColorsDark();
			ImGui_ImplWin32_Init(FindWindow(nullptr, mc->nameWindow));
			ImGui_ImplOpenGL3_Init();
			initGL = true;
		}
		menu->Draw();

		return buffer(hDc);
	}
}