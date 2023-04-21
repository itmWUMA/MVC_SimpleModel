#include "Pawn.h"
#include "Info.h"
#include "Map.h"
#include "RenderComponent.h"
using namespace std;

Pawn::Pawn() : PlayerState(make_shared<Info>()), RenderComp(make_shared<RenderComponent>())
{
}

Pawn::Pawn(char Mesh)
    : Mesh(Mesh)
    , PlayerState(make_shared<Info>())
    , RenderComp(make_shared<RenderComponent>())
{
}

void Pawn::ChangeMesh(char NewMesh)
{
    this->Mesh = NewMesh;
}

void Pawn::Move(int OffsetX, int OffsetY) const
{
    if (PlayerState)
    {
        Map* MapInstance = Map::Get();

        const int NewPosX = PlayerState->GetX() + OffsetX;
        const int NewPosY = PlayerState->GetY() + OffsetY;

        if (NewPosX >= 0 && NewPosX < MapInstance->Length && NewPosY >= 0 && NewPosY < MapInstance->Width)
        {
            PlayerState->SetX(NewPosX);
            PlayerState->SetY(NewPosY);
        }

        Render();
    }
}

int Pawn::GetCurrentStep() const
{
    return PlayerState ? PlayerState->GetStep() : 0;
}

void Pawn::Render() const
{
    RenderComp->Clear();

    const int CurPosX = PlayerState->GetX();
    const int CurPosY = PlayerState->GetY();

    const Map* MapInstance = Map::Get();
    for (int Row = 0; Row < MapInstance->Length; ++Row)
    {
        for (int Col = 0; Col < MapInstance->Width; ++Col)
        {
            if (CurPosX == Row && CurPosY == Col)
            {
                RenderComp->Render(Mesh);
            }
            else
            {
                RenderComp->Render(' ');
            }
        }
        RenderComp->Render('\n');
    }
}