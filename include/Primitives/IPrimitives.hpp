/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** IPrimitives
*/

#pragma once

#include "Scene/Ray.hpp"
#include "./Record.hpp"

namespace Raytracer {
namespace Primitives {
class IPrimitives {
    public:
        virtual bool hit(Raytracer::Scene::Ray &ray, Raytracer::Utils::interval Ray_t, Raytracer::Primitives::Record &Record) const = 0;
    protected:
    private:
};
} // Primitives namespace
} // Raytracer namespace
