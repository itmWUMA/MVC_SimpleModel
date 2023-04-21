#pragma once

#include <memory>
using namespace std;

class InputComponent;
class InputCommand;
class Pawn;

class Controller
{
public:
    Controller();

    /* MoveForward Command Callback */
    void OnMoveForward(bool InputValue);

    /* MoveRight Command Callback */
    void OnMoveRight(bool InputValue);

    void PossessPawn(shared_ptr<Pawn> NewPawn);

    void Possess();

private:
    unique_ptr<InputComponent> InputComp;
    shared_ptr<InputCommand> MoveForwardCommand = nullptr;
    shared_ptr<InputCommand> MoveRightCommand = nullptr;
    shared_ptr<Pawn> CurPawn = nullptr;
};
