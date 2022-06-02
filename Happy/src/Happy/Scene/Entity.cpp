#include "hpypch.h"
#include "Happy/Scene/Entity.h"

namespace HPY
{

	Entity::Entity(entt::entity handle, Scene* scene)
		:m_EntityHandle(handle), m_Scene(scene)
	{
	}

}