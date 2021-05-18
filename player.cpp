#include "player.h"

#include "sound.h"
#include "bolderdash.h"

drawer mDrawer;

player::player()
{

}
//---------------------------------------------
int player::get_Steps()
{
    return mSteps;
}
//-------------------------------------------

void player::player_up(level& aLevel)
{
  _movePlayer(-1, 0,aLevel );
}
//------------------------------------------
void player::player_down(level& aLevel)
{
  _movePlayer(1, 0, aLevel);
}
//-----------------------------------------
void player::player_left(level& aLevel)
{
 _movePlayer(0, -1, aLevel);
}
//-------------------------------------------
void player::player_rigth(level& aLevel)
{
  _movePlayer(0, 1, aLevel);
}
//----------------------------------------------
void player::_movePlayer(int aDl, int aDc, level& aLevel) //функция передвижения игрока
{
      sound mSound;//объект класса звуков
      diamond mDiamond;//объект класса алмазов

        auto &[line, column] = mPlayerPos; //передаю позицию игрока

        auto nl  = line   + aDl;                // next line
        auto nc  = column + aDc;                // next column

        auto nnl = nl + aDl;                    // next next line
        auto nnc = nc + aDc;                    // next next column

        auto coff  = aLevel.get_Columns() * line + column;  // current offset
        auto noff  = aLevel.get_Columns() * nl + nc;        // next offset
        auto nnoff = aLevel.get_Columns() * nnl + nnc;      // next next offset

        auto &f   = aLevel.get_Room(coff);                 // current field
        auto &nf  = aLevel.get_Room(noff);                 // next field
        auto &nnf = aLevel.get_Room(nnoff);                // next next field

       bool isMoving = false; //флаг можно ли двигаться или нет

    switch(nf)
      {
          case Field::eField::SOIL:
       {
           if(nnf == Field::eField::SOIL)
       {
           f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
              //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
          break;
        }
           if(nnf == Field::eField::EMPTY)
        {
           f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
           nf  = Field::eField::PLAYER;
           //nnf = eField::BOX_ON_GOAL;
           isMoving = true;
           //++mBoxesOnGoal;
            break;
         }
            if(nnf == Field::eField::WALL)
         {
             f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
             nf  = Field::eField::PLAYER;
                       //nnf = eField::BOX_ON_GOAL;
              isMoving = true;
                       //++mBoxesOnGoal;
              break;
          }
             if(nnf == Field::eField::WASP)
          {
              f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
              nf  = Field::eField::PLAYER;
               //nnf = eField::BOX_ON_GOAL;
              isMoving = true;
              //++mBoxesOnGoal;
                       break;
            }
              if(nnf == Field::eField::BOULDER)
            {
              f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
              nf  = Field::eField::PLAYER;
              //nnf = eField::BOX_ON_GOAL;
              isMoving = true;
              //++mBoxesOnGoal;
                  break;
           }
              if(nnf == Field::eField::DIAMOND)
           {
              f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
              nf  = Field::eField::PLAYER;
             //nnf = eField::BOX_ON_GOAL;
             isMoving = true;
              //++mBoxesOnGoal;
              break;
                     }
             if(nnf == Field::eField::BUTTERFLY)
          {
             f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
             nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
             //++mBoxesOnGoal;
            break;
         }
            break;
         }
        case Field::eField::EMPTY:
        {
          if(nnf == Field::eField::SOIL)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          if(nnf == Field::eField::EMPTY)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          if(nnf == Field::eField::WALL)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          if(nnf == Field::eField::WASP)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          if(nnf == Field::eField::BOULDER)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          if(nnf == Field::eField::DIAMOND)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          if(nnf == Field::eField::BUTTERFLY)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          if(nnf == Field::eField::SWAMP)
          {
            f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
            nf  = Field::eField::PLAYER;
            //nnf = eField::BOX_ON_GOAL;
            isMoving = true;
            //++mBoxesOnGoal;
            break;
          }
          break;
        }

        case Field::eField::DIAMOND:
            {
              if(nnf == Field::eField::SOIL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::PLAYER;
                line   = nl;
                column = nc;
                mDiamond.delete_Diamond(line , column);
                mDiamond.mDiamond--;
                mSound.play_diamond();
                isMoving = true;
                break;
              }
              if(nnf == Field::eField::EMPTY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::PLAYER;
                line   = nl;
                column = nc;
                mDiamond.delete_Diamond(line , column);
                mDiamond.mDiamond--;
                mSound.play_diamond();
                isMoving = true;
                break;
              }
              if(nnf == Field::eField::WALL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::PLAYER;
                line   = nl;
                column = nc;
                mDiamond.delete_Diamond(line , column);
                mDiamond.mDiamond--;
                mSound.play_diamond();mSound.play_diamond();
                isMoving = true;
                break;
              }
              if(nnf == Field::eField::WASP)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::PLAYER;
                line   = nl;
                column = nc;
                mDiamond.delete_Diamond(line , column);
                mDiamond.mDiamond--;
                mSound.play_diamond();
                isMoving = true;
                break;
              }
              if(nnf == Field::eField::BOULDER)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::PLAYER;
                line   = nl;
                column = nc;
                mDiamond.delete_Diamond(line , column);
                mDiamond.mDiamond--;
                mSound.play_diamond();
                isMoving = true;
                break;
              }
              if(nnf == Field::eField::DIAMOND)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::PLAYER;
                line   = nl;
                column = nc;
                mDiamond.delete_Diamond(line , column);
                mDiamond.mDiamond--;
                mSound.play_diamond();
                isMoving = true;
                break;
              }
              if(nnf == Field::eField::BUTTERFLY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::PLAYER;
                line   = nl;
                column = nc;
                mDiamond.delete_Diamond(line , column);
                mDiamond.mDiamond--;
                mSound.play_diamond();
                isMoving = true;
                break;
              }

                if(nnf == Field::eField::SWAMP)
                {
                  f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                  nf  = Field::eField::PLAYER;
                  line   = nl;
                  column = nc;
                  mDiamond.delete_Diamond(line , column);
                  mDiamond.mDiamond--;
                  mSound.play_diamond();
                  isMoving = true;
                  break;
                }

                break;
              }

            case Field::eField::BUTTERFLY:
            {
              if(nnf == Field::eField::SOIL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::EMPTY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::WALL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::WASP)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::BOULDER)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::DIAMOND)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::BUTTERFLY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;         
            }
            if(nnf == Field::eField::SWAMP)
            {
              f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
              nf  = Field::eField::EXPLOSION;
              game = false;
              break;
            }
            }
            break;
            case Field::eField::WASP:
            {
              if(nnf == Field::eField::SOIL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::EMPTY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::WALL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::WASP)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::BOULDER)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::DIAMOND)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::BUTTERFLY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }       
            if(nnf == Field::eField::SWAMP)
            {
              f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
              nf  = Field::eField::EXPLOSION;
              game = false;
              break;
            }
            break;
          }

            case Field::eField::SWAMP:
            {
              if(nnf == Field::eField::SOIL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::EMPTY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::WALL)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::WASP)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::BOULDER)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::DIAMOND)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
              if(nnf == Field::eField::BUTTERFLY)
              {
                f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                nf  = Field::eField::EXPLOSION;
                game = false;
                break;
              }
            if(nnf == Field::eField::SWAMP)
            {
              f   = (f == Field::eField::PLAYER) ? Field::eField::EMPTY : Field::eField::EMPTY;
              nf  = Field::eField::EXPLOSION;
              game = false;
              break;
            }
            break;
          }


          case Field::eField::WALL:
          case Field::eField::BOULDER:
          case Field::eField::PLAYER:
          case Field::eField::EXPLOSION:
          break;

 }
                    if(isMoving)//если ирок двинулся
                   {  //меняю координаты игрока
                        line   = nl;
                        column = nc;

                       mSound.play_steps();
                      ++mSteps; //увиличиваю кол шагов
                   }
        mBoulder.muve_Boulder(aLevel);//вызываю вункция падения камней
        mDiamond.muve_Diamond(aLevel);//вызываю вункция падения алмазов

}
//-------------------------------------------static-----------------------------
std::pair<int,int> player::mPlayerPos{0,0};
int player::mSteps{0};
int player::set_Diamond{0};//кол алмазов кторые нужно собрать
bool player::game{true};//жив ли игрок
