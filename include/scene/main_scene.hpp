#ifndef SFML_TEMPLATE_MAIN_SCENE_HPP
#define SFML_TEMPLATE_MAIN_SCENE_HPP
#include "scene.hpp"
#include <memory>


namespace yu {


    class MainScene : public yu::Scene {

        private:
            std::unique_ptr<yu::Image> image;

        public:
            MainScene(const yu::ChangeScene& change_scene);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}


#endif