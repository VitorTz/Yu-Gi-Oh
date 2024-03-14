#include "../../include/scene/main_menu_scene.hpp"
#include <memory>



yu::MainMenuScene::MainMenuScene(
    const yu::ChangeScene& changeScene
) : yu::Scene(changeScene) {
    
    yu::SoundSystem::music.play(yu::MusicId::MainMenuMusic);

    addComponent(
        std::make_unique<yu::Sprite>(
            "logo",
            "assets/menu/bg.png",
            sf::Vector2f(-6.f, -6.f),
            0
        )
    );

}   


void yu::MainMenuScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::MainMenuScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}