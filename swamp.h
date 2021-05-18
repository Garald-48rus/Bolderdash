#ifndef SWAMP_H
#define SWAMP_H

#include "vector"
#include "player.h"

class level;

class swamp
{
public:
    swamp();

    static std::vector <std::pair<int ,int>> mSwampPos;//массив координат, ячеек болот в комнате

    static bool Is_Muving;//флаг можно ли болоту расплываться

    void reset_resetSwampPos();// функция очистки массива элементов болота
    void add_Swamp(int&, int&);//функция добовления ячеек болота массив

    void muve_Swamp(level&);//функция движения болота

private:
    int aDl{0};//переменная хранящая кординату движения линии
    int aDc{0};//переменная движения координаты столбца


};

#endif // SWAMP_H
