/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Vector lib for Raytracer
*/

#include <cmath>
#include <iostream>

namespace Raytracer {
namespace Math {
    class Vector3D {
        public :
            // Constructor for our class
            Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

            // Getter for our values
            double x() const { return _x; }
            double y() const { return _y; }
            double z() const { return _z; }

            // Setter for out values
            Vector3D operator+=(Vector3D vec) {
                this->_x += vec.x();
                this->_y += vec.y();
                this->_z += vec.z();
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
}
}
