#include "EntityPlayer.h"

#include "minecraftClasses.h"
extern JNIEnv* env;
void EntityPlayer::SetAllowFlying(bool b, jobject player) {
	jclass entityPlayerClass = env->FindClass(mineceaftClass.entityPlayer.c_str()); // EnityPlayer 
	jfieldID capabilitiesField = env->GetFieldID(entityPlayerClass, mineceaftField.capabilities.c_str(), ("L"+mineceaftClass.playerCapabilities+";").c_str()); // PlayerCapabilities
	jfieldID fid = env->GetFieldID(env->GetObjectClass(env->GetObjectField(player, capabilitiesField)), "c", "Z"); // allowFlying
	env->SetBooleanField(env->GetObjectField(player, capabilitiesField), fid, b);
}
void EntityPlayer::SetFying(bool b, jobject player) {
	jclass entityPlayerClass = env->FindClass(mineceaftClass.entityPlayer.c_str()); // EnityPlayer
	jfieldID capabilitiesField = env->GetFieldID(entityPlayerClass, mineceaftField.capabilities.c_str(), ("L" + mineceaftClass.playerCapabilities + ";").c_str()); // PlayerCapabilities
	jfieldID fid = env->GetFieldID(env->GetObjectClass(env->GetObjectField(player, capabilitiesField)), "b", "Z");
	env->SetBooleanField(env->GetObjectField(player, capabilitiesField), fid, b);
}
bool EntityPlayer::isFlying(jobject player) {
	jclass entityPlayerClass = env->FindClass(mineceaftClass.entityPlayer.c_str());
	jfieldID capabilitiesField = env->GetFieldID(entityPlayerClass, mineceaftField.capabilities.c_str(), ("L" + mineceaftClass.playerCapabilities + ";").c_str()); // PlayerCapabilities
	jfieldID fid = env->GetFieldID(env->GetObjectClass(env->GetObjectField(player, capabilitiesField)), "b", "Z");
	return env->GetBooleanField(env->GetObjectField(player, capabilitiesField), fid);
}


void EntityPlayer::SetGlowing(jobject entity, bool b) {
	jclass classEntity = env->FindClass("vg");
	jmethodID methodeId = env->GetMethodID(classEntity, "g", "(Z)V");

	env->CallVoidMethod(entity,methodeId,true);
}

void EntityPlayer::SetSprintig(jobject entity, bool b) {
	jclass entitySP = env->FindClass("bud");
	jmethodID spring = env->GetMethodID(entitySP, "f", "(Z)V");
	env->CallVoidMethod(entity, spring,b);
}

std::vector<jobject> EntityPlayer::playerEnitities(jobject world) {
	std::vector<jobject> entities;
	jclass worldClass = env->FindClass("amu");
	jfieldID loadedEntityList = env->GetFieldID(worldClass, "i","Ljava/util/List;");
	jclass listClass = env->FindClass("java/util/List");
	jobject wordMain =  env->GetObjectField(world, loadedEntityList);
	jmethodID toArray = env->GetMethodID(listClass, "toArray", "()[Ljava/lang/Object;");
	jobjectArray entityList = reinterpret_cast<jobjectArray>(env->CallObjectMethod(wordMain, toArray));

	int size = env->GetArrayLength(entityList);
	for(int  i = 0; i < size; i++)
	{
		entities.push_back(env->GetObjectArrayElement(entityList, i));
	}
	return entities;
}