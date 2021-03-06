#pragma once


#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include "Happy/Core/Memory.h"
#include "Happy/Renderer/Material.h"
#include "Happy/Renderer/Mesh.h"

namespace HPY
{
	// Add Sun - Only one of these...
	enum class LightType { Sun, Directional, Point, Spot };

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string & tag)
			: Tag(tag){ }
	};

	struct TransformComponent
	{
		glm::vec3 Translation{ 0.0f };
		glm::vec3 Rotation{ 0.0f };
		glm::vec3 Scale{ 1.0f };


		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3& translation)
			:Translation(translation) {}

		TransformComponent(const glm::vec3& translation, const glm::vec3& rotation, const glm::vec3& scale)
			:Translation(translation), Rotation(rotation), Scale(scale) { }

		glm::mat4 Transform() const
		{
			glm::mat4 translation = glm::translate(glm::mat4(1.0f), Translation);
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));
			glm::mat4 scale = glm::scale(glm::mat4(1.0f), Scale);

			return translation * rotation * scale;
		}

		glm::quat CalculateOrientation()
		{
			auto& rotation = Rotation;
			return glm::quat(rotation);
		}

		glm::vec3 Up()
		{
			return glm::rotate(CalculateOrientation(), { 0.0f, 1.0f, 0.0f });
		}

		glm::vec3 Right()
		{
			return glm::rotate(CalculateOrientation(), { 1.0f, 0.0f, 0.0f });
		}

		glm::vec3 Forward()
		{
			return glm::rotate(CalculateOrientation(), { 0.0f, 0.0f, 1.0f });
		}
	};

	struct MeshRendererComponent
	{
		Ref<Material> MaterialInstance;
		Ref<Mesh> MeshData;

		bool IsComplete() const
		{
			return MaterialInstance != nullptr && MeshData != nullptr;
		}

		MeshRendererComponent() = default;
		MeshRendererComponent(const MeshRendererComponent&) = default;
		MeshRendererComponent(const Ref<Material>& material, const Ref<Mesh>& mesh)
			:MaterialInstance(material), MeshData(mesh) { }
	};

	struct CameraComponent
	{
		glm::mat4 View;
		glm::mat4 Projection;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;
		CameraComponent(const glm::mat4& view, const glm::mat4& projection)
			:View(view), Projection(projection) { }
	};

	struct LightComponent
	{
		LightType Type;
		glm::vec4 Color;
		float Intensity = 1.0f;
		bool DebugLight = true;

		LightComponent() = default;
		LightComponent(const LightComponent&) = default;
		LightComponent(LightType type, const glm::vec4& color = glm::vec4(1.0f), float intensity = 1.0, bool debug = false)
			:Type(type), Color(color), DebugLight(debug), Intensity(intensity) { }
	};
}