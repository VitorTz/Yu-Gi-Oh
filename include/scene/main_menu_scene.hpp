#ifndef SFML_TEMPLATE_MENU_SCENE_HPP
#define SFML_TEMPLATE_MENU_SCENE_HPP
#include "scene.hpp"


namespace yu {


    class MainMenuScene : public yu::Scene {

        public:
            MainMenuScene(const yu::ChangeScene& change_scene);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}


#endif