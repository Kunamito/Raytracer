/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** Color lib for Raytracer
*/

#include <iostream>

namespace Raytracer {
    class Color {
        public :
            // Constructor for our class
            Color(double red, double green, double blue, double alpha) : _r(red), _g(green), _b(blue), _a(alpha) {}

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

            // Write our Color
            static void write_color(std::ostream& out, const Color& pixel_color) {
                int r = pixel_color.r();
                int g = pixel_color.g();
                int b = pixel_color.b();
                int a = pixel_color.a();

                // Translate the [0,1] component values to the byte range [0,255].
                int rbyte = int(255.999 * r);
                int gbyte = int(255.999 * g);
                int bbyte = int(255.999 * b);
                int abyte = int(255.999 * a);

                // Write out the pixel color components.
                out << rbyte << ' ' << gbyte << ' ' << bbyte << ' ' << abyte << '\n';
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
