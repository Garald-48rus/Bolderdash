#include "appsetings.h"

static const QString levels_path = "levels/"; //переменная хранящая адрес уровней
static const QString pics_path = "pics/"; //переменная хранящая адрес текстур

static std::array<unsigned int, (int)appSetings::eTexturesID::End> lTextures;//массив хранящий текстуры точнее их номера

appSetings::appSetings()
{

}
//-------------------------------------------------
appSetings::~appSetings()
{
  save();
}
//-------------------------------------------------
 appSetings &appSetings:: instanse()//функция возвращающая экземпляр класса
{
    static appSetings res;
    return res;
}
//----------------------------------------------------

void appSetings::load()//функция загрузки сохраненной игры
{
   // ad app settings
      // ...

      // load player info
      // ...

      // load levels info

      mAvailableLevels.clear();//предварительно очищаю массив

      QDirIterator it(levels_path);// передаю итератору путь к файлу

      while (it.hasNext()) //пока есть следующий файл
      {
        it.next();//переход с следующему файлу
        QFileInfo info(it.fileInfo());//получаю инфу о файле
        if(info.completeSuffix() == "lvl") //если есть файл c окончанием lvl
          mAvailableLevels.push_back({info.baseName().toInt(), true});//записываем его в массив(имя и пройден ли)
      }

      std::sort(mAvailableLevels.begin(), mAvailableLevels.end(),//сортирую массив с помощью лямбды
                [](const auto &a, const auto &b) -> bool
                {
                  return a.first < b.first;
                });

      //if(mAvailableLevels.size() == 0)
      //  return;

      //mAvailableLevels[0].second = true;

      _load_textures(); //загружаю текстуры
    }

//------------------------------------------------------
void appSetings::save()//функция сохранения игры
{

}
//-----------------------------------------------------------
unsigned appSetings::screenWidth() const//функция возвращающая ширину
{
    //static unsigned res{1920};
    auto mWidth = mDesctop->width();
    return mWidth;
}
//------------------------------------------------------
unsigned appSetings::screenHeight() const//функция возвращающая высоту
{
    //static unsigned res{1080};
    auto mHeight = mDesctop->height();
    return mHeight;
}
//----------------------------------------------------------------------
QString appSetings::levelsPath()//фунуция возвращающая адрес файла уровней
{
    return levels_path;

}
//-------------------------------------------------------

const std::vector<std::pair<int, bool>> &appSetings::availablesLevels() //ФУНКЦИЯ ВОЗВРАЩАЮЩИАЯ массив уровней
{
  return mAvailableLevels;
}
//----------------------------------------------------------
void appSetings::setQGLWidget(QGLWidget &aQGLWidgeT)//фенкция задает GL контекст
{
   mpGLContext = &aQGLWidgeT;
}
//---------------------------------------------------------
void appSetings::_load_textures()//функция загрузки текстур
{
    glEnable(GL_TEXTURE_2D); //включаю текстуры

    //загрузка текстур
    auto load_lexture = [this](QString aPath) -> unsigned int //передаю путь и указываю точное значение которое будет возврашаться (unsigned int)
     {
       QImage mPngImg; //переменная дря зранения текстуры
       mPngImg.load(aPath); //зашружаю текстуру
       return mpGLContext->bindTexture(mPngImg);//приклепляю текстуру к объекту и возвращаю номер текстуры,
       //для gl библиотеки все текстуры храняться по номерам
     };
      //добовляю в массив текстуры
     lTextures[(int)eTexturesID::Boulder]   = load_lexture(pics_path + "boulder.png");
     lTextures[(int)eTexturesID::Diamond]   = load_lexture(pics_path + "diamond.png");
     lTextures[(int)eTexturesID::Player]    = load_lexture(pics_path + "player.png");
     lTextures[(int)eTexturesID::Wall]      = load_lexture(pics_path + "wall.png");
     lTextures[(int)eTexturesID::Wasp]      = load_lexture(pics_path + "wasp.png");
     lTextures[(int)eTexturesID::Butterfly] = load_lexture(pics_path + "butterfly.png");
     lTextures[(int)eTexturesID::Soil]      = load_lexture(pics_path + "soil.png");
     lTextures[(int)eTexturesID::Explosion] = load_lexture(pics_path + "explosion.png");
     lTextures[(int)eTexturesID::Swamp] = load_lexture(pics_path + "swamp.png");

    glDisable(GL_TEXTURE_2D); //выключаю текстуры

}
//-----------------------------------------------------
 unsigned int appSetings::textureID(eTexturesID aId) //функция вохвращающая текстуру
 {
     return  lTextures[(int)aId];
 }
