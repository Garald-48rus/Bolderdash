#ifndef DRAWER_H
#define DRAWER_H

#include <QGLWidget>
#include "level.h"
#include "sound.h"

class player;
class sound;
class drawer
{
public:
    drawer();

    drawer(drawer &) = delete;
    drawer(drawer &&) = delete;

    void draw(const level&, QGLWidget &);//функция отрисовки уровня

    float get_map_w();
    float get_map_h();

private:
      void _draw_grid(const level&, QGLWidget &);//функция отрисовки сетки
      void _draw_objects(const level&, QGLWidget &);//функция отрисовки объектов
      void _draw_statistic(QGLWidget &);//функция отрисовки статистики

    private:

      bool mTextureIsLoad{false};//флаг загрузки текстуры

      static float map_w;
      static float map_h;
      float fw{0.0};


};

#endif // DRAWER_H
