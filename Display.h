#ifndef DISPLAY_H
#define DISPLAY_H
#include <thread>
#include "Headers.h"
#include "Aquarium.h"
#include "Effect.h"
// ������������� �������� � 3� ���������, �� ����������� � 2�, ����� ����� ����
//�� ����, ������� ����� � ���, �� ���� z ���������� ����������	//<- � ������ ���� ���� ����� ���, �� �� ������� ������ ���� ������ (����������� ���)

//! �����, ����������� ����������� �� �����
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
