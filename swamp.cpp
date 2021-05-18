#include "swamp.h"

#include "level.h"



swamp::swamp()
{

}
//--------------------------------------------
 void swamp::reset_resetSwampPos()// функция очистки массива элементов болота
 {
     mSwampPos.clear();
 }
//-----------------------------------------------
void swamp::add_Swamp(int& aFirst, int& aSecond)//функция добовления ячеек болота массив
{
     std::pair<int, int> itr{aFirst, aSecond};

     mSwampPos.push_back(itr);
}
//----------------------------------------------------------
void swamp::muve_Swamp(level& aLevel)//функция движения болота
{

    if(Is_Muving)
    {

      player mPlayer;

    for(auto itr :mSwampPos)
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
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }
               if(nnf == Field::eField::EMPTY)
               {
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }

               if(nnf == Field::eField::WALL)
               {
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }

               if(nnf == Field::eField::WASP)
               {
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP: Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }

               if(nnf == Field::eField::BOULDER)
               {
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }

               if(nnf == Field::eField::DIAMOND)
               {
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }

               if(nnf == Field::eField::BUTTERFLY)
               {
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }

               if(nnf == Field::eField::EXPLOSION)
               {
                 f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
                 nf  = Field::eField::SWAMP;
                 line   = nl;
                 column = nc;
                 add_Swamp(line, column);
                break;
               }
              break;
            }

     case Field::eField::SOIL:
   {
    if(nnf == Field::eField::SOIL)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }
    if(nnf == Field::eField::EMPTY)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }

    if(nnf == Field::eField::WALL)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }

    if(nnf == Field::eField::WASP)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP: Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }

    if(nnf == Field::eField::BOULDER)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }

    if(nnf == Field::eField::DIAMOND)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }

    if(nnf == Field::eField::BUTTERFLY)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }

    if(nnf == Field::eField::EXPLOSION)
    {
      f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::SWAMP;
      nf  = Field::eField::SWAMP;
      line   = nl;
      column = nc;
      add_Swamp(line, column);
     break;
    }
   break;
 }


    case Field::eField::PLAYER:
    {
        if(nnf == Field::eField::SOIL)
        {
          f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
        }

        if(nnf == Field::eField::WALL)
        {
          f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
        }

        if(nnf == Field::eField::WASP)
        {
          f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
        }

        if(nnf == Field::eField::EMPTY)
        {
          f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::EMPTY;
          nf  = Field::eField::EXPLOSION;
          mPlayer.game = false;
          break;
         }

          if(nnf == Field::eField::BOULDER)
          {
            f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::EMPTY;
            nf  = Field::eField::EXPLOSION;
            mPlayer.game = false;
            break;
          }

            if(nnf == Field::eField::DIAMOND)
            {
              f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::EMPTY;
              nf  = Field::eField::EXPLOSION;
              mPlayer.game = false;
              break;
            }

            if(nnf == Field::eField::BUTTERFLY)
            {
              f   = (f == Field::eField::SWAMP) ? Field::eField::SWAMP : Field::eField::EMPTY;
              nf  = Field::eField::EXPLOSION;
              mPlayer.game = false;
              break;
            }
        break;
    }

     case Field::eField::EXPLOSION:
     case Field::eField::WALL:
     case Field::eField::WASP:
     case Field::eField::BOULDER:
     case Field::eField::DIAMOND:
     case Field::eField::BUTTERFLY:
     case Field::eField::SWAMP:
    {
        break;
    }

      }

   }

    }
}

//----------------------------static--------------
std::vector <std::pair<int ,int>> swamp::mSwampPos{0};//массив координат, ячеек болот в комнате

bool swamp::Is_Muving{false};//флаг можно ли болоту расплываться
