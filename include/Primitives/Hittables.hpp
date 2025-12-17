/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Hittables
*/

#include "IPrimitives.hpp"
#include "Scene/Ray.hpp"

#include <memory>
#include <vector>

namespace Raytracer {
namespace Primitives {
class HittableList : public IPrimitives {
    public:
        std::vector<std::shared_ptr<IPrimitives>> Objects;

        HittableList() {};
        HittableList(std::shared_ptr<IPrimitives> object) { Add(object); };

        void Clear () { Objects.clear(); };

        void Add (std::shared_ptr<IPrimitives> object) {Objects.push_back(object);};

        bool hit(Scene::Ray &Ray, Raytracer::Utils::interval Ray_t, Raytracer::Primitives::Record &Records) const override {
            Raytracer::Primitives::Record TempRecord;
            bool HitAnything = false;
            double Closest = Ray_t.max;

           for (const auto &Object : Objects) {
               if (Object->hit(Ray, Ray_t, TempRecord)) {
                   HitAnything = true;
                   Closest = TempRecord.Root;
                   Records = TempRecord;
               }
           }
           return HitAnything;
        }
};
} // Namespace Primitives
} /// Namesapce Raytracer
