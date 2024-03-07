#ifndef SFML_TEMPLATE_MENU_SCENE_HPP
#define SFML_TEMPLATE_MENU_SCENE_HPP
#include "scene.hpp"


namespace yu {


    class MenuScene : public yu::Scene {

        public:
            MenuScene(const yu::ChangeScene& change_scene);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}


#endif