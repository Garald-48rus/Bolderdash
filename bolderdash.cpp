#include "bolderdash.h"


//------------------- ADDITIONAL FUNCTIONS -------------------------------------
//------------------------------------------------------------------------------
bolderdash::eMenu operator++(bolderdash::eMenu &aMenu)//перегрузка опнратора ++ для перемещения по меню вверх
{
  aMenu = bolderdash::eMenu(int(aMenu) + 1);

  if(aMenu == bolderdash::eMenu::END )
  {
     aMenu = bolderdash::eMenu::PLAY;
     return aMenu;
  }
  return aMenu;
}
//------------------------------------------------------------------------------
bolderdash::eMenu operator--(bolderdash::eMenu &aMenu)//перегрузка оператора -- вниз
{
  aMenu = bolderdash::eMenu(int(aMenu) - 1);

  if(aMenu == bolderdash::eMenu::START )
  {
     aMenu = bolderdash::eMenu::EXIT;
     return aMenu;
  }
  return aMenu;
}

//------------------------------------------------------------------------------
int menuStateToInt(const bolderdash::eMenu &aMenu)//ковертирую пункты меню в int
{
  switch(aMenu)
  {
    case bolderdash::eMenu::START:       return (int)bolderdash::eMenu::START;
    case bolderdash::eMenu::END:         return (int)bolderdash::eMenu::END;
    case bolderdash::eMenu::SELECT_LEVEL:return (int)bolderdash::eMenu::SELECT_LEVEL;
    case bolderdash::eMenu::PLAY:        return (int)bolderdash::eMenu::PLAY;
    case bolderdash::eMenu::PLAYER_STAT: return (int)bolderdash::eMenu::PLAYER_STAT;
    case bolderdash::eMenu::EXIT:        return (int)bolderdash::eMenu::EXIT;
  }
  return -1;
}
//------------------------------------------------------------------------------
bolderdash::eState menuStateToGameState(const bolderdash::eMenu &aMenu)//функция перехода из основного меню в игровое меню
{
  switch(aMenu)
  {
    case bolderdash::eMenu::START:
    case bolderdash::eMenu::END:         return bolderdash::eState::MENU;

    case bolderdash::eMenu::SELECT_LEVEL:return bolderdash::eState::SELECT_LEVEL;
    case bolderdash::eMenu::PLAY:        return bolderdash::eState::PLAY;
    case bolderdash::eMenu::PLAYER_STAT: return bolderdash::eState::PLAYER_STAT;
    case bolderdash::eMenu::EXIT:        return bolderdash::eState::EXIT;
  }
  return bolderdash::eState::MENU;
}


bolderdash::bolderdash()
       {
    //фиксированный размер окна нельзя изменить
     //setSizePolicy(QSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed));
     //размер окна
     //setFixedSize(800,600);
     //каждые 2000 млс таймер подает сигнал
    mTimer.start(33);
    //соединяю сигнал timeout cо слото
    connect(&mTimer,SIGNAL(timeout()), this, SLOT(repaint()));
      /*передаю текущий объект точнее срез QGLWidget иницилизация меню*/
     appSetings::instanse().setQGLWidget(*this);
       mvMenu.push_back({eMenu::PLAY,        "Играть"});
       mvMenu.push_back({eMenu::SELECT_LEVEL,"Выбор уровня"});
       mvMenu.push_back({eMenu::PLAYER_STAT, "Статистика"});
       mvMenu.push_back({eMenu::EXIT,        "Выход"});



}
//---------------------------------------------------//перекрываю функцию иницилицации окно(2D<3D..)
void bolderdash::initializeGL()
{
     static  auto w = appSetings::instanse().screenWidth();
     static auto h = appSetings::instanse().screenHeight();

         //самый минимум 2D режим
         //размер окна
         glOrtho(0, w, h, 0, 0, 1);

         glDisable(GL_DEPTH_TEST);
          glEnable(GL_BLEND);
          glEnable(GL_LINE_SMOOTH);
          glEnable(GL_POINT_SMOOTH);
          glEnable(GL_SMOOTH);
          glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
          //важно включить текстуру
          glEnable(GL_TEXTURE_2D);
          //загружаею файл уровней
          appSetings::instanse().load();
}
//----------------------------------------------------------//перекрываю функцию изменения размеров окна(пересчитывает размеры прапоции если окно меняет размер)
void bolderdash::resizeGL(int aW, int aH)
{
     w = appSetings::instanse().screenWidth();
     h = appSetings::instanse().screenHeight();

     glLoadIdentity();
     glViewport(0, 0, (GLint)aW, (GLint)aH);
     //если размер окна изменился вызываю opgl функцию она пересчитывает пропорции
     glOrtho(0, w, h, 0, 0, 1);

}
//--------------------------------------------------------------//перекрываю функцию прорисовки окна
void bolderdash::paintGL()
{
           //очищаю экран
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          //цвет окна
          qglClearColor(Qt::darkGray);


          _proccesing();

          _draw();         
}
//------------------------------------------------------------------//перекрываю функцию обработки клавиатуры
void bolderdash::keyReleaseEvent(QKeyEvent * apKeyEvent)
{
    //выбор пункта меню
    switch (mState)
    {
        case eState::MENU:
        {
        _key_released_menu(apKeyEvent->key());
          break;
        }
        case eState::SELECT_LEVEL:
        {
        _key_released_menu_select_level(apKeyEvent->key());
          break;
        }
        case eState::PLAYER_STAT:
        {
        _key_released_player_stat(apKeyEvent->key());
          break;
        }
        case eState::PLAY:
        {
        _key_released_play(apKeyEvent->key());
          break;
        }
        case eState::EXIT:
        {

          close();
          break;
        }
      }

}
//------------------------------------------------------------------//функция процессов вычислениы считиванияюю

void bolderdash::_proccesing()
{
    //выбор пункта меню
    switch (mState)
      {
        case eState::MENU:
        {
          break;
        }
        case eState::SELECT_LEVEL:
        {
          break;
        }
        case eState::PLAYER_STAT:
        {
          break;
        }
        case eState::PLAY:
        {
          break;
        }
        case eState::EXIT:
        {
          close();
          break;
        }
      }
}
//------------------------------------------------------ //отрисовка действий
void bolderdash::_draw()
{
    //выбор пункта меню и его отрисовка
    switch (mState)
      {
        case eState::MENU:
        {
        _draw_menu();
          break;
        }
        case eState::SELECT_LEVEL:
        {
        _draw_menu_select_level();
          break;
        }
        case eState::PLAYER_STAT:
        {
        _draw_player_stat();
          break;
        }
        case eState::PLAY:
        {
        // mLevel.load(1);
        _draw_play();
          break;
        }
        case eState::EXIT:
        {

          close();
          break;
        }
      }

}
//----------------------------------------------------------------------------//функция отрисовки пункта меню

void bolderdash::_draw_menu()
{
    // ТОЧКА начала отрисовки меню
    static auto app_w = appSetings::instanse().screenWidth() / 2.f;
     static auto app_h = appSetings::instanse().screenHeight() / 3.f;
       //шрифт если пункт меню не выбран
     static auto font          = QFont("Sans", 45);
     //шрифт если пункт меню  выбран
     static auto font_selected = QFont("Sans", 50);
     //для выбраного шрифта устанавливаю жиность
     font_selected.setBold(true);
    //сдвигаю точку отрисовки по оси х
     auto x   = app_w - 200;
     auto y   = app_h ;
     //смещение по оси у
     auto dy  = 85.f;
     //переменная хранящая колличество элементов меню
     int  end = mvMenu.size();
     //пробегаем по меню
     for(int i = 0; i < end; ++i)
     {
         //если пункт меню совпадает с выбраным
       if(i == menuStateToInt(mCurrentMenu))
       {
           //подсвечиваеи его
         qglColor(Qt::red);
         //стандатная функция отрисовки текста.....  меняю шрифт
         renderText(x, y, mvMenu[i].second.c_str(), font_selected);
       }
       else
       {
         qglColor(Qt::white);
         renderText(x, y, mvMenu[i].second.c_str(), font);
       }
       //после прохода смещаю по оси у
       y += dy;
     }
}
//---------------------------------------------------------------------//функция отрисовки пункта выбор уровня
void bolderdash::_draw_menu_select_level()
{
     auto &app = appSetings::instanse();
     static auto app_w = app.screenWidth() / 2.f;
     static auto app_h = app.screenHeight() / 3.f;
     //получаю уровни
     auto &levels = app.availablesLevels();
     //переменная кол уровней
     int  l_count = (int)levels.size();
     //если уровней нет
     if(levels.empty())
       return;

     //шрифты для выброного уровня и нет
     static auto font          = QFont("Comic Sans MS", 25);
     static auto font_selected = QFont("Comic Sans MS", 30);
     font_selected.setBold(true);

     int tmp = (mSelectLevelIndex - 6);
     int start = tmp < 0 ? 0 : tmp;

     //типо скролл не более 6 елементов
     tmp = (start + 6);
     int end = (tmp < l_count) ? tmp : l_count - 1;

     //переменные для отрисовки примерно по соредине экрана
     auto x   = app_w - 100;
     auto y   = app_h;
     auto dy  = 45.f;

     for(int i = start; i <= end; ++i)
     {
         //декомпозиция с++ 17
       const auto &[lvl, isLock] = levels[i];
       //формирую строку (уровень..номер)
       QString item_str = "Уровень " + QString::number(lvl);
      //если номер уровня выбран его подсвечиваю....
       QFont  &rf = (i == mSelectLevelIndex) ? font_selected : font;

       Qt::GlobalColor color = Qt::gray;

       if(i == mSelectLevelIndex)
       {
         if(isLock == true)
           color = Qt::red;
       }
       else
       {
         if(isLock == true)
           color = Qt::white;
       }

       qglColor(color);
       renderText(x, y, item_str, rf);

       y += dy;
     }

}
//---------------------------------------------------------------//функция отрисовки пункта статистика игрока
void bolderdash::_draw_player_stat()
{

}
//-------------------------------------------------------------------------//функция отрисовки пункта играть
void bolderdash::_draw_play()
{
   mDrawer.draw(mLevel, *this);

   mWasp.muve_Wasp(mLevel);

   index += 0.4;

   if(index > 1)
   {
   mButterfly.muve_Butterfly(mLevel);
   index =0.0;
   }

   countrer += 0.01;

   if(countrer > 1.0)
   {
       mSwamp.muve_Swamp(mLevel);
       countrer = 0.0;
   }

}
//----------------------------------------------------------------------------------//функция обработко клавиш когда мы находимися в меню
void bolderdash::_key_released_menu(int aKey)
{
    switch (aKey) {

    case Qt::Key_Up :
    {
      -- mCurrentMenu;
        break;
    }
    case Qt::Key_Down:
    {
        ++mCurrentMenu;
        break;
    }
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        //переводим наше стартовое положение в меню в текущее
       mState = menuStateToGameState(mCurrentMenu);
        break;
    }

    }
}
//----------------------------------------------------------------------//функция обработко клавиш когда мы находимися в пункте выборе уровня
void bolderdash::_key_released_menu_select_level(int aKey)
{
    const auto &levels = appSetings::instanse().availablesLevels();
    //переменная кол уровней
     int levels_count = (int)levels.size();
    switch(aKey)
      {
        case Qt::Key_Up:
        {
        --mSelectLevelIndex;
         if(mSelectLevelIndex < 0)
           mSelectLevelIndex = 0;
          break;
        }
        case Qt::Key_Down:
        {
        ++mSelectLevelIndex;
         if(mSelectLevelIndex >= levels_count)
           mSelectLevelIndex = levels_count - 1;
          break;
        }
        case Qt::Key_Enter:
        case Qt::Key_Return:
        {
        if(mSelectLevelIndex >= 0)
             {
               if(mSelectLevelIndex >= levels_count)
                 break;

               const auto & [lvl, isLock] = levels[mSelectLevelIndex];
               if(isLock)
               {
                   mLevel.load(lvl);

                   mState = eState::PLAY;
               }
             }
          break;
        }
        case Qt::Key_Escape:
        {
          mState = eState::MENU;
          break;
        }
      }
}
//---------------------------------------------------------------------
void bolderdash::_key_released_player_stat(int aKey)//функция обработко клавиш когда мы находимися в пункте статистике игрока
{
    switch(aKey)
     {
       case Qt::Key_Escape:
       {
         mState = eState::MENU;
         break;
       }
     }
}
//----------------------------------------------------------------------
void bolderdash::_key_released_play(int aKey) //функция обработко клавиш когда мы находимися в пункте играть
{
    switch(aKey)
      {
        case Qt::Key_Up:
        {
        if(mPlayer.game)
       mPlayer.player_up(mLevel);
          break;
        }
        case Qt::Key_Down:
        {
        if(mPlayer.game)
       mPlayer.player_down(mLevel);
          break;
        }
        case Qt::Key_Left:
        {
        if(mPlayer.game)
        mPlayer.player_left(mLevel);
          break;
        }
        case Qt::Key_Right:
        {
        if(mPlayer.game)
        mPlayer.player_rigth(mLevel);
          break;
        }
        case Qt::Key_Escape:
        {
          mState = eState::MENU;
          break;
        }
        case Qt::Key_R:
        {
        mLevel.reset();
          break;
        }
      case Qt::Key_N:
      {
      if(mPlayer.set_Diamond == 0)
      {
        mLevel.load(lvl += 1);
        mPlayer.game = true;
      }

      break;
      }
        break;
      }
}
//------------------------------------------------------------
float bolderdash::get_w()
{
    return w;
}
//----------------------------------------------
float bolderdash::get_h() const
{
    return h;
}

//----------------------------------------------
void bolderdash::set_Up_w( const float & aW)
{
    w = aW;
}
//-----------------------------------------------
void bolderdash::set_Down_w(const float & aW)
{
  w -= aW;
}
//--------------------------------------------------
void bolderdash::set_Up_h(const float & aH)
{
  h = aH;
}
//-----------------------------------------------
void set_Down_h(const float &)
{

}

//-----------------------------static---------------------------------------------------
float bolderdash::w{0.0};
float bolderdash::h{0.0};


