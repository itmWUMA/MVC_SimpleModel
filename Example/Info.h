#pragma once

class Info
{
public:
    Info() = default;
    Info(int X, int Y) : X(X), Y(Y) {}
    int GetX() const;
    int GetY() const;
    void SetX(int X);
    void SetY(int Y);
    int GetStep();
    void SetStep(int Step);

private:
    int X = 0;
    int Y = 0;
    int Step = 1;
};
