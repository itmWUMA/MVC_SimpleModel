#include "Info.h"

int Info::GetX() const
{
    return X;
}

int Info::GetY() const
{
    return Y;
}

void Info::SetX(int X)
{
    this->X = X;
}

void Info::SetY(int Y)
{
    this->Y = Y;
}

int Info::GetStep()
{
    return Step;
}

void Info::SetStep(int Step)
{
    this->Step = Step;
}
