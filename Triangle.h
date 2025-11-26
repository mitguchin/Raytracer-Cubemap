#pragma once

#include "Object.h"

namespace hlab
{
	using namespace glm;

	class Triangle : public Object
	{
	public:
		vec3 v0, v1, v2;
		vec2 uv0, uv1, uv2;

	public:
		Triangle()
			: v0(vec3(0.0f)), v1(vec3(0.0f)), v2(vec3(0.0f)), 
			uv0(vec2(0.0f)), uv1(vec2(0.0f)), uv2(vec2(0.0f))
		{
		}

		Triangle(vec3 v0, vec3 v1, vec3 v2, vec2 uv0 = vec2(0.0f), vec2 uv1 = vec2(0.0f), vec2 uv2 = vec2(0.0f))
			: v0(v0), v1(v1), v2(v2), uv0(uv0), uv1(uv1), uv2(uv2)
		{
		}

		virtual Hit CheckRayCollision(Ray &ray)
		{
			Hit hit = Hit{-1.0, vec3(0.0), vec3(0.0)};

			vec3 point, faceNormal;
			float t, w0, w1;
			if (IntersectRayTriangle(ray.start, ray.dir, this->v0, this->v1,
				this->v2, point, faceNormal, t, w0, w1))
			{
				hit.d = t;
				hit.point = point;
				hit.normal = faceNormal;
				hit.uv = uv0 * w0 + uv1 * w1 + uv2 * (1.0f - w0 - w1);
			}

			return hit;
		}

		bool IntersectRayTriangle(const vec3 &orig, const vec3 &dir,
			const vec3 &v0, const vec3 &v1,
			const vec3 &v2, vec3 &point, vec3 &faceNormal,
			float &t, float &w0, float &w1)

		{
			faceNormal = glm::normalize(glm::cross(v1 - v0, v2 - v0));

			if (dot(-dir, faceNormal) < 0.0f)
				return false;

			if (glm::abs(dot(dir, faceNormal)) < 1e-2f)
				return false;

			t = (dot(v0, faceNormal) - dot(orig, faceNormal)) / 
			(dot(dir, faceNormal));

			if (t < 0.0f)
				return false;

			point = orig + t * dir;

			const vec3 cross0 = glm::cross(point - v2, v1 - v2);
			const vec3 cross1 = glm::cross(point - v0, v2 - v0);
			const vec3 cross2 = glm::cross(v1 - v0, point - v0);

			if (dot(cross0, faceNormal) < 0.0f)
				return false;
			if (dot(cross1, faceNormal) < 0.0f)
				return false;
			if (dot(cross2, faceNormal) < 0.0f)
				return false;

			const float area0 = glm::length(cross0) * 0.5f;
			const float area1 = glm::length(cross1) * 0.5f;
			const float area2 = glm::length(cross2) * 0.5f;

			const float areaSum = area0 + area1 + area2;

			w0 = area0 / areaSum;
			w1 = area1 / areaSum;

			return true;
		}
	};
}
