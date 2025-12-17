/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IMaterials
*/

#pragma once

#include "Math/Vector.hpp"
#include "Utils/Color.hpp"
#include "../Scene/Ray.hpp"
#include "../Primitives/Record.hpp"

namespace Raytracer {
namespace Material {
class IMaterials {
    public:
        virtual ~IMaterials() = default;

        virtual bool Scatter(const Raytracer::Scene::Ray &Ray_in, const Raytracer::Primitives::Record &Record, Raytracer::Color &attenuation, Raytracer::Scene::Ray &Scattered) const = 0;
};

class Lambertian : public IMaterials {
    public:
        Lambertian(const Color &albedo) : _Albedo(albedo) {};

        bool Scatter(const Raytracer::Scene::Ray &Ray_In, const Raytracer::Primitives::Record &Record, Raytracer::Color &attenuation, Raytracer::Scene::Ray &Scattered) const override {
            Math::Vector3D Scatter_direction = Record.Vector + Math::random_unit_vector();

            // Catch degenerate scatter direction

            if (Scatter_direction.near_zero())
                Scatter_direction = Record.Vector;
            Scattered = Scene::Ray(Record.Point, Scatter_direction);
            attenuation = this->_Albedo;
            return true;
        }
    private:
        Color _Albedo;
};
}
}
