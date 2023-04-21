#include <memory>
#include "Controller.h"
#include "Pawn.h"
#include "InputComponent.h"
using namespace std;

int main(int argc, char* argv[])
{
    unique_ptr<Controller> MyController = make_unique<Controller>();
    shared_ptr<Pawn> MyPawn = make_shared<Pawn>();

    MyController->PossessPawn(MyPawn);

    MyPawn->Render();
    while (true)
    {
        MyController->Possess();
    }

    return 0;
}
