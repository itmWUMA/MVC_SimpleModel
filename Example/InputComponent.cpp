#include "InputComponent.h"
#include <iostream>
#include "Controller.h"

void InputCommand::Execute(Controller* Controller, void(Controller::* InputCallback)(bool)) const
{
    if (InputCallback)
    {
        (Controller->*InputCallback)(InputValue);
    }
}

shared_ptr<InputCommand> InputComponent::HandleInput() const
{
    char PlayerInputCharacter = '\0';
    cin >> PlayerInputCharacter;

    switch (PlayerInputCharacter)
    {
    case 'w':
    case 'W':
        return make_shared<MoveForwardInputCommand>(true);
    case 's':
    case 'S':
        return make_shared<MoveForwardInputCommand>(false);
    case 'd':
    case 'D':
        return make_shared<MoveRightInputCommand>(true);
    case 'a':
    case 'A':
        return make_shared<MoveRightInputCommand>(false);
    default:
        return nullptr;
    }
}
