#ifndef PLAYER_H
#define PLAYER_H


#include "level.h"


class player
{

public:
    player();

    //функции упрвления игроком
   void player_up(level&);
   void player_down(level&);
   void player_left(level&);
   void player_rigth(level&);

   int get_Steps();//фуекция возвращающая кол шагов

   static std::pair<int,int>  mPlayerPos;//хранение позиции игрока
   static int mSteps;//кол зделаных ходов
   static int set_Diamond;//кол алмазов кторые нужно собрать

   static bool game;//жив ли игрок

private:
      void _movePlayer(int, int,level&); //функция смещения по осям

      Boulder mBoulder;//объект класса камней

};

#endif // PLAYER_H
