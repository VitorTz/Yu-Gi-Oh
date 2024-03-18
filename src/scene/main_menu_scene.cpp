#include "../../include/scene/main_menu_scene.hpp"


yu::MainMenuScene::MainMenuScene(
    yu::CurrentScene* currentScene
) : yu::Scene(yu::SceneId::MainMenuSceneId, currentScene) {
    
    yu::Sprite* bg_image = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "assets/menu/bg.jpeg",
            1,
            sf::Vector2f()
        )
    );
    
    bg_image->setRight(yu::constants::SCREEN_WIDTH);
    
    yu::Sprite* logo = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "assets/menu/logo.png",
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

}


void yu::MainMenuScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::MainMenuScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}