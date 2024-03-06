#include "../../include/scene/main_scene.hpp"
#include <memory>


yu::MainScene::MainScene(
    const yu::ChangeScene& change_scene
) : yu::Scene(change_scene) {
    addComponent(
        std::make_unique<yu::Image>("/home/vitor/Pictures/wallpapers/4de301429bb2b361a0a9479f59171891.png")
    );   
}


void yu::MainScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::MainScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}