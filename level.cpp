#include "level.h"
#include "player.h"
#include "sound.h"


level::level()
{

}
//-----------------------------------------------------------

int& level::get_Columns()
{
    return  mColumns;
}
//----------------------------------------------------------------------------
int& level::get_Lines()
{
    return mLines;
}
//----------------------------------------------------------
Field::eField& level::get_Room(int& index)
{

    return mRoom[index];

}
//----------------------------------------------------------------------
void level::reset()
{
    load(mLevel);
}
//------------------------------------------------------------------------------
void level::load(int aLevel)
{

 const auto &lp =  appSetings::instanse().levelsPath();//получаю имя файла хранящий уровни

 QString lvl_path = lp + QString::number(aLevel) + ".lvl";//формирую полный адрес уровня

  QFile   file(lvl_path);

  player mPlayer;//создаю объект класса игрока
  Boulder mBoulder;//объект класса камненй
  diamond mDiamond; //объект класса алмазов
  butterfly mButterfly; //объект класса бабочек
  wasp mWasp; //объект класса oс
  sound mSound; //объект класса звуков
  swamp mSwamp; //объект класса болото

  mBoulder.reset_resetBoulderPos();//очищаю массив камней
  mPlayer.mSteps = 0;//обнуляю кол шагов
  mPlayer.game = true;//флаг моно играть ставлю в true
  mDiamond.reset_resetDiamondPos(); //очищаю массив алмазов
  mDiamond.mDiamond = 0;//обнуляю количество алмазов комнате
  mButterfly.reset_resetButterflyPos();//очищаю массив бабочек
  mButterfly.Is_Muving = true;
  mWasp.reset_WaspPos();//очищаю массив ос
  mWasp.Is_Muving = true;
  mSwamp.reset_resetSwampPos();//очищаю массив элементо болота
  mSwamp.Is_Muving = false;
  mSound.stop();

  mIsLoad       = false;
  mIsComplete   = false;


  file.open(QIODevice::ReadWrite);

  if(file.isOpen())
  {
    mRoom.clear();

    QTextStream in(&file);
    in >> mLevel;
    in >> mColumns;
    in >> mLines;

    std::vector<Field::eField> tmpRoom(mColumns * mLines, Field::eField::EMPTY);//заполняю временный вектор  пустыми полями

    in.readLine();

    for(int i = 0; i < mLines; ++i)
    {
      QString line;
      line = in.readLine();

      int  column = 0;
      int  end    = line.size();

      while(column != end)
      {
        switch (line[column].toLatin1())
        {
          case '#': // Wall
          {
            tmpRoom[mColumns * i + column] = Field::eField::WALL;
            break;
          }
          case '*': // Soil
          {
          tmpRoom[mColumns * i + column] = Field::eField::SOIL;
          break;
          }
          case '@': // Player
          {
            tmpRoom[mColumns * i + column] = Field::eField::PLAYER;

            mPlayer.mPlayerPos.first = i;//получаю координаты игрока в комнате
            mPlayer.mPlayerPos.second = column;

            break;
          }
          case '+': // diamond
          {
            tmpRoom[mColumns * i + column] = Field::eField::DIAMOND;

            mDiamond.add_Diamond(i, column);//добовляю алмаз в массив
            ++mDiamond.mDiamond;//увиличиваю кол алмазов в комнате

            break;
          }
          case '$': // Wasp
          {
            tmpRoom[mColumns * i + column] = Field::eField::WASP;

            mWasp.add_Wasp(i, column); //добовляю ос в массив
            break;
          }
          case '.': // Boulder
          {
            tmpRoom[mColumns * i + column] =  Field::eField::BOULDER;

            mBoulder.add_Boulder(i, column); //передаю координаты камней в комнате в массив камней

            break;
          }
          case '&': // BUTTERFLY
          {
            tmpRoom[mColumns * i + column] = Field::eField::BUTTERFLY;

            ++mDiamond.mDiamond;//увиличиваю кол алмазов в комнате(бабочка преврашается в алмаз)
            mButterfly.add_Butterfly(i, column);//добовляю бабочек в массив

            break;
          }

        case '^': // Swamp
        {
          tmpRoom[mColumns * i + column] = Field::eField::SWAMP;

          mSwamp.add_Swamp(i, column); //добовляю элемент болота в массив в массив
          mSwamp.Is_Muving = true;
          break;
        }
          case ' ': // Floor or Empty
          {
            tmpRoom[mColumns * i + column] = Field::eField::EMPTY;
            break;
          }
      }
      ++column;
    }
  }
    mRoom.swap(tmpRoom); //меняю данные из временного вектора в нашу комнату
    mIsLoad = true;//ставлю флаг загрузки уровня в true
  }

  file.close();

}
//------------------------------------------------------------------------------
void level::load(std::string)
{


}
//------------------------------------------------------------------------------
bool level::isComplete()
{
  return mIsComplete;
}
//------------------------------------------------------------------------------
bool level::isLoad()
{
  return mIsLoad;
}
//------------------------------------------------------------------------------

