#include "drawer.h"

#include "appsetings.h"

player  mPLayer;// объект класа игрока
diamond mDiamond;//объект класса алмаза
sound mSound; //объект класса звуков

drawer::drawer()
{

}
//--------------------------------------------
 void drawer::draw(const level& aLevel, QGLWidget & aGLWidget)//функция отрисовки уровня
 {
     if(!aLevel.mIsLoad)
         return;

       _draw_grid(aLevel, aGLWidget);
       _draw_objects(aLevel, aGLWidget);
       _draw_statistic(aGLWidget);

 }
//-----------------------------------------
 void drawer::_draw_grid(const level& aLevel, QGLWidget & aGLWidget)//функция отрисовки сетки
  {
     static auto sw =  appSetings::instanse().screenHeight() - 100;
     static auto hw = appSetings::instanse().screenWidth();

       auto lines   = aLevel.mLines;
       auto columns = aLevel.mColumns;

       fw    = 35;//(float)sw / (float)columns;  // field width
       map_w = hw;
       map_h = sw;//fw*lines;

       if(map_w < aLevel.mColumns * fw)
       {
          map_w += (aLevel.mColumns * fw) - map_w;
       }

       if(map_h < aLevel.mLines * fw)
       {
           map_h += (aLevel.mLines * fw) - map_h;
       }

       float x{0.0};//{(appSetings::instanse().screenWidth() )/2.f};
       float y{100.f};

         aGLWidget.qglColor(Qt::darkGray);

         glBegin(GL_LINES);

         for(int r = 0; r <= lines; ++r)
         {
           glVertex2i(x,         y + fw*r);
           glVertex2i(x + map_w, y + fw*r);
         }

         for(int c = 0.f; c <= columns; ++c)
         {
           glVertex2i(x + fw*c, y );
           glVertex2i(x + fw*c, y + map_h);
         }

         glEnd();
  }
//----------------------------------------------------
 void drawer::_draw_objects(const level& aLevel, QGLWidget & aGLWidget)//функция отрисовки объектов
  {


     auto &app = appSetings::instanse(); //создаю ссылку на объект appSetings

     // static auto sw = app.screenHeight() - 100;

      auto lines   = aLevel.mLines;
      auto columns = aLevel.mColumns;

      float fw    = 35;//(float)sw / (float)columns;  // field width

      float x{0.0};//{(appSetings::instanse().screenWidth() - sw)/ 2.f};

      float y{100.f};

      auto tboulder    = app.textureID(appSetings::eTexturesID::Boulder);
      auto tdiamond    = app.textureID(appSetings::eTexturesID::Diamond);
      auto tplayer     = app.textureID(appSetings::eTexturesID::Player);
      auto twall       = app.textureID(appSetings::eTexturesID::Wall);
      auto twasp       = app.textureID(appSetings::eTexturesID::Wasp);
      auto tbutterfly  = app.textureID(appSetings::eTexturesID::Butterfly);
      auto tsoit       = app.textureID(appSetings::eTexturesID::Soil);
      auto texplotion       = app.textureID(appSetings::eTexturesID::Explosion);
      auto tswamp       = app.textureID(appSetings::eTexturesID::Swamp);

      const auto &map = aLevel.mRoom;

     glEnable(GL_TEXTURE_2D);

      aGLWidget.qglColor(Qt::white);

      for(int l = 0; l < lines; ++l)
        for(int c = 0; c < columns; ++c)
        {
          unsigned int textureID = 0;
          switch(map[l*columns + c])
          {
            case Field::eField::BOULDER:
            {
              textureID = tboulder;
              break;
            }
            case Field::eField::DIAMOND:
            {
              textureID = tdiamond;
              break;
            }
            case Field::eField::PLAYER:
            {
              textureID = tplayer;
              break;
            }
            case Field::eField::WALL:
            {
              textureID = twall;
              break;
            }
            case Field::eField::WASP:
            {
              textureID = twasp;
              break;
            }
           case Field::eField::BUTTERFLY:
            {
             textureID = tbutterfly;
            break;
            }
          case Field::eField::SOIL:
           {
            textureID = tsoit;
           break;
           }
          case Field::eField::EXPLOSION:
           {
            textureID = texplotion;
           break;
           }
          case Field::eField::SWAMP:
           {
            textureID = tswamp;
           break;
           }
            case Field::eField::EMPTY:
            {
              break;
            }
          }

          if(textureID != 0)
            aGLWidget.drawTexture(QRectF{x + c*fw, y + l*fw, fw, fw}, textureID);
        }

      glDisable(GL_TEXTURE_2D);
  }
//--------------------------------------------------------

 void drawer::_draw_statistic(QGLWidget & aGLWidget) //функция отрисовки статистики
  {

      mPLayer.set_Diamond = mDiamond.mDiamond - 3;

     static auto font = QFont("Comic Sans MS", 25);
       aGLWidget.qglColor(Qt::blue);

       QString str;

       str = "Шаги        : ";
       str += QString::number(mPLayer.get_Steps());
       aGLWidget.renderText(20, 35, str, font);
       str = "Всего алмазов: ";
       str += QString::number(mDiamond.mDiamond);
       aGLWidget.renderText(20, 75, str, font);

       aGLWidget.qglColor(Qt::darkGreen);
       str = "Нужно собрать алмазов: ";
       str += QString::number(mPLayer.set_Diamond);
       aGLWidget.renderText(350, 75, str, font);

       if(mPLayer.set_Diamond == 0)
       {
           static auto font = QFont("Comic Sans MS", 40);
           aGLWidget.qglColor(Qt::green);
           str = "Уровень пройден!";
           aGLWidget.renderText(350, 40, str, font);

           static auto font2 = QFont("Comic Sans MS", 20);
           aGLWidget.qglColor(Qt::green);
           str = "Намите N чтобы продолжить";
           aGLWidget.renderText(830, 75, str, font2);

           if(wasp::Is_Muving != false || butterfly::Is_Muving != false)
           {
           mSound.play_win();
           }
           mPLayer.game = false;
           wasp::Is_Muving = false;
           butterfly::Is_Muving = false;
           swamp::Is_Muving = false;
       }

       if(!mPLayer.game && mPLayer.set_Diamond != 0)
       {

            static auto font = QFont("Comic Sans MS", 42);
           aGLWidget.qglColor(Qt::red);
           str = "Вы проиграли";
           aGLWidget.renderText(350, 40, str, font);

           static auto font2 = QFont("Comic Sans MS", 20);
           aGLWidget.qglColor(Qt::red);
           str = "Намите R чтобы начать с начала или Esc для выхода";
           aGLWidget.renderText(830, 75, str, font2);
           if(wasp::Is_Muving != false || butterfly::Is_Muving != false)
           {
           mSound.play_loose();
           }
           wasp::Is_Muving = false;
           butterfly::Is_Muving = false;
           swamp::Is_Muving = false;

       }

}

//--------------------------------------------------------
 float drawer::get_map_w()
{
     return map_w;
}
 //------------------------------------------------
 float drawer::get_map_h()
 {
     return map_h;
 }
 //-------------------------static------------------------------
 float drawer::map_w{0.0};
 float drawer::map_h{0.0};
