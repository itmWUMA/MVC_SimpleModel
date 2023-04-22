#include "RenderComponent.h"
#include "Map.h"

void RenderComponent::Render(int Row, int Col, char Character) const
{
    Map* MapInstance = Map::Get();
    MapInstance->SetRenderMapElement(Row, Col, Character);
    MapInstance->Render();
}