/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** main.cpp
*/

#include <memory>
#include "Materials/Mirror.hpp"
#include "Materials/Metal.hpp"
#include "Materials/IMaterial.hpp"
#include "Math/Vector.hpp"
#include "Scene/Camera.hpp"
#include "Primitives/Spheres.hpp"
#include "Primitives/Hittables.hpp"
#include "Utils/Color.hpp"


int main(int ac, const char * const * argv) {
    // Setup World

    Raytracer::Primitives::HittableList World;
    std::shared_ptr<Raytracer::Material::Lambertian> material_ground = std::make_shared<Raytracer::Material::Lambertian>(Raytracer::Color(0.8, 0.8, 0.0));
    std::shared_ptr<Raytracer::Material::Lambertian> material_center = std::make_shared<Raytracer::Material::Lambertian>(Raytracer::Color(0.1, 0.2, 0.5));
    std::shared_ptr<Raytracer::Material::IMaterials> material_left   = std::make_shared<Raytracer::Material::Mirror>(Raytracer::Color(0.8, 0.8, 0.8));
    std::shared_ptr<Raytracer::Material::IMaterials> material_right  = std::make_shared<Raytracer::Material::Metal>(Raytracer::Color(0.8, 0.6, 0.2), 0.5);

    World.Add(std::make_shared<Raytracer::Primitives::Spheres>(Raytracer::Math::Point3D( 0.0, -100.5, -1.0), 100.0, material_left));
    World.Add(std::make_shared<Raytracer::Primitives::Spheres>(Raytracer::Math::Point3D( 0.0,    0.0, -1.2),   0.5, material_center));
    World.Add(std::make_shared<Raytracer::Primitives::Spheres>(Raytracer::Math::Point3D(-1.0,    0.0, -1.0),   0.5, material_left));
    World.Add(std::make_shared<Raytracer::Primitives::Spheres>(Raytracer::Math::Point3D( 1.0,    0.0, -1.0),   0.5, material_right));

    Raytracer::Scene::Camera SceneCamera(400);

    // Display
    SceneCamera.render(World);

}
