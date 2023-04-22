#pragma once

#include <memory>
using namespace std;

class Controller;

class InputCommand
{
public:
    InputCommand() = default;
    virtual ~InputCommand() = default;
    virtual void Execute(Controller* Controller) const {}
};

class MoveForwardInputCommand : public InputCommand
{
public:
    MoveForwardInputCommand() = default;
    MoveForwardInputCommand(bool bMoveForward) : InputValue(bMoveForward) {}

    virtual void Execute(Controller* Controller) const override;

protected:
    bool InputValue = true;
};

class MoveRightInputCommand : public InputCommand
{
public:
    MoveRightInputCommand() = default;
    MoveRightInputCommand(bool bMoveRight) : InputValue(bMoveRight) {}

    virtual void Execute(Controller* Controller) const override;

protected:
    bool InputValue = true;
};

class InputComponent
{
public:
    shared_ptr<InputCommand> HandleInput() const;
};
