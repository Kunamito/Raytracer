/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Vector lib for Raytracer
*/

#pragma once

#include "Utils/Color.hpp"
#include <cmath>
#include <iostream>

namespace Raytracer {
namespace Math {
    class Vector3D {
        public :
            // Constructor for our class
            Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}
            Vector3D() {}

            // Getter for our values
            double x() const { return _x; }
            double y() const { return _y; }
            double z() const { return _z; }

            Raytracer::Color Cast_Vector() {
                Raytracer::Color color(0, 0, 0);

                color.setColorX(this->_x);
                color.setColorY(this->_y);
                color.setColorZ(this->_z);
                return color;
            }

            // Operator for our values
            Vector3D operator+=(Vector3D vec) {
                this->_x += vec.x();
                this->_y += vec.y();
                this->_z += vec.z();
                return *this;
            }

            Vector3D operator-() {
                this->_x = -this->x();
                this->_y = -this->y();
                this->_z = -this->z();
                return *this;
            }

            Vector3D operator*=(double mult) {
                this->_x *= mult;
                this->_y *= mult;
                this->_z *= mult;
                return *this;
            }

            Vector3D operator/=(double mult) {
                return *this *= 1 / mult;
            }

            double length() const {
                return std::sqrt(length_squared());
            }

            double length_squared() const {
               return this->x()*this->x() + this->y() * this->y() + this->z() * this->z();
            }

            bool near_zero() const {
                float s = 1e-8;
                return (std::fabs(this->x()) < s) && (std::fabs(this->y()) < s) && (std::fabs(this->z()) < s);
            }

            static Raytracer::Math::Vector3D random() {
                return Raytracer::Math::Vector3D(random_double(), random_double(), random_double());
            }

            static Raytracer::Math::Vector3D random(double min, double max) {
              return Raytracer::Math::Vector3D(random_double(min,max), random_double(min,max), random_double(min,max));
            }

        private :
            double _x;
            double _y;
            double _z;
    };

    // The use of Point3D is similar to Vector3D its just to image better
    using Point3D = Vector3D;

    // Utility for our vector
    inline std::ostream& operator<<(std::ostream& out, const Vector3D& vec) {
        return out << vec.x() << ' ' << vec.y() << ' ' << vec.z();
    }

    inline Vector3D operator+(const Vector3D& u, const Vector3D& vec) {
        return Vector3D(u.x() + vec.x(), u.y() + vec.y(), u.z() + vec.z());
    }

    inline Vector3D operator-(const Vector3D& u, const Vector3D& vec) {
        return Vector3D(u.x() - vec.x(), u.y() - vec.y(), u.z() - vec.z());
    }

    inline Vector3D operator*(const Vector3D& u, const Vector3D& vec) {
        return Vector3D(u.x() * vec.x(), u.y() * vec.y(), u.z() * vec.z());
    }

    inline Vector3D operator*(double t, const Vector3D& vec) {
        return Vector3D(t*vec.x(), t*vec.y(), t*vec.z());
    }

    inline Vector3D operator*(const Vector3D& vec, double t) {
        return t * vec;
    }

    inline Vector3D operator/(const Vector3D& vec, double t) {
        return (1/t) * vec;
    }

    inline double dot(const Vector3D& u, const Vector3D& vec) {
        return u.x() * vec.x()
             + u.y() * vec.y()
             + u.z() * vec.z();
    }

    inline Vector3D cross(const Vector3D& u, const Vector3D& vec) {
        return Vector3D(u.y() * vec.z() - u.z() * vec.y(),
                    u.z() * vec.x() - u.x() * vec.z(),
                    u.x() * vec.y() - u.y() * vec.x());
    }

    inline Vector3D unit_vector(const Vector3D& vec) {
        return vec / vec.length();
    }
    inline Raytracer::Math::Vector3D random_unit_vector() {
        while (true) {
            Raytracer::Math::Vector3D p = Raytracer::Math::Vector3D::random(-1,1);
            double lensq = p.length_squared();
            if (1e-160 < lensq && lensq <= 1)
                return p / sqrt(lensq);
        }
    }
    inline Raytracer::Math::Vector3D random_on_hemisphere(const Raytracer::Math::Vector3D& normal) {
        Raytracer::Math::Vector3D on_unit_sphere = random_unit_vector();
        if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
            return on_unit_sphere;
        else
            return -on_unit_sphere;
    }

    inline Vector3D reflect(const Vector3D& Vector, const Vector3D&incidence) {
        return Vector - 2 * dot(Vector, incidence) * incidence;
    }
}
}
