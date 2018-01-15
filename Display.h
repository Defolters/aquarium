#ifndef DISPLAY_H
#define DISPLAY_H
#include "Headers.h"
#include "Aquarium.h"
// ������������� �������� � 3� ���������, �� ����������� � 2�, ����� ����� ����
//�� ����, ������� ����� � ���, �� ���� z ���������� ����������	//<- � ������ ���� ���� ����� ���, �� �� ������� ������ ���� ������ (����������� ���)

//! �����, ����������� ����������� �� �����
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
