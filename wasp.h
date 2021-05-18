#ifndef WASP_H
#define WASP_H

#include <vector>

#include "level.h"


class wasp
{
public:
    wasp();
    static std::vector <std::pair<int ,int>> mWaspPos;//массив координат ос в комнате
    static bool Is_Muving;

    void reset_WaspPos();// функция очистки массива элементов ос
    void add_Wasp(int&, int&);//функция добовления ос в массив
    void delete_Wasp(int&, int&);//функция удаления осы из массива
    void muve_Wasp(level&);//функция движения ос

private:
    int aDl{0};//переменная хранящая кординату движения линии
    int aDc{0};//переменная движения координаты столбца



};

#endif // WASP_H
