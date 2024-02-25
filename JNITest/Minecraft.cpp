#include "Minecraft.h"
#include "minecraftClasses.h"
extern JNIEnv* env;
jobject Minecraft::GetMinecraft() {
	jclass classId = env->FindClass(mineceaftClass.minecraftClass.c_str());
	if (classId == 0) {
		return 0;
	}
	jfieldID fieldId = env->GetStaticFieldID(classId, mineceaftField.theMinecraft.c_str(), ("L" +mineceaftClass.minecraftClass+ ";").c_str());
	return env->GetStaticObjectField(classId, fieldId);
}

jobject Minecraft::thePlayer() {
	auto player = env->GetFieldID(env->GetObjectClass(this->GetMinecraft()), mineceaftField.thePlayer.c_str(), ("L"+mineceaftClass.entityPlayerSP+";").c_str());
	return env->GetObjectField(this->GetMinecraft(), player);
}
jobject Minecraft::GetWorldClient() {
	auto world = env->GetFieldID(env->GetObjectClass(this->GetMinecraft()), mineceaftField.world.c_str(), ("L"+mineceaftClass.worldClient+";").c_str());
	return env->GetObjectField(this->GetMinecraft(), world);
}
double Minecraft::PositionX(jobject entity) {
	jclass entityClass = env->FindClass(mineceaftClass.entity.c_str());//Enity
	jfieldID posXF = env->GetFieldID(entityClass, mineceaftField.posX.c_str(), "D"); //pos x
	return env->GetDoubleField(entity, posXF);
}

double Minecraft::PositionY(jobject entity) {
	jclass entityClass = env->FindClass(mineceaftClass.entity.c_str());//Enity
	jfieldID posXF = env->GetFieldID(entityClass, mineceaftField.posY.c_str(), "D"); // pos y
	return env->GetDoubleField(entity, posXF);
}

double Minecraft::PositionZ(jobject entity) {
	jclass entityClass = env->FindClass(mineceaftClass.entity.c_str());//Enity
	jfieldID posXF = env->GetFieldID(entityClass, mineceaftField.posZ.c_str(), "D"); // z
	return env->GetDoubleField(entity, posXF);
}

float Minecraft::GetHealth(jobject entity) {
	jclass enityLiving = env->FindClass(mineceaftClass.entityLivingBase.c_str());
	jmethodID health = env->GetMethodID(enityLiving, mineceaftMethode.getHealth.c_str(), "()F");
	return env->CallFloatMethod(entity, health);
}
