#ifndef YUGIOH_CHOOSE_DECK_SCENE_HPP
#define YUGIOH_CHOOSE_DECK_SCENE_HPP
#include "scene.hpp"
#include "../util/card.hpp"


namespace yu {


    class ChooseDeckScene : public yu::Scene {

        private:
            yu::card::CardSpritePool cardPool;

        public:
            ChooseDeckScene(
                const yu::ChangeScene& changeScene
            );
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}


#endif