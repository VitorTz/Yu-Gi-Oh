#ifndef SFML_TEMPLATE_UTIL_HPP
#define SFML_TEMPLATE_UTIL_HPP
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <filesystem>
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <vector>
#include "box.hpp"
#include "../constants.hpp"


namespace yu {

    int randint(int start, int end);

    template<typename T>
    void normalizeVector(sf::Vector2<T>* v) {
        const float m = std::sqrt(v->x * v->x + v->y * v->y);
        if (m > 1) {
            v->x *= m;
            v->y *= m;
        }
    }

    template<typename T>
    void printVector(const sf::Vector2<T> v) {
        std::cout << "Vector2(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")\n";
    }

    void drawBorder(
        const yu::box_t& box, 
        const sf::Color color, 
        const float thickness,
        sf::RenderWindow& window
    );
    
    std::filesystem::path getCardPath(const std::string& cardCode);

}

#endif