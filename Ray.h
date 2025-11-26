#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

namespace hlab
{
	class Ray
	{
	public:
		glm::vec3 start;
		glm::vec3 dir;
	};
}