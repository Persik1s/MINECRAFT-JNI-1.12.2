#pragma once
#include <string>
struct MinecraftClass
{
	std::string minecraftClass = "bib"; // Minecraft
	std::string entityPlayerSP = "bud"; // EntityPlayerSP 
	std::string worldClient = "bsb"; // WorldClient
	std::string world = "amu"; // World

	std::string entity = "vg"; // Entity
	std::string entityPlayer = "aed"; // EntityPlayer
	std::string playerCapabilities = "aeb"; //PlayerCapabilities

	std::string entityLivingBase = "vp"; // EntityLivingBase
};
static MinecraftClass mineceaftClass;

struct MinecraftField 
{
	std::string theMinecraft = "R"; // in Minecraft class
	std::string thePlayer = "h";// // in Minecraft class 
	std::string world = "f"; // in Minecraft class

	std::string capabilities = "bO";

	std::string posX = "p";// in Entity class
	std::string posY = "r";// in Entity class
	std::string posZ = "s";// in Entity class
};
static MinecraftField mineceaftField;


struct MinecraftMethode
{
	std::string getHealth = "cd";
};
static MinecraftMethode mineceaftMethode;