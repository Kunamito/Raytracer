/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Mirror
*/

#include "IMaterial.hpp"
#include "Math/Vector.hpp"
#include "Scene/Ray.hpp"
#include "Utils/Color.hpp"


namespace Raytracer {
namespace Material {
class Mirror : public IMaterials {
    public :
        Mirror(const Color & albedo) : _Albedo(albedo) {}

        bool Scatter(const Raytracer::Scene::Ray &Ray_in, const Raytracer::Primitives::Record &Record, Raytracer::Color &attenuation, Raytracer::Scene::Ray &Scattered) const override {
            Math::Vector3D Reflected = Math::reflect(Ray_in.Direction(), Record.Vector);
            Scattered = Scene::Ray(Record.Point, Reflected);
            attenuation = this->_Albedo;
            return true;
        }
    private:
    Color _Albedo;
};
}
}
