#pragma once
#include "scene.hpp"


namespace yu {


    class MainMenuScene : public yu::Scene {

        public:
            MainMenuScene(
                yu::CurrentScene* currentScene
            );
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;    

    };
    
} // namespace yu
