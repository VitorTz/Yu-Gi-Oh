#ifndef SFML_TEMPLATE_UTIL_HPP
#define SFML_TEMPLATE_UTIL_HPP
#include <SFML/System/Vector2.hpp>
#include <filesystem>
#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <vector>
#include "../constants.hpp"


namespace yu {

    int randint(int start, int end);
    std::filesystem::path make_path(const std::string& path);
    std::filesystem::path get_random_file_from_dir(const std::filesystem::path& dir);
    std::vector<std::filesystem::path> get_files_from_dir(const std::filesystem::path& dir);

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
}

#endif