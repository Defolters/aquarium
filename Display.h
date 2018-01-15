#ifndef DISPLAY_H
#define DISPLAY_H
#include "Headers.h"
#include "Aquarium.h"
// ѕреподователь говорила о 3д аквариуме, но отображении в 2д, чтобы видно было
//ту рыбу, котора€ ближе к нам, то есть z координата наименьша€	//<- € сделаю чтоб было видно все, но те которые дальше были меньше (перспектива тип)

//!  ласс, реализующий отображение на экран
class Display
{
public:
    Display();
    ~Display();
	void DrawAquarium() const;
private:
	const Aquarium& aquarium;
};
#endif  //! DISPLAY_H
