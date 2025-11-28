
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
- 
