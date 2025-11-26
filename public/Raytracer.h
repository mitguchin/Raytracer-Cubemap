#pragma once

#include "Sphere.h"
#include "Ray.h"
#include "Light.h"
#include "Triangle.h"
#include "Square.h"

#include <vector>

namespace hlab
{
	using namespace std;
	using namespace glm;

	class Raytracer
	{
	public:
		int width, height;
		Light light;
		vector<shared_ptr<Object>> objects;

		Raytracer(const int& width, const int& height)
			: width(width), height(height)
		{

			auto sphere1 = make_shared<Sphere>(vec3(0.2f, 0.3f, 3.0f), 1.5f);
			sphere1->amb = vec3(0.0f);
			sphere1->dif = vec3(1.0f, 0.0f, 0.0f);
			sphere1->spec = vec3(1.0f);
			sphere1->alpha = 50.0f;
			sphere1->reflection = 0.15f;
			sphere1->transparency = 0.5f;
			objects.push_back(sphere1);

			auto sphere2 = make_shared<Sphere>(vec3(1.2f, -0.8f, 1.0f), 0.4f);
			sphere2->amb = vec3(0.0f);
			sphere2->dif = vec3(0.0f, 0.0f, 1.0f);
			sphere2->spec = vec3(1.0f);
			sphere2->alpha = 50.0f;
			sphere2->reflection = 0.15f;
			sphere2->transparency = 0.5f;
			objects.push_back(sphere2);

			auto sphere3 = make_shared<Sphere>(vec3(-2.0f, -0.4f, 2.0f), 0.8f);
			sphere3->amb = vec3(0.0f);
			sphere3->dif = vec3(0.0f, 0.0f, 1.0f);
			sphere3->spec = vec3(0.2f);
			sphere3->alpha = 50.0f;
			sphere3->reflection = 0.1f;
			sphere3->transparency = 0.9f;
			objects.push_back(sphere3);

			auto groundTexture = std::make_shared<Texture>("orange-stucco-surface.jpg");
			auto ground = make_shared<Square>(
				vec3(-5.0f, -1.2f, 0.0f), 
				vec3(-5.0f, -1.2f, 10.0f), 
				vec3(5.0f, -1.2f, 5.0f), 
				vec3(5.0f, -1.2f, 0.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), 
				vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));
			ground->amb = vec4(0.5f);
			ground->dif = vec4(1.0f);
			ground->spec = vec4(1.0f);
			ground->alpha = 50.0f;
			ground->reflection = 0.0f;
			ground->ambTexture = groundTexture;
			ground->difTexture = groundTexture;

			objects.push_back(ground);

			auto texRight = std::make_shared<Texture>("image/posx.jpg");
			auto texLeft = std::make_shared<Texture>("image/negx.jpg");
			auto texTop = std::make_shared<Texture>("image/posy.jpg");
			auto texBottom = std::make_shared<Texture>("image/negy.jpg");
			auto texFront = std::make_shared<Texture>("image/posz.jpg");
			auto texBack = std::make_shared<Texture>("image/negz.jpg");

			auto front = make_shared<Square>(
				vec3(-10.0f, 10.0f, 10.0f),
				vec3(10.0f, 10.0f, 10.0f),
				vec3(10.0f, -10.0f, 10.0f),
				vec3(-10.0f, -10.0f, 10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f),
				vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			front->amb = vec3(1.0f);
			front->dif = vec3(0.0f);
			front->spec = vec3(0.0f);
			front->alpha = 10.0f;
			front->reflection = 0.0f;
			front->ambTexture = texFront;
			front->difTexture = texFront;

			objects.push_back(front);


			auto back = make_shared<Square>(
				vec3(10.0f, 10.0f, -10.0f), 
				vec3(-10.0f, 10.0f, -10.0f), 
				vec3(-10.0f, -10.0f, -10.0f), 
				vec3(10.0f, -10.0f, -10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), 
				vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			back->amb = vec3(1.0f);
			back->dif = vec3(0.0f);
			back->spec = vec3(0.0f);
			back->alpha = 10.0f;
			back->reflection = 0.0f;
			back->ambTexture = texBack;
			back->difTexture = texBack;

			objects.push_back(back);

			auto right = make_shared<Square>(
				vec3(10.0f, 10.0f, 10.0f),
				vec3(10.0f, 10.0f, -10.0f),
				vec3(10.0f, -10.0f, -10.0f),
				vec3(10.0f, -10.0f, 10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f),
				vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			right->amb = vec3(1.0f);
			right->dif = vec3(0.0f);
			right->spec = vec3(0.0f);
			right->alpha = 10.0f;
			right->reflection = 0.0f;
			right->ambTexture = texRight;
			right->difTexture = texRight;

			objects.push_back(right);

			auto left = make_shared<Square>(
				vec3(-10.0f, 10.0f, -10.0f),
				vec3(-10.0f, 10.0f, 10.0f),
				vec3(-10.0f, -10.0f, 10.0f),
				vec3(-10.0f, -10.0f, -10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f),
				vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			left->amb = vec3(1.0f);
			left->dif = vec3(0.0f);
			left->spec = vec3(0.0f);
			left->alpha = 10.0f;
			left->reflection = 0.0f;
			left->ambTexture = texLeft;
			left->difTexture = texLeft;

			objects.push_back(left);

			auto top = make_shared<Square>(
				vec3(-10.0f, 10.0f, -10.0f),
				vec3(10.0f, 10.0f, -10.0f),
				vec3(10.0f, 10.0f, 10.0f),
				vec3(-10.0f, 10.0f, 10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f),
				vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			top->amb = vec3(1.0f);
			top->dif = vec3(0.0f);
			top->spec = vec3(0.0f);
			top->alpha = 10.0f;
			top->reflection = 0.0f;
			top->ambTexture = texTop;
			top->difTexture = texTop;

			objects.push_back(top);

			auto bottom = make_shared<Square>(
				vec3(-10.0f, -10.0f, 10.0f),
				vec3(10.0f, -10.0f, 10.0f),
				vec3(10.0f, -10.0f, -10.0f),
				vec3(-10.0f, -10.0f, -10.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f),
				vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			bottom->amb = vec3(1.0f);
			bottom->dif = vec3(0.0f);
			bottom->spec = vec3(0.0f);
			bottom->alpha = 10.0f;
			bottom->reflection = 0.0f;
			bottom->ambTexture = texBottom;
			bottom->difTexture = texBottom;

			objects.push_back(bottom);

			light = Light{ {0.0f, 0.3f, -0.5f} };
		}

		Hit FindClosestCollision(Ray& ray)
		{
			float closestD = 1000.0;

			Hit closestHit{ -1.0, glm::dvec3(0.0), glm::dvec3(0.0) };

			for (size_t l = 0; l < objects.size(); ++l)
			{
				Hit hit = objects[l]->CheckRayCollision(ray);

				if (hit.d >= 0.0 )
				{
					if (hit.d < closestD)
					{
						closestD = hit.d;
						closestHit = hit;
						closestHit.obj = objects[l]; 

						closestHit.uv = hit.uv;
					}
				}
			}

			return closestHit;
		}


		vec3 traceRay(Ray& ray, const int recurseLevel)
		{
			if (recurseLevel < 0)
				return vec3(0.0f);

			// Render first hit
			const auto hit = FindClosestCollision(ray);

			if (hit.d >= 0.0f)
			{
				glm::vec3 color(0.0f);

				const vec3 dirToLight = glm::normalize(light.pos - hit.point);

				
					glm::vec3 phongColor(0.0f);

					const float diff = glm::max(dot(hit.normal, dirToLight), 0.0f);
					const vec3 reflectDir = 2.0f * hit.normal * dot(dirToLight, hit.normal) - dirToLight;
					const float specular = glm::pow(glm::max(glm::dot(-ray.dir, reflectDir), 0.0f), hit.obj->alpha);

					if (hit.obj->ambTexture)
					{
						phongColor += hit.obj->amb * hit.obj->ambTexture->SampleLinear(hit.uv);
					}
					else
					{
						phongColor += hit.obj->amb;
					}

					if (hit.obj->difTexture)
					{
						phongColor += diff * hit.obj->dif * hit.obj->difTexture->SampleLinear(hit.uv);
					}
					else
					{
						phongColor += diff * hit.obj->dif;
					}

					phongColor += hit.obj->spec * specular;


					color += phongColor * (1.0f - hit.obj->reflection - hit.obj->transparency);

					if (hit.obj->reflection)
					{
						const auto reflectedDirection = glm::normalize(2.0f * hit.normal * dot(-ray.dir, hit.normal) + ray.dir);
						Ray reflection_ray{ hit.point + reflectedDirection * 1e-4f, reflectedDirection }; // add a small vector to avoid numerical issue

						color += traceRay(reflection_ray, recurseLevel - 1) * hit.obj->reflection;
					}

					if (hit.obj->transparency)
					{
						const float ior = 1.5f; 

						float eta; 
						vec3 normal;

						if (glm::dot(ray.dir, hit.normal) < 0.0f) 
						{
							eta = ior;
							normal = hit.normal;
						}
						else 
						{
							eta = 1.0f / ior;
							normal = -hit.normal;
						}

						const float cosTheta1 = glm::dot(-ray.dir, normal);
						const float sinTheta1 = sqrt(1.0f - cosTheta1 * cosTheta1); 
						const float sinTheta2 = sinTheta1 / eta;
						const float cosTheta2 = sqrt(1.0f - sinTheta2 * sinTheta2);

						const vec3 m = glm::normalize(dot(normal, -ray.dir) * normal + ray.dir);
						const vec3 a = m * sinTheta2;
						const vec3 b = -normal * cosTheta2;
						const vec3 refractedDirection = glm::normalize(a + b); 

						Ray refractionRay{ hit.point + refractedDirection * 0.001f, refractedDirection };
						color += traceRay(refractionRay, recurseLevel - 1) * hit.obj->transparency;

					}

				return color;
			}

			return vec3(0.0f);
		}

		void Render(std::vector<glm::vec4>& pixels)
		{
			std::fill(pixels.begin(), pixels.end(), vec4(0.0f, 0.0f, 0.0f, 1.0f));

			const vec3 eyePos(0.0f, 0.0f, -1.5f);

#pragma omp parallel for
			for (int j = 0; j < height; j++)
				for (int i = 0; i < width; i++)
				{
					const vec3 pixelPosWorld = TransformScreenToWorld(vec2(i, j));
					Ray pixelRay{ pixelPosWorld, glm::normalize(pixelPosWorld - eyePos) };
					pixels[i + width * j] = vec4(glm::clamp(traceRay(pixelRay, 5), 0.0f, 1.0f), 1.0f);
				}
		}

		vec3 TransformScreenToWorld(vec2 posScreen)
		{
			const float xScale = 2.0f / this->width;
			const float yScale = 2.0f / this->height;
			const float aspect = float(this->width) / this->height;

			return vec3((posScreen.x * xScale - 1.0f) * aspect, -posScreen.y * yScale + 1.0f, 0.0f);
		}
	};
}
