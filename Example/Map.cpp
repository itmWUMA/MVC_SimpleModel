#include "Map.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Map* Map::MapInstance = new Map;

Map* Map::Get()
{
    return MapInstance;
}

void Map::Render()
{
    system("cls");
    for (const vector<char>& Row : RenderMap)
    {
        for (const char Element : Row)
        {
            cout << Element;
        }
        cout << endl;
    }
    Refresh();
}

void Map::SetRenderMapElement(int Row, int Col, char Value)
{
    if (Check(Row, Col))
    {
        RenderMap[Row][Col] = Value;
    }
}

char Map::GetRenderMapElement(int Row, int Col) const
{
    if (Check(Row, Col))
    {
        return RenderMap[Row][Col];
    }

    return '\0';
}

bool Map::Check(int Row, int Col) const
{
    return Row >= 0 && Row < Length && Col >= 0 && Col < Width;
}

void Map::Refresh()
{
    for (vector<char>& Row : RenderMap)
    {
        for (int Index = 0; Index < Width; ++Index)
        {
            Row[Index] = ' ';
        }
    }
}
