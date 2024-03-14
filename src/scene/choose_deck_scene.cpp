#include "../../include/scene/choose_deck_scene.hpp"



yu::ChooseDeckScene::ChooseDeckScene(
    const yu::ChangeScene& changeScene
) : yu::Scene(changeScene) {

}


void yu::ChooseDeckScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::ChooseDeckScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}