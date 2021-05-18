#include "wasp.h"
#include "player.h"
#include "sound.h"



wasp::wasp()
{

}
//--------------------------------------------------------
void wasp::reset_WaspPos()// функция очистки массива элементов ос
{
  mWaspPos.clear();
}
//--------------------------------------------------------
void wasp::wasp::add_Wasp(int& aFirst, int& aSecond)//функция добовления ос в массив
{
    std::pair<int, int> itr{aFirst, aSecond};

    mWaspPos.push_back(itr);
}
//----------------------------------------------------------
void wasp::delete_Wasp(int& aFirst, int& aSecond)//функция удаления осы из массива
{
    std::pair <int, int>  index{aFirst, aSecond};

    auto itr = std::find(mWaspPos.begin(), mWaspPos.end(), index);

    mWaspPos.erase(itr);
}
//----------------------------------------------
void wasp::muve_Wasp(level& aLevel)//функция движения ос
{
    if(Is_Muving)
    {
    player mPlayer; //объект класса игрока


    for(auto itr :mWaspPos)
    {
        auto &[line, column] = itr;

        aDl = rand()% 3 + -1;
        aDc = rand()% 3 + -1;
        while ((aDl == 0 && aDc == 0) || (aDl != 0 && aDc != 0))
        {
            aDl = rand()% 3 + -1;
            aDc = rand()% 3 + -1;
        }


           auto nl  = line + aDl;                // next line
           auto nc  = column + aDc;                // next column

                auto nnl = nl  + aDl;                    // next next line
                auto nnc = nc + aDc;                    // next next column

                auto coff  = aLevel.get_Columns() * line + column;  // current offset
                auto noff  = aLevel.get_Columns() * nl + nc;        // next offset
                auto nnoff = aLevel.get_Columns() * nnl + nnc;      // next next offset

                auto &f   = aLevel.get_Room(coff);                 // current field
                auto &nf  = aLevel.get_Room(noff);                 // next field
                auto &nnf = aLevel.get_Room(nnoff);                // next next field

    switch(nf)
             {
               case Field::eField::EMPTY:
              {
               if(nnf == Field::eField::SOIL)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::WASP;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }
               if(nnf == Field::eField::EMPTY)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::WASP;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }

               if(nnf == Field::eField::WALL)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::WASP;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }

               if(nnf == Field::eField::WASP)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::WASP;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }

               if(nnf == Field::eField::BOULDER)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::WASP;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }

               if(nnf == Field::eField::WASP)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::WASP;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }

               if(nnf == Field::eField::BUTTERFLY)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::WASP;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }

               if(nnf == Field::eField::EXPLOSION)
               {
                 f   = (f == Field::eField::WASP) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Wasp(line, column);
                 line   = nl;
                 column = nc;
                 add_Wasp(line, column);
                break;
               }
              break;
            }

    case Field::eField::PLAYER:
    {
        if(nnf == Field::eField::SOIL)
        {
          f   = (f == Field::eField::WASP) ? Field::eField::WASP : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
        }

        if(nnf == Field::eField::WALL)
        {
          f   = (f == Field::eField::BUTTERFLY) ? Field::eField::BUTTERFLY : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
        }

        if(nnf == Field::eField::WASP)
        {
          f   = (f == Field::eField::BUTTERFLY) ? Field::eField::BUTTERFLY : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
        }

        if(nnf == Field::eField::EMPTY)
        {
          f   = (f == Field::eField::BUTTERFLY) ? Field::eField::BUTTERFLY : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
         }

          if(nnf == Field::eField::BOULDER)
          {
            f   = (f == Field::eField::BUTTERFLY) ? Field::eField::BUTTERFLY : Field::eField::EMPTY;
            nf  = Field::eField::EXPLOSION;
            mPlayer.game = false;
            break;
          }

            if(nnf == Field::eField::DIAMOND)
            {
              f   = (f == Field::eField::BUTTERFLY) ? Field::eField::BUTTERFLY : Field::eField::EMPTY;
              nf  = Field::eField::EXPLOSION;
              mPlayer.game = false;
              break;
            }

            if(nnf == Field::eField::BUTTERFLY)
            {
              f   = (f == Field::eField::BUTTERFLY) ? Field::eField::BUTTERFLY : Field::eField::EMPTY;
              nf  = Field::eField::EXPLOSION;
              mPlayer.game = false;
              break;
            }
        break;
    }

     case Field::eField::EXPLOSION:
     case Field::eField::SOIL:
     case Field::eField::WALL:
     case Field::eField::WASP:
     case Field::eField::BOULDER:
     case Field::eField::DIAMOND:
     case Field::eField::BUTTERFLY:
    {
        break;
    }

      }

   }
    }
}
//--------------------------static--------------------
std::vector <std::pair<int ,int>> wasp::mWaspPos{};
bool wasp::Is_Muving = true;
