//Yaminah Qureshi
//qureshiy

#include "CardADT.h"

CardT::CardT(int R, int S)
{
  this->r = R;
  this->s = S;
}

SuitT CardT::suit()
{
  return this->s;
}

int CardT::rank()
{
  return this->r;
}

