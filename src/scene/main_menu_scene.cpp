#include "../../include/scene/main_menu_scene.hpp"
#include <memory>



yu::MainMenuScene::MainMenuScene(
    const yu::ChangeScene& changeScene
) : yu::Scene(changeScene) {
    
    yu::SoundSystem::music.play(yu::MusicId::MainMenuMusic);

    addComponent(
        std::make_unique<yu::Sprite>(
            "bg",
            "assets/menu/bg.png",
            sf::Vector2f(-6.f, -6.f),
            0
        )
    );

    addComponent(
        std::make_unique<yu::Grid>(
            "button-grid",
            sf::Vector2f(70.f, 320.f),
            1,
            1,
            7
        )
    );

    yu::Grid* grid = (yu::Grid*) getComponent("button-grid");

    grid->addItem(
        std::make_unique<yu::TextBtn>(
            "campign-btn",
            "CAMPAIGN",
            []() { std::cout << "CAMPAIGN\n"; },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            1,
            yu::style::MAIN_COLOR_STYLE,      
            yu::style::NORMAL_TXT,            
            yu::style::NO_BORDER
        )
    );

    grid->addItem(
        std::make_unique<yu::TextBtn>(
            "free-duel-btn",
            "FREE DUEL",
            []() { std::cout << "FREE DUEL\n"; },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            1,
            yu::style::MAIN_COLOR_STYLE,      
            yu::style::NORMAL_TXT,            
            yu::style::NO_BORDER
        )
    );

    grid->addItem(
        std::make_unique<yu::TextBtn>(
            "deck-editor-btn",
            "DECK EDITOR",
            [this]() { this->changeScene(yu::SceneId::ChooseDeckSceneId); },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            1,
            yu::style::MAIN_COLOR_STYLE,      
            yu::style::NORMAL_TXT,            
            yu::style::NO_BORDER
        )
    );

    grid->addItem(
        std::make_unique<yu::TextBtn>(
            "settings-btn",
            "SETTINGS",
            []() { std::cout << "SETTINGS\n"; },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            1,
            yu::style::MAIN_COLOR_STYLE,      
            yu::style::NORMAL_TXT,            
            yu::style::NO_BORDER
        )
    );

}   


void yu::MainMenuScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::MainMenuScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}