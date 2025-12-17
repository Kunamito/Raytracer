/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Spheres
*/

#pragma once

#include "Math/Vector.hpp"
#include "Primitives/IPrimitives.hpp"
#include "Primitives/Record.hpp"
#include <cmath>
#include <memory>

namespace Raytracer {
namespace Primitives {
class Spheres : public IPrimitives {
    public:
        bool hit(Raytracer::Scene::Ray &ray, Raytracer::Utils::interval Ray_t, Raytracer::Primitives::Record &Record) const override {
            Raytracer::Math::Vector3D Origin = this->_Origin - ray.Origin();
            double dot_direction = ray.Direction().length_squared();
            double dot_ray = Raytracer::Math::dot(ray.Direction(), Origin);
            double dot_origin = Origin.length_squared() - this->_Radius * this->_Radius;
            double discriminant = dot_ray * dot_ray - dot_direction * dot_origin;

            if (discriminant < 0) {
                return false;
            }

            double sqrtd = std::sqrt(discriminant);

            double root = (dot_ray - sqrtd) / dot_direction;
            if (!Ray_t.surrounds(root)) {
                root = (dot_ray + sqrtd) / dot_direction;
                if (!Ray_t.surrounds(root)) {
                    return false;
                }
            }
            Record.Point = ray.at(root);
            Record.Root = root;
            Record.Material = this->_Material;
            Record.Vector = (Record.Point - this->_Origin) / this->_Radius;
            Math::Vector3D Outward = (Record.Point - this->_Origin) / this->_Radius;
            Record.setFace(ray, Outward);
            return true;
        };

        Spheres(Raytracer::Math::Point3D origin, double radius, std::shared_ptr<Raytracer::Material::IMaterials> Material) : _Origin(origin), _Radius(std::fmax(0, radius)), _Material(Material) {};
        ~Spheres() = default;

        Raytracer::Math::Point3D Origin() {return this->_Origin;};
        double Radius() {return this->_Radius;}

    protected:
    private:
        Raytracer::Math::Point3D _Origin;
        double _Radius;
        std::shared_ptr<Raytracer::Material::IMaterials> _Material;
};
} // Namespace Primitives
} // Namespace Raytracer
