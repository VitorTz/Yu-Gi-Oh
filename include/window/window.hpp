#ifndef SFML_TEMPLATE_WINDOW_HPP
#define SFML_TEMPLATE_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include "../scene/scenes.hpp"
#include "../constants.hpp"
#include <memory>


namespace yu {


    class Window {

        private:
            sf::RenderWindow window;
            sf::Clock clock;
            std::unique_ptr<yu::Scene> scene;
            yu::ChangeScene change_scene;
            yu::Timer mouseTimer = yu::Timer(20);
        
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