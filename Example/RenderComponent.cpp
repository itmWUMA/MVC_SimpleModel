#include "RenderComponent.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void RenderComponent::Render(char Character) const
{
    cout << Character;
}

void RenderComponent::Clear() const
{
    system("cls");
}
