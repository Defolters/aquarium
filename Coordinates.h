﻿#ifndef COORDINATES_H
#define COORDINATES_H
#include <string>
struct Coordinates
{
    Coordinates() : x(1), y(1), z(1) {}
    Coordinates(int x, int y, int z) : x(x), y(y), z(z) {};

    int x;
    int y;
    int z;
	Coordinates() : x(0), y(0), z(0) {};
	Coordinates(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {};
	std::string toString() 
	{ 
		std::string res;
		res += std::to_string(x);
		res += " ";
		res += std::to_string(y);
		res += " ";
		res += std::to_string(z);
		return res;
	}
    //переопределить сравнение
};
#endif //! COORDINATES_H