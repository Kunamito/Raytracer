/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Camera
*/

#pragma once

#include "Materials/IMaterial.hpp"
#include "Math/Vector.hpp"
#include "Primitives/IPrimitives.hpp"
#include "Scene/Ray.hpp"
#include "Utils/Color.hpp"

namespace Raytracer {
namespace Scene {
class Camera {
    public:
        Camera(double width) : _ImageWidth(width), _FocalLength(1.0), _ViewportHeight(2.0) {
            // May be changed in the future to improve code
            this->_Ratio = 16.0 / 9.0;
            this->_MaxDepth = 50;
            this->_SamplesPerPixel = 100;
            this->_PixelSample = 1.0 / this->_SamplesPerPixel;
            this->_ImageLength = this->_ImageWidth / this->_Ratio;
            this->_ViewportWidth = this->_ViewportHeight * (double(this->_ImageWidth) / this->_ImageLength);
            this->_CameraCenter = Raytracer::Math::Point3D(0, 0, 0);

            this->_ViewportU = Raytracer::Math::Vector3D(this->_ViewportWidth, 0, 0);
            this->_ViewportV = Raytracer::Math::Vector3D(0, -this->_ViewportHeight, 0);

            this->_PixelDataU = this->_ViewportU / this->_ImageWidth;
            this->_PixelDataV = this->_ViewportV / this->_ImageLength;

            Raytracer::Math::Vector3D ViewportUpperLeft = this->_CameraCenter - Raytracer::Math::Vector3D(0, 0, this->_FocalLength) - this->_ViewportU/2 - this->_ViewportV/2;
            this->_Pixel00_Loc = ViewportUpperLeft + 0.5 * (this->_PixelDataU + this->_PixelDataV);
        }
        ~Camera() = default;
        double Width() {return _ImageWidth;}
        double Length() {return _ImageLength;}
        Raytracer::Math::Vector3D PixelDataU() {return _PixelDataU;}
        Raytracer::Math::Vector3D PixelDataV() {return _PixelDataV;}
        Raytracer::Math::Point3D CameraCenter() {return _CameraCenter;}
        Raytracer::Math::Vector3D Pixel00_Loc() {return _Pixel00_Loc;}


        void render(const Raytracer::Primitives::IPrimitives &world) {
            std::cout << "P3\n" << this->_ImageWidth << ' ' << this->_ImageLength << "\n255\n";

            for (int j = 0; j < this->_ImageLength; j++) {
                std::clog << "\rScanlines remaining: " << (this->_ImageLength - j) << ' ' << std::flush;
                for (int i = 0; i < this->_ImageWidth; i++) {
                    Raytracer::Color PixelColor(0, 0, 0);
                    for (int sample = 0; sample < this->_SamplesPerPixel; sample++) {
                        Raytracer::Scene::Ray Ray = GetRay(i, j);
                        PixelColor += this->RayColor(Ray, this->_MaxDepth, world);
                    }
                    PixelColor.write_color(std::cout, PixelColor * this->_PixelSample);
                }
            }

            std::clog << "\rDone.                 \n";
        }

    protected:
    private:

    Raytracer::Math::Vector3D sample_square() const {
        return Raytracer::Math::Vector3D(random_double() - 0.5, random_double() - 0.5, 0);
    }

    Raytracer::Scene::Ray GetRay(int i, int j) {
        Raytracer::Math::Vector3D offset = sample_square();
        Raytracer::Math::Vector3D PixelSample = this->Pixel00_Loc()
        + ((i + offset.x()) * PixelDataU())
        + ((j + offset.y()) * PixelDataV());
        Raytracer::Math::Vector3D RayOrigin = this->_CameraCenter;
        Raytracer::Math::Vector3D RayDirection = PixelSample - RayOrigin;
        return Raytracer::Scene::Ray(RayOrigin, RayDirection);
    }

    Raytracer::Color RayColor(Raytracer::Scene::Ray& Ray, double MaxDepth, const Raytracer::Primitives::IPrimitives &world) {
        Raytracer::Primitives::Record Record;

        if (MaxDepth <= 0) {
            return Raytracer::Color(0, 0, 0);
        }
        if (world.hit(Ray, Raytracer::Utils::interval(0.001, infinity), Record)) { // Shadow Acne suppression 0.001
            Raytracer::Scene::Ray Scattered;
            Raytracer::Color Attenuation(0, 0, 0);
            if (Record.Material->Scatter(Ray, Record, Attenuation, Scattered)) {
                return Attenuation * RayColor(Scattered, MaxDepth - 1, world); // Gamut of renderer
            }
            return Raytracer::Color(0, 0, 0);
        }
        Raytracer::Math::Vector3D unit_direction = Raytracer::Math::unit_vector(Ray.Direction());
        double a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * Raytracer::Color(1.0, 1.0, 1.0) + a * Raytracer::Color(0.5, 0.7, 1.0);
    }
        // May be changed in the future to improve code
        double _ImageWidth;
        int _SamplesPerPixel;
        double _PixelSample;
        double _ImageLength;
        double _Ratio;
        double _FocalLength;
        double _ViewportHeight;
        double _ViewportWidth;
        double _MaxDepth;
        Raytracer::Math::Vector3D _ViewportU;
        Raytracer::Math::Vector3D _ViewportV;

        // Will not change
        Raytracer::Math::Vector3D _PixelDataU;
        Raytracer::Math::Vector3D _PixelDataV;
        Raytracer::Math::Point3D _CameraCenter;
        Raytracer::Math::Point3D _Pixel00_Loc;

};
} // Namespace Scene
} // Namespace Raytracer
