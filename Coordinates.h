#ifndef COORDINATES_H
#define COORDINATES_H
struct Coordinates
{
    Coordinates() : x(1), y(1), z(1) {}
    Coordinates(int x, int y, int z) : x(x), y(y), z(z) {};

    int x;
    int y;
    int z;
};
#endif //! COORDINATES_H