#include "menu.h"

void MenuImGui::Draw() {

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();



	ImGui::Begin("JNI CHEAT 1.12.2", nullptr, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize);
	{

	}
	
	
	ImGui::End();
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}