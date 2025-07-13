/*
** EPITECH PROJECT, 2025
** Raytracer
** File description:
** Camera
*/

#pragma once

class Camera {
    public:
        Camera(double width, double length) : _ImageLength(length), _ImageWidth(width) {
            this->_Ratio = 16.0 / 9.0;
        }
        ~Camera() = default;

    protected:
    private:
        double _ImageWidth;
        double _ImageLength;
        double _Ratio;
};
