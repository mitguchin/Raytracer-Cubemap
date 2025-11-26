#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

namespace hlab
{
	using namespace glm;

	class Object;

	class Hit
	{
	public:
		float d; //광선의 시작 충돌거리
		vec3 point; //충돌한 위치
		vec3 normal; //충돌한 위치에서 표면 수직 벡터
		vec2 uv; //텍스처 좌표

		std::shared_ptr<Object> obj; //충돌한 오브젝트

	};
}