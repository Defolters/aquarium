#ifndef DISPLAY_H
#define DISPLAY_H
#include <thread>
#include "Headers.h"
#include "Aquarium.h"
#include "Effect.h"
//3д аквариуме, но отображении в 2д, чтобы видно было
//ту рыбу, которая ближе к нам, то есть z координата наименьшая	//<- я сделаю чтоб было видно все, но те которые дальше были меньше (перспектива тип)

/*!
\brief Класс, реализующий отображение на экран

нужны комменты к полям и методам, чтобы я мог помочь и понять.
*/
class Display
{
public:
    Display(Aquarium* target, Texture*);
    ~Display();
	void PullEvents() const;
	void DrawAquarium() const;
private:
	Texture* plankton;
	//const Aquarium& aquarium;
    Aquarium* aquarium;
};
#endif  //! DISPLAY_H
