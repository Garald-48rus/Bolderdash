#ifndef BOLDERDASH_H
#define BOLDERDASH_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>

#include "appsetings.h"
#include "level.h"
#include "drawer.h"
#include "sound.h"

class bolderdash: public QGLWidget
{
public:
    //перечисление состояния игры
       enum class eState
        {
          MENU //меню
         ,SELECT_LEVEL //выбор уровня
         ,PLAYER_STAT //статистика игрока
         ,PLAY //играть
         ,EXIT //выход
        };
       //перечесления меню на каком пункте мы нажали энтер
        enum class eMenu
        {
          START = -1
         ,PLAY //0
         ,SELECT_LEVEL //1
         ,PLAYER_STAT //2
         ,EXIT //3
         ,END //4
        };


public:
    bolderdash();

       void initializeGL()                    override;//перекрываю функцию иницилицации окно(2D<3D..)
       void resizeGL(int w, int h)            override;//перекрываю функцию изменения размеров окна(пересчитывает размеры прапоции если окно меняет размер)
       void paintGL()                         override;//перекрываю функцию прорисовки окна
       void keyReleaseEvent(QKeyEvent *)      override;//перекрываю функцию обработки клавиатуры

private:
  void _proccesing();//функция процессов вычислениы считиванияюю
  void _draw(); //отрисовка действий

  void _draw_menu();//функция отрисовки пункта меню
  void _draw_menu_select_level();//функция отрисовки пункта выбор уровня
  void _draw_player_stat();//функция отрисовки пункта статистика игрока
  void _draw_play();//функция отрисовки пункта играть


   void _key_released_menu(int);//функция обработко клавиш когда мы находимися в меню
   void _key_released_menu_select_level(int);//функция обработко клавиш когда мы находимися в пункте выборе уровня
   void _key_released_player_stat(int);//функция обработко клавиш когда мы находимися в пункте статистике игрока
   void _key_released_play(int); //функция обработко клавиш когда мы находимися в пункте играть

public:
   static float get_w();
   float get_h() const;

   static void set_Up_w( const float &);
   void set_Down_w(const float &);

   void set_Up_h(const float &);
   void set_Down_h(const float &);

private:
   int mSelectLevelIndex{0};//переменная выбора уровня

   static  float  w;
   static  float  h;

   int lvl{1};//счечик уровней

   level mLevel; //объект класса  уровней
   drawer mDrawer;  //объект класса отрисовки
   player mPlayer; //oбъект класса игрока
   butterfly mButterfly; //объект класса бабочек
   wasp mWasp; //объект класса ос
   swamp mSwamp; //объект класса болота

  eState  mState{eState::MENU};//стартовое состояние мнгю
  eMenu   mCurrentMenu{eMenu::PLAY};;//текущее сосиояние меню

  QTimer mTimer;//объект таймера

  float countrer{0.0};
  float index{0.0};

  std::vector<std::pair<eMenu, std::string>> mvMenu;//вектор пар, пукт меню и что надо нарисовать
};

#endif // BOLDERDASH_H
