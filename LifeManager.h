#pragma once
class LifeManager
{
public:
    LifeManager();
    ~LifeManager();
    void printState(); // print number of different creatures..
    void dayPassed();  //! ONE DAY. append day, reduces day of life of creatures and days witout food 
    void checkTheDead();  //! check ** and ** and kill creatures
    void moving();  //! ��� ��������
    void mating(); //!  ��� �����������
private:
    int days;
};

