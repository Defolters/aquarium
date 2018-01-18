#ifndef DISPLAY_H
#define DISPLAY_H
#include <thread>
#include "Headers.h"
#include "Aquarium.h"
#include "Effect.h"
//3д аквариуме, но отображении в 2д, чтобы видно было
//ту рыбу, которая ближе к нам, то есть z координата наименьшая	//<- я сделаю чтоб было видно все, но те которые дальше были меньше (перспектива тип)

//! Класс, реализующий отображение на экран
class Display
{
public:
    Display();
    ~Display();
	std::queue<Effect> effects;
	void PullEvents();
	void DrawAquarium() const;
private:
	const Aquarium& aquarium;
};
#endif  //! DISPLAY_H
