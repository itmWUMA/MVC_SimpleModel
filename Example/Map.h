#pragma once

class Map
{
public:
    static Map* Get();

private:
    Map() = default;
    Map(const Map& Map) = default;

public:
    const int Length = 10;
    const int Width = 10;

private:
    static Map* MapInstance;
};
