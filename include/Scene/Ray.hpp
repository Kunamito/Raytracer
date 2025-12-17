/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Ray
*/

#pragma once

#include "Math/Vector.hpp"

namespace Raytracer {
namespace Scene {
class Ray {
    public:
        // Constructor for the ray class
        Ray() = default;
        Ray(Raytracer::Math::Point3D Origin,
            Raytracer::Math::Vector3D Direction) :
            _Origin(Origin),
            _Direction(Direction) {}
        // Destructor for this class
        ~Ray() = default;

        // Getter for Direction and Origin
        Raytracer::Math::Vector3D Direction() const {
            return this->_Direction;
        }

        Raytracer::Math::Point3D Origin() {
            return this->_Origin;
        }

        // At function important to calculate the ray hit point
        Raytracer::Math::Point3D at(double t) const {
            return this->_Origin + t * this->_Direction;
        }

    protected:
    private:
        Raytracer::Math::Point3D _Origin;
        Raytracer::Math::Vector3D _Direction;
};
} // Namespace Scene
} // Namespace Raytracer
