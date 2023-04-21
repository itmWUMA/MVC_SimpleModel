#include "Controller.h"
#include "InputComponent.h"
#include "Pawn.h"

Controller::Controller() : InputComp(make_unique<InputComponent>())
{
}

void Controller::OnMoveForward(bool InputValue)
{
    if (CurPawn)
    {
        const int CurStep = CurPawn->GetCurrentStep();
        CurPawn->Move(InputValue ? -CurStep : CurStep, 0);
    }
}

void Controller::OnMoveRight(bool InputValue)
{
    if (CurPawn)
    {
        const int CurStep = CurPawn->GetCurrentStep();
        CurPawn->Move(0, InputValue ? CurStep : -CurStep);
    }
}

void Controller::PossessPawn(shared_ptr<Pawn> NewPawn)
{
    this->CurPawn = NewPawn;
}

void Controller::Possess()
{
    if (InputComp)
    {
        const shared_ptr<InputCommand> CurCommand = InputComp->HandleInput();

        if (dynamic_cast<MoveForwardInputCommand*>(CurCommand.get()))
        {
            MoveForwardCommand = CurCommand;
        }
        if (dynamic_cast<MoveRightInputCommand*>(CurCommand.get()))
        {
            MoveRightCommand = CurCommand;
        }

        if (MoveForwardCommand)
        {
            MoveForwardCommand->Execute(this, &Controller::OnMoveForward);
        }

        if (MoveRightCommand)
        {
            MoveRightCommand->Execute(this, &Controller::OnMoveRight);
        }
    }

    MoveForwardCommand = nullptr;
    MoveRightCommand = nullptr;
}
