/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IPrimitives
*/

#pragma once

#include "Math/Vector.hpp"
#include "../Scene/Ray.hpp"
#include <memory>

namespace Raytracer {
namespace Material {
    class IMaterials;
}
namespace Primitives {
class Record {
    public:
        Math::Point3D Point;
        Math::Vector3D Vector;
        std::shared_ptr<Raytracer::Material::IMaterials> Material;
        double Root;
        bool Front_Face;

        void setFace(Scene::Ray& Ray, Math::Vector3D &Outward) {
            Front_Face = dot(Ray.Direction(), Outward) < 0;
            Vector = Front_Face ? Outward : -Outward;
        }
};
}
}
