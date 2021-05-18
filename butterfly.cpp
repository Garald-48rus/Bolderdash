 #include "butterfly.h"

#include "level.h"


player mPlayer;// объект класса игрока


butterfly::butterfly()
{

}
//--------------------------------------------------
void butterfly::reset_resetButterflyPos()// функция очистки массива элементов бабочек
{
     mButteflyPos.clear();
}
//--------------------------------------------------
void butterfly::add_Butterfly(int& aFirst, int& aSecond)//функция добовления бабочек в массив
{
    std::pair<int, int> itr{aFirst, aSecond};

    mButteflyPos.push_back(itr);
}
//-----------------------------------------------------
void butterfly::delete_Butterfly(int& aFirst, int& aSecond)//функция удаления бабочки из массива
{
    std::pair <int, int>  index{aFirst, aSecond};

    auto itr = std::find(mButteflyPos.begin(), mButteflyPos.end(), index);

    mButteflyPos.erase(itr);
}
//--------------------------------------------------------
void butterfly::muve_Butterfly(level& aLevel)//функция движения бабочек
{
    if(Is_Muving)
    {
    for(auto itr :mButteflyPos)
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
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }
               if(nnf == Field::eField::EMPTY)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
               break;
               }

               if(nnf == Field::eField::WALL)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }

               if(nnf == Field::eField::WASP)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }

               if(nnf == Field::eField::BOULDER)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }

               if(nnf == Field::eField::DIAMOND)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }

               if(nnf == Field::eField::BUTTERFLY)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }

               if(nnf == Field::eField::EXPLOSION)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }
               if(nnf == Field::eField::SWAMP)
               {
                 f   = (f == Field::eField::BUTTERFLY) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BUTTERFLY;
                 delete_Butterfly(line, column);
                 line   = nl;
                 column = nc;
                 add_Butterfly(line, column);
                break;
               }
              break;

            }

    case Field::eField::PLAYER:
    {

        if(nnf == Field::eField::SOIL)
        {
          f   = (f == Field::eField::BUTTERFLY) ? Field::eField::BUTTERFLY : Field::eField::EMPTY;
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
            if(nnf == Field::eField::SWAMP)
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
     case Field::eField::SWAMP:
    {
        break;
    }

      }

   }

    }
}
//--------------------------------------------------------ststic----------------------
std::vector <std::pair<int ,int>> butterfly::mButteflyPos{};
bool butterfly::Is_Muving = true;
