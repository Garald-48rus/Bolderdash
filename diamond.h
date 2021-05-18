#ifndef DIAMOND_H
#define DIAMOND_H
#include <vector>
#include <algorithm>
#include "level.h"
#include "butterfly.h"
#include "boulder.h"
#include "wasp.h"

class level;


class diamond
{
public:
    diamond();
    static std::vector <std::pair<int ,int>> mDiamondPos;//массив координат алмазов в комнате
    static int mDiamond;// переменная количества алмазов в комнате
    void reset_resetDiamondPos();// функция очистки массива элементов алмазов

    void muve_Diamond(level&);//функция падения алмазов

    void delete_Diamond(int&, int&);//функция удаления алмаза из массива
    void add_Diamond(int&, int&);//функция добовления алмаза в массив

private:

     butterfly mButterfly; //обект класса бабочки
     Boulder mBoulder; //объект класса камней



};

#endif // DIAMOND_H
