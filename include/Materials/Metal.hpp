/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Metal
*/

#include "IMaterial.hpp"
#include "Math/Vector.hpp"
#include "Scene/Ray.hpp"
#include "Utils/Color.hpp"

namespace Raytracer {
namespace Material {
class Metal : public IMaterials {
    public :
        Metal(const Color & albedo, double fuzz) : _Fuzz(fuzz < 1 ? fuzz : 1), _Albedo(albedo) {}

        bool Scatter(const Raytracer::Scene::Ray &Ray_in, const Raytracer::Primitives::Record &Record, Raytracer::Color &attenuation, Raytracer::Scene::Ray &Scattered) const override {
            Math::Vector3D Reflected = Math::reflect(Ray_in.Direction(), Record.Vector);
            Reflected = Math::unit_vector(Reflected) + (this->_Fuzz * Math::random_unit_vector());
            Scattered = Scene::Ray(Record.Point, Reflected);
            attenuation = this->_Albedo;
            return (Math::dot(Scattered.Direction(), Record.Vector) > 0);
        }
    private:
    Color _Albedo;
    double _Fuzz;
};
}
}
