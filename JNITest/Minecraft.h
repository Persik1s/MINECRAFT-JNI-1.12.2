#pragma once
#include "include.h"

class Minecraft {
public:
	jobject GetMinecraft();
	jobject thePlayer();
	jobject GetWorldClient();


	const char* nameWindow = "Minecraft 1.12.2"; // Name Minecraft;
	//Position
	double PositionX(jobject entity);
	double PositionY(jobject entity);
	double PositionZ(jobject entity);

	float GetHealth(jobject entity);


};
 static Minecraft* mc = new Minecraft();