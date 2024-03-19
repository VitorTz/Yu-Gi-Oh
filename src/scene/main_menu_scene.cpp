#include "../../include/scene/main_menu_scene.hpp"


yu::MainMenuScene::MainMenuScene(
    yu::CurrentScene* currentScene
) : yu::Scene(yu::SceneId::MainMenuSceneId, currentScene) {

    yu::Sprite* bg_image = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "assets/scenes/main-menu/bg.jpeg",
            1,
            sf::Vector2f()
        )
    );
    
    bg_image->setRight(yu::constants::SCREEN_WIDTH);
    
    yu::Sprite* logo = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "assets/scenes/main-menu/logo.png",
            1,
            sf::Vector2f()
        )
    );

    yu::box_t left_grid_box{
        { }, {yu::constants::SCREEN_WIDTH - bg_image->width(), yu::constants::SCREEN_HEIGHT}
    };

    logo->setCenterX(left_grid_box);
    logo->setTop(60.f);

    yu::Rect* line = (yu::Rect*) addComponent(
        std::make_unique<yu::Rect>(
            "line",
            1,
            sf::Vector2f(),
            sf::Vector2f(2, yu::constants::SCREEN_HEIGHT),
            yu::colors::YELLOW_200
        )
    );

    line->setRight(bg_image->left());

    yu::Grid* grid = (yu::Grid*) addComponent(
        std::make_unique<yu::Grid>(
            "button-grid",
            sf::Vector2f(85.f, 260.f),
            2,
            5.f,
            10.f,
            1
        )
    );

    grid->addComponent(
        std::make_unique<yu::TextButton>(
            "campaign-btn",
            "CAMPAIGN",
            []() { std::cout << "campaign\n"; },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            0,
            yu::style::NORMAL_TXT_STYLE,
            yu::style::COLOR_STYLE_1
        )
    );

    grid->addComponent(
        std::make_unique<yu::TextButton>(
            "free-duel-btn",
            "FREE DUEL",
            []() { std::cout << "free duel\n"; },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            0,
            yu::style::NORMAL_TXT_STYLE,
            yu::style::COLOR_STYLE_1
        )
    );

    grid->addComponent(
        std::make_unique<yu::TextButton>(
            "deck-editor-btn",
            "DECK EDITOR",
            [this]() { this->currentScene->submitSceneChangeRequest(yu::SceneId::ChooseDeckSceneId); },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            0,
            yu::style::NORMAL_TXT_STYLE,
            yu::style::COLOR_STYLE_1
        )
    );

    grid->addComponent(
        std::make_unique<yu::TextButton>(
            "settings-btn",
            "SETTINGS",
            []() { std::cout << "settings\n"; },
            sf::Vector2f(),
            sf::Vector2f(200.f, 40.f),
            0,
            yu::style::NORMAL_TXT_STYLE,
            yu::style::COLOR_STYLE_1
        )
    );    

    yu::audio::music.playLoop(yu::audio::MainMenuMusic);

}


void yu::MainMenuScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::MainMenuScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}