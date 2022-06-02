#pragma once

#include "Happy/Scene/Scene.h"

namespace HPY
{
	class SceneSerializer
	{
	public:
		SceneSerializer(const Ref<Scene>& scene);

		void Serialize(const std::string& filePath);
		bool Deserialize(const std::string& filePath);

	private:
		Ref<Scene> m_Scene;
	};
}