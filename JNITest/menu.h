#pragma once
#include "include.h "

#include "../JNITest/imgui/imgui.h"
#include "../JNITest/imgui/imgui_impl_win32.h"
#include "../JNITest/imgui/imgui_impl_opengl3.h"
class MenuImGui
{
public:
	void Draw();
	bool DrawBool = false;
};

static MenuImGui* menu = new MenuImGui();


static WNDPROC wndProcMinecraft = nullptr;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	return CallWindowProcA(wndProcMinecraft, hWnd, msg, wParam, lParam);
}



