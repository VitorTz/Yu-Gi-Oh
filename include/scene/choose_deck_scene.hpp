#pragma once
#include "scene.hpp"


namespace yu {


    class ChooseDeckScene : public yu::Scene {

        public:
            ChooseDeckScene(yu::CurrentScene* currentScene);
            void update(double dt);
            void draw(sf::RenderWindow& window);

    };

    
} // namespace yu
