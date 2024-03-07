#include "../../include/scene/menu_scene.hpp"


yu::MenuScene::MenuScene(
    const yu::ChangeScene& change_scene
) : yu::Scene(change_scene) {
    
    addComponent(
        std::make_unique<yu::Image>(
            "assets/menu/logo.png",
            sf::Vector2f(80.f, 80.f),
            3
        )
    );
    addComponent(
        std::make_unique<yu::Image>(
            "monster",
            yu::get_random_file_from_dir(yu::constants::MENU_MONSTERS),
            sf::Vector2f(),
            0
        )
    );
    addComponent(
        std::make_unique<yu::FlameAnimation>(
            -1,
            yu::Box(
                sf::Vector2f(360.f, 0.f),
                sf::Vector2f(yu::constants::SCREEN_WIDTH - 360.f, yu::constants::SCREEN_HEIGHT)
            )
        )
    );
    addComponent(
        std::make_unique<yu::Rect>(
            "menu_left_rect",
            sf::Vector2f(0.f, 0.f),
            sf::Vector2f(360.f, yu::constants::SCREEN_HEIGHT),
            2,
            yu::colors::GREY_400,
            yu::style::NO_BORDER
        )
    );
    addComponent(
        std::make_unique<yu::Rect>(
            "line",
            sf::Vector2f(360.f, 0.f),
            sf::Vector2f(2.f, yu::constants::SCREEN_HEIGHT),
            2,
            yu::colors::YELLOW_400,
            yu::style::NO_BORDER
        )
    ); 
    addComponent(
        std::make_unique<yu::ImageButton>(
            "CampaignBtn",
            sf::Vector2f(300.f, 200.f),
            []() { std::cout << "Hello!\n"; },
            "CAMPAIGN",
            yu::style::MENU_SCENE_CAMPAIGN_BTN,
            4
        )
    );

    yu::Image* monster_image = (yu::Image*) getComponent("monster");

    monster_image->setCenter(
        yu::Box(
            sf::Vector2f(360.f, 0.f),
            sf::Vector2f(yu::constants::SCREEN_WIDTH - 360.f, yu::constants::SCREEN_HEIGHT)
        )
    );    
    
}


void yu::MenuScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::MenuScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}