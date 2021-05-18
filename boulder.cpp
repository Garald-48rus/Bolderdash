#include "level.h"


diamond mDiamod;
butterfly mButterfly;


Boulder::Boulder()
{

}
//-------------------------------------------------------------------
 void Boulder::delete_Boulder(int& aFirst, int& aSecond)
 {
     std::pair <int, int>  index{aFirst, aSecond};

     auto itr = std::find(mBoulderPos.begin(), mBoulderPos.end(), index);

     mBoulderPos.erase(itr);
 }
//------------------------------------------------
 void Boulder::reset_resetBoulderPos()
 {
     mBoulderPos.clear();
 }
//----------------------------------------------
 void Boulder::add_Boulder(int& aFirst, int& aSecond)
 {
    std::pair<int, int> itr{aFirst, aSecond};

    mBoulderPos.push_back(itr);
 }
 //--------------------------------------------------------
void Boulder::muve_Boulder(level& aLevel)
{
   wasp mWasp;

    for(auto itr : mBoulderPos)
    {
        auto &[line, column] = itr;

           auto nl  = line   + 1;                // next line
           auto nc  = column;                // next column

                auto nnl = nl + 1;                    // next next line
                auto nnc = nc ;                    // next next column

                auto coff  = aLevel.get_Columns() * line + column;  // current offset
                auto noff  = aLevel.get_Columns() * nl + nc;        // next offset
                auto nnoff = aLevel.get_Columns() * nnl + nnc;      // next next offset

                auto nocr = aLevel.get_Columns() * line + (nnc + 1);
                auto nocrr = aLevel.get_Columns() * nl + (nnc + 1);

                auto &ncr = aLevel.get_Room(nocr);
                auto &ncrr = aLevel.get_Room(nocrr);

                auto nocl = aLevel.get_Columns() * line + (nnc - 1);
                auto nocll = aLevel.get_Columns() * nl + (nnc - 1);

                auto &ncl = aLevel.get_Room(nocl);
                auto &ncll = aLevel.get_Room(nocll);

                auto &f   = aLevel.get_Room(coff);                 // current field
                auto &nf  = aLevel.get_Room(noff);                 // next field
                auto &nnf = aLevel.get_Room(nnoff);                // next next field



               bool isMoving = false; //флаг можно ли двигаться или нет 

    switch(nf)
             {
               case Field::eField::EMPTY:
              {
               if(nnf == Field::eField::SOIL)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }

               if(nnf == Field::eField::EMPTY)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }

               if(nnf == Field::eField::WALL)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }

               if(nnf == Field::eField::BOULDER)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }

               if(nnf == Field::eField::BUTTERFLY)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }

               if(nnf == Field::eField::WASP)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }
               if(nnf == Field::eField::PLAYER)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }
               if(nnf == Field::eField::DIAMOND)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }
               if(nnf == Field::eField::SWAMP)
               {
                 f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                 nf  = Field::eField::BOULDER;
                 isMoving = true;
                 delete_Boulder(line, column);
                 line   = nl;
                 column = nc;
                 add_Boulder(line, column);
                break;
               }
                  break;
               }


      case Field::eField::BUTTERFLY:
                  {
                   if(nnf == Field::eField::SOIL)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
                   if(nnf == Field::eField::WALL)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
                   if(nnf == Field::eField::WASP)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
                   if(nnf == Field::eField::EMPTY)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
                   if(nnf == Field::eField::BOULDER)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
                   if(nnf == Field::eField::DIAMOND)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
                   if(nnf == Field::eField::BUTTERFLY)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
                   if(nnf == Field::eField::SWAMP)
                   {
                     f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
                     nf  = Field::eField::DIAMOND;
                     isMoving = true;
                     line   = nl;
                     column = nc;
                     mDiamod.add_Diamond(line, column);
                     mButterfly.delete_Butterfly(line, column);
                    break;
                   }
          break;
               }

    case Field::eField::WASP:
            {
             if(nnf == Field::eField::SOIL)
             {
               f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
               nf  = Field::eField::BOULDER;
               isMoving = true;
               //delete_Boulder(line, column);
               line   = nl;
               column = nc;
               mWasp.delete_Wasp(line, column);
               add_Boulder(line, column);
              break;
             }
             if(nnf == Field::eField::WALL)
             {
               f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
               nf  = Field::eField::BOULDER;
               isMoving = true;
               //delete_Boulder(line, column);
               line   = nl;
               column = nc;
               mWasp.delete_Wasp(line, column);
               add_Boulder(line, column);
              break;
             }
             if(nnf == Field::eField::WASP)
             {
               f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
               nf  = Field::eField::BOULDER;
               isMoving = true;
               //delete_Boulder(line, column);
               line   = nl;
               column = nc;
               mWasp.delete_Wasp(line, column);
               add_Boulder(line, column);
              break;
             }
             if(nnf == Field::eField::EMPTY)
             {
               f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
               nf  = Field::eField::BOULDER;
               isMoving = true;
               //delete_Boulder(line, column);
               line   = nl;
               column = nc;
               mWasp.delete_Wasp(line, column);
               add_Boulder(line, column);
              break;
             }
             if(nnf == Field::eField::DIAMOND)
             {
               f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
               nf  = Field::eField::BOULDER;
               isMoving = true;
               //delete_Boulder(line, column);
               line   = nl;
               column = nc;
               mWasp.delete_Wasp(line, column);
               add_Boulder(line, column);
              break;
             }
             if(nnf == Field::eField::BUTTERFLY)
             {
               f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
               nf  = Field::eField::BOULDER;
               isMoving = true;
               //delete_Boulder(line, column);
               line   = nl;
               column = nc;
               mWasp.delete_Wasp(line, column);
               add_Boulder(line, column);
              break;
             }
             if(nnf == Field::eField::SWAMP)
             {
               f   = (f == Field::eField::BOULDER) ? Field::eField::BOULDER : Field::eField::EMPTY;
               nf  = Field::eField::BOULDER;
               isMoving = true;
               //delete_Boulder(line, column);
               line   = nl;
               column = nc;
               mWasp.delete_Wasp(line, column);
               add_Boulder(line, column);
              break;
             }
             break;
           }
    case Field::eField::WALL:
    case Field::eField::DIAMOND:
    case Field::eField::BOULDER:
    case Field::eField::SOIL:
    case Field::eField::PLAYER:
    case Field::eField::EXPLOSION:
    case Field::eField::SWAMP:

      {
        break;
      }

      break;
       }

        if(isMoving == false)
        {
         switch (ncr) {

         case Field::eField::EMPTY:

         {
             if(nf == Field::eField::BOULDER || nf == Field::eField::DIAMOND)
             {
                if(ncrr == Field::eField::EMPTY)
                {
             f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
             ncr = Field::eField::BOULDER;
             delete_Boulder(line,column);
             column = nc + 1;
             add_Boulder(line, column);
             isMoving = true;
             break;
             }
           }
             break;
         }

         case Field::eField::SOIL:
         case Field::eField::WALL:
         case Field::eField::WASP:
         case Field::eField::SWAMP:
         case Field::eField::PLAYER:
         case Field::eField::BOULDER:
         case Field::eField::DIAMOND:
         case Field::eField::BUTTERFLY:
         case Field::eField::EXPLOSION:
         {
             break;
         }
             break;
          }
        }

       if(isMoving == false)
       {
         switch (ncl) {

         case Field::eField::EMPTY :

         {

         if(nf == Field::eField::BOULDER || nf == Field::eField::DIAMOND)
         {

              if(ncll == Field::eField::EMPTY)
              {

                  f   = (f == Field::eField::BOULDER) ? Field::eField::EMPTY : Field::eField::EMPTY;
                  ncl = Field::eField::BOULDER;
                  delete_Boulder(line,column);
                  column = nc - 1;
                  add_Boulder(line, column);
                  isMoving = true;
                  break;

              }
         }

         }

         case Field::eField::SOIL:
         case Field::eField::WALL:
         case Field::eField::WASP:
         case Field::eField::SWAMP:
         case Field::eField::PLAYER:
         case Field::eField::BOULDER:
         case Field::eField::DIAMOND:
         case Field::eField::BUTTERFLY:
         case Field::eField::EXPLOSION:
         {
             break;
         }

         break;
         }
       }

        if(isMoving)//если камень двинулся
        {
            muve_Boulder(aLevel);//запускаю рекурсию падения камня
            mDiamod.muve_Diamond(aLevel); //запускаю рекурсию падения алмаза
         }

}

}
//---------------------------------------------
std::vector < std::pair<int ,int>> Boulder::mBoulderPos;

