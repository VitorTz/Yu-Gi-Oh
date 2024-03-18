#include "../../include/component/grid.hpp"


yu::Grid::Grid(
    const std::string& name,
    const sf::Vector2f pos,
    const int zIndex,
    const int paddingX,
    const int paddingY,
    const int columns
) : yu::Component(name, pos, zIndex) {

}