#pragma once
#include <jni.h>
#include "include.h"
class EntityPlayer {
public:
	void SetAllowFlying(bool b,jobject player);
	void SetFying(bool b, jobject player);
	bool isFlying(jobject player);

	void SetGlowing(jobject entity, bool b);
	void SetSprintig(jobject entity, bool b);

	std::vector<jobject> playerEnitities(jobject world);
};
static EntityPlayer* entity = new EntityPlayer();

