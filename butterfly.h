#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <vector>
#include <algorithm>



class level;

class butterfly
{
public:
    butterfly();
    static std::vector <std::pair<int ,int>> mButteflyPos;//массив координат бабочек в комнате
    void reset_resetButterflyPos();// функция очистки массива элементов бабочек
    static bool Is_Muving;

    void add_Butterfly(int&, int&);//функция добовления бабочек в массив
    void delete_Butterfly(int&, int&);//функция удаления бабочки из массива
    void muve_Butterfly(level&);//функция движения бабочек
private:
    int aDl{0};//переменная хранящая кординату движения линии
    int aDc{0};//переменная движения координаты столбца

};

#endif // BUTTERFLY_H
