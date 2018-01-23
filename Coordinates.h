#ifndef COORDINATES_H
#define COORDINATES_H
#include <string>
#include "Headers.h"
struct Coordinates
{
    Coordinates() : x(0), y(0), z(0) {};
    Coordinates(int x, int y, int z) : x(x), y(y), z(z) {};

    int x;
    int y;
    int z;

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
    Vector2f toVector2f()
    {
        return Vector2f(x, y);
    }
    bool operator==(const Coordinates& coord)
    {
        if (this == &coord)
        {
            return true;
        }
        if ((this->x == coord.x) && (this->y == coord.y) && (this->z == coord.z))
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    /*
    bool operator==(const Ratio& ratio2);
    bool operator!=(const Ratio& ratio2);
    bool operator<(const Ratio& ratio2);
    bool operator>(const Ratio& ratio2);
    bool operator<=(const Ratio& ratio2);
    bool operator>=(const Ratio& ratio2);
    */
};
#endif //! COORDINATES_H