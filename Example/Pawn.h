#pragma once

#include <memory>
using namespace std;

class Info;
class RenderComponent;

class Pawn
{
public:
    Pawn();
    Pawn(char Mesh);
    void ChangeMesh(char NewMesh);
    void Move(int OffsetX, int OffsetY) const;
    int GetCurrentStep() const;
    void Render() const;

private:
    char Mesh = 'A';
    shared_ptr<Info> PlayerState;
    shared_ptr<RenderComponent> RenderComp;
};
