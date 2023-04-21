#pragma once

#include <memory>
using namespace std;

class Controller;

class InputCommand
{
public:
    InputCommand() = default;
    InputCommand(bool bInputValue) : InputValue(bInputValue) {}
    virtual ~InputCommand() = default;
    virtual void Execute(Controller* Controller, void(Controller::* InputCallback)(bool)) const;

protected:
    bool InputValue = true;
};

class MoveForwardInputCommand : public InputCommand
{
public:
    MoveForwardInputCommand() = default;
    MoveForwardInputCommand(bool bMoveForward) : InputCommand(bMoveForward) {}
};

class MoveRightInputCommand : public InputCommand
{
public:
    MoveRightInputCommand() = default;
    MoveRightInputCommand(bool bMoveRight) : InputCommand(bMoveRight) {}
};

class InputComponent
{
public:
    shared_ptr<InputCommand> HandleInput() const;
};
