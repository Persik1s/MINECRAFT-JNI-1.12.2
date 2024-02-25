#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <jni.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <gl/GL.h>
#include <string>

#include "Minecraft.h"
#include "MinHook.h"

typedef int(__stdcall* wglSwapBuffer)(HDC hdc);

static wglSwapBuffer buffer;




#pragma comment(lib, "jvm.lib")
#pragma comment(lib, "imgui.lib")
#pragma comment(lib, "libMinHook-x64.lib")
#pragma comment(lib, "opengl32")