#ifndef HEADERS_H
#define HEADERS_H
#include <SFML/Graphics.hpp>
using namespace sf;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const double downByUnit = 3;
extern Clock CLOCK; // should be started in main IMMEDIATELY
extern RenderWindow MAIN_WINDOW;
#endif //! HEADERS_H