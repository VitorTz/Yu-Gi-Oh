#include "../../include/util/util.hpp"


std::filesystem::path yu::make_path(const std::string &path) {
    std::filesystem::path p(yu::constants::ASSETS_PATH.string() + '/' + path);
    return p;
}