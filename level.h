#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <QFile>
#include <QTextStream>

#include "appsetings.h"
#include "boulder.h"
#include "diamond.h"
#include "player.h"
#include "butterfly.h"
#include "wasp.h"
#include "swamp.h"

class player;


namespace Field {
/*
Wall                  #   0x23
Player                @   0x40
Diamond               +   0x2b
Wasp                  $   0x24
Boulder               .   0x2a
Butterfly             &   0x2e
Soil                  *
Floor            (Space)  0x20
*/
//класс перечеслений игровых елементов
  enum class eField
   {
     EMPTY
    ,WALL
    ,SOIL
    ,PLAYER
    ,DIAMOND
    ,WASP
    ,BOULDER
    ,EXPLOSION
    ,BUTTERFLY
    ,SWAMP
   };

}
class level
{
friend class drawer;
public:
    level();

         void reset();///сброс уровня
         void load(int);//загрузка уровня
         void load(std::string);//загрузка последенго уровня продолжение игры
         bool isComplete();//проверка пройден ли уровень
         bool isLoad();//проверка загрузился лт уровень

         int& get_Columns();//функция возвращающая кол колонок
         int& get_Lines();//функция возвращающая кол линий
         Field::eField& get_Room(int&);//функция возвращающая ячейку в комнате уровня


         int steps_count() const;//функция возращающая кол ходов
         int goals() const; //функция возращающая кол ящиков
         int boxes_on_goal() const;//функция возращающая кол ящиков на месте

    private:
          int mLevel{-1};//текущий уровень
          int mColumns{0};//кол колонок
          int mLines{0};//кол линий в уровнев

          bool mIsComplete{false};//флаг пройден ли уровень
          bool mIsLoad{false};//флаг загрузился ли уровень

         std::vector<Field::eField> mRoom;//вектор хренения элементов уровня



};

#endif // LEVEL_H
