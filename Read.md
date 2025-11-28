
#CPU Raytracer Example
This project is the simple example of "CPU Raytracer".

[By using "glm" Library and C++ standard Library, Randered Sphere, Ground(Square), Skybox.



#Main Function

**Object**
- Three Spheres
- Ground(Floor): Square(Two Triangles) | Texture(orange-stucco-surface.jpg)

**Skybox**
- Six Squares(front, back, left, right, top, bottom)
- Use cube map immages('posx/negx/posy/negy/posz/negz")

**Materials & Lighting**
- Ambient / Diffuse / Specular(Phong Shading)
- Mirror reflection
- Refraction(with IOR = 1.5)
- Texture sampling with "SampleLinear"

**Camera**
- Position (0,0,-1.5)
- Screen-to-world Coordinate transform: "TransformScreenToWorld"

**Performance**
- Pixel-level multithreading using OpenMP  [#pragma omp parallel for]


## Project Structure

* "Raytracer.h"
Contains the main "Raytracer" class:
- Scene initialize(sphere, ground, skybox)
- Ray casting and collision detection
- Color computation (Phong, reflection, refraction)

- Sphere.h, Triangle.h, Square.h
=> Implement geometric primitives and their ray-object intersections

* "Ray.h"
=> Ray structure (origin, direction)

* "Light.h"
=> Point light data

* "Texture.h"
=> Load image files and samples pixels using UV coordinates.

* "main.cpp"
=> Create the ray tracer, call "Render()", and display or save the final image.

## Requirment
- C++ 17 or higher
- GLM[https://github.com/g-truc/glm]
- (Optional) OpenMP for multithreaded rendering
- An image loader (stb_image) for textures

## Instructions
1. Create a new C++ console
2. Add GLM header include path.
3. Add all .h/ .cpp files to the project
4. Enable OpenMP (optional):
- Project Properties-> C/C++ -> Language -> Enable OpemMP Support
5. Place the "image" folder next to the exucutable so texture files load activity.


## cpp

int main()
{
  const int width = 1280;
  const int height = 720;

  hlab::Raytracer raytracer(width,height);
  std::vector<glm::vec4> pixels(width * height);

  raytracer.Render(pixels);
  
  return 0;
}
