#pragma once

#include <vector>
using namespace std;

class Map
{
public:
    static Map* Get();

public:
    void Render();
    void SetRenderMapElement(int Row, int Col, char Value);
    char GetRenderMapElement(int Row, int Col) const;

private:
    Map() = default;
    Map(const Map& Map) = default;

    bool Check(int Row, int Col) const;
    void Refresh();

public:
    const int Length = 10;
    const int Width = 10;

private:
    static Map* MapInstance;

private:
    vector<vector<char>> RenderMap = vector<vector<char>>(Length, vector<char>(Width, ' '));
};
