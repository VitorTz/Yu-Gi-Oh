#ifndef SFML_TEMPLATE_WINDOW_HPP
#define SFML_TEMPLATE_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include <memory>
#include "../scene/scenes.hpp"
#include "../constants.hpp"


namespace yu {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::shared_ptr<yu::CurrentScene> currentScene = std::make_shared<yu::CurrentScene>();
            yu::Timer mouseTimer = { 20 };
        
        private:
            void handle_input();
            void update();
            void render();

        public:
            Window();
            ~Window();
            void run();

    };
    
}


#endif