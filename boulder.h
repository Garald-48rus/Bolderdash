#ifndef BOULDER_H
#define BOULDER_H

#include <vector>
#include <algorithm>


class level;

class Boulder
{
public:
    Boulder();
    static std::vector <std::pair<int ,int>> mBoulderPos;//массив координат камней в комнате
    void reset_resetBoulderPos();// функция очистки массива элементов камней

    void muve_Boulder(level&);//функция падения камней
    void add_Boulder(int&, int&);//функция добовления камня в массив

private:
    void delete_Boulder(int&, int&);//функция удаления камня из массива

};
#endif // BOULDER_H
