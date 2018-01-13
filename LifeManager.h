#pragma once
class LifeManager
{
public:
    LifeManager();
    ~LifeManager();
    void printState(); // print number of different creatures..
    void dayPassed();  //! ONE DAY. append day, reduces day of life of creatures and days witout food 
    void checkTheDead();  //! check ** and ** and kill creatures
    void moving();  //! ход движение
    void mating(); //!  ход размножение
private:
    int days;
};

