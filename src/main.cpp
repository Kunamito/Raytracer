/*
** EPITECH PROJECT, 2025
** Raytracing
** File description:
** main.cpp
*/


#include <iostream>
#include "Utils/Color.hpp"
#include "Math/Vector.hpp"

int main(int ac, const char * const * argv) {
        // Temporary
        double ratio = 16.0 / 9.0;
        int image_width = 400;
        int image_height = int(image_width / ratio);

        // Render
        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; j++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; i++) {
                Raytracer::Color pixel_color = Raytracer::Color(double(i)/(image_width-1), double(j)/(image_height-1), 0, 255);
                Raytracer::Color::write_color(std::cout, pixel_color);
            }
        }

        std::clog << "\rDone.                 \n";
}
