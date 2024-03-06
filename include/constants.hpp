#ifndef SFML_TEMPLATE_CONSTANTS_HPP
#define SFML_TEMPLATE_CONSTANTS_HPP
#include <filesystem>


namespace yu::constants {

    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;
    const char WINDOW_TITLE[] = "Yu-Gi-Oh Forbidden Memories";
    const int FPS = 60;

    const std::filesystem::path ASSETS_PATH("assets");
    
}


#endif