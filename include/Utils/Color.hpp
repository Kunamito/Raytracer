/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Color lib for Raytracer
*/

#pragma once

#include <cmath>
#include <iostream>
#include "Interval.hpp"

namespace Raytracer {
    class Color {
        public :
            // Constructor for our class
            Color(double red, double green, double blue, double alpha) : _r(red), _g(green), _b(blue), _a(alpha) {}
            Color(double red, double green, double blue) : _r(red), _g(green), _b(blue), _a(255) {}

            // Getter for all degree of color
            double r() const { return _r; }
            double g() const { return _g; }
            double b() const { return _b; }
            double a() const { return _a; }

            // Setter for new degree of color
            Color operator+=(Color color) {
                this->_r += color.r();
                this->_g += color.g();
                this->_b += color.b();
                this->_a += color.a();
                return *this;
            }


            Color operator*=(double mult) {
                this->_r *= mult;
                this->_g *= mult;
                this->_b *= mult;
                this->_a *= mult;
                return *this;
            }

            Color operator/=(double mult) {
                return *this *= 1 / mult;
            }


            void setColorX(double x) {
                this->_r = x;
            }

            void setColorY(double y) {
                this->_g = y;
            }

            void setColorZ(double z) {
                this->_b = z;
            }

            static inline double linear_to_gamma(double linear_component) {
                if (linear_component > 0) {
                    return std::sqrt(linear_component);
                }
                return 0;
            }
            // Write our Color
            static void write_color(std::ostream& out, const Color& pixel_color) {
                double r = pixel_color.r();
                double g = pixel_color.g();
                double b = pixel_color.b();

                // Apply gamma to color
                r = linear_to_gamma(r);
                g = linear_to_gamma(g);
                b = linear_to_gamma(b);

                // Translate the [0,1] component values to the byte range [0,255].
                static const Utils::interval intensity(0.000, 0.999);
                int rbyte = int(255.999 * intensity.clamp(r));
                int gbyte = int(255.999 * intensity.clamp(g));
                int bbyte = int(255.999 * intensity.clamp(b));

                // Write out the pixel color components.
                out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
            }

        private :
            double _r;
            double _g;
            double _b;
            double _a;
    };

    inline std::ostream& operator<<(std::ostream& out, const Color& color) {
        return out << color.r() << ' ' << color.g() << ' ' << color.b() << " " << color.a();
    }

    inline Color operator+(const Color& our, const Color& color) {
        return Color(our.r() + color.r(), our.g() + color.g(), our.b() + color.b(), our.a() + color.a());
    }

    inline Color operator-(const Color& our, const Color& color) {
        return Color(our.r() - color.r(), our.g() - color.g(), our.b() - color.b(), our.a() + color.a());
    }

    inline Color operator*(const Color& our, const Color& color) {
        return Color(our.r() * color.r(), our.g() * color.g(), our.b() * color.b(), our.a() + color.a());
    }

    inline Color operator*(double t, const Color& color) {
        return Color(t*color.r(), t*color.g(), t*color.b(), t*color.a());
    }

    inline Color operator*(const Color& color, double t) {
        return t * color;
    }

    inline Color operator/(const Color& color, double t) {
        return (1/t) * color;
    }
}
