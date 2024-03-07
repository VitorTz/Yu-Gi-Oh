#include "../../include/scene/menu_scene.hpp"
#include <memory>


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
        std::make_unique<yu::Menu>(
            "Menu",
            sf::Vector2f(60.f, 200.f),
            10,
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

    yu::Menu* menu = (yu::Menu*) getComponent("Menu"); 
    menu->addBtn(
        std::make_unique<yu::ImageButton>(
            "Campaign",
            sf::Vector2f(0.f, 0.f),
            [this]() { this->change_scene(yu::SceneId::CampaignSceneId); },
            "CAMPAIGN",
            yu::style::MENU_SCENE_CAMPAIGN_BTN,
            4
        )
    );
    menu->addBtn(
        std::make_unique<yu::ImageButton>(
            "FreeDuel",
            sf::Vector2f(0.f, 0.f),
            []() { std::cout << "Free Duel\n"; },
            "FREE DUEL",
            yu::style::MENU_SCENE_CAMPAIGN_BTN,
            4
        )
    );
    menu->addBtn(
        std::make_unique<yu::ImageButton>(
            "DeckEditor",
            sf::Vector2f(0.f, 0.f),
            []() { std::cout << "Deck Editor\n"; },
            "DECK EDITOR",
            yu::style::MENU_SCENE_CAMPAIGN_BTN,
            4
        )
    );
    menu->addBtn(
        std::make_unique<yu::ImageButton>(
            "Settings",
            sf::Vector2f(0.f, 0.f),
            []() { std::cout << "Settings\n"; },
            "Settings",
            yu::style::MENU_SCENE_CAMPAIGN_BTN,
            4
        )
    );
    
}


void yu::MenuScene::update(const double dt) {
    yu::Scene::update(dt);
    yu::Menu* menu = (yu::Menu*) getComponent("Menu"); 
    menu->handleBtnClick();    
}


void yu::MenuScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}