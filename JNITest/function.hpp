#include "Minecraft.h"
#include "EntityPlayer.h"

#include "include.h"


namespace Function {
	void GlowESP() {
		if (mc->GetWorldClient() == 0)
			return;

		std::vector<jobject> entities = entity->playerEnitities(mc->GetWorldClient());

		if (entities.size() == 0) 
			return;

		for (int i = 0; i < entities.size(); i++) {
			entity->SetGlowing(entities[i], true);
		}
	}

	void Sprint() {
		entity->SetSprintig(mc->thePlayer(), true);
	}
}
