#include "../../include/scene/choose_deck_scene.hpp"


yu::ChooseDeckScene::ChooseDeckScene(
    yu::CurrentScene* currentScene
) : yu::Scene(yu::SceneId::ChooseDeckSceneId, currentScene) {

    if (yu::audio::music.getLastSoundPlayed() != yu::audio::SoundId::DeckBuilderMusic) {
        yu::audio::music.playLoop(yu::audio::SoundId::DeckBuilderMusic);
    }

    yu::Sprite* header = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "assets/scenes/deck-builder/header.png",
            1,
            sf::Vector2f()
        )  
    );

    header->setCenterX(yu::constants::SCREEN_WIDTH / 2);
    header->setTop(30.f);

    yu::Sprite* cornerTopLeft = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "cornerTopLeft",
            "assets/icons/corner/corner.png",
            1,
            sf::Vector2f(40.f, 160.f)
        )  
    );
    cornerTopLeft->setRotation(180.f);

    yu::Sprite* cornerBottomLeft = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "cornerBottomLeft",
            "assets/icons/corner/corner.png",
            1,
            sf::Vector2f(40.f, 685.f)
        )  
    );
    cornerBottomLeft->setRotation(90.f);

    yu::Sprite* cornerTopRight = (yu::Sprite*) addComponent(
        std::make_unique<yu::Sprite>(
            "cornerTopRight",
            "assets/icons/corner/corner.png",
            1,
            sf::Vector2f(1240.f, 160.f)
        )  
    );
    cornerTopRight->setRotation(270.f);

    addComponent(
        std::make_unique<yu::Sprite>(
            "cornerBottomRight",
            "assets/icons/corner/corner.png",
            1,
            sf::Vector2f(1220.f, 660.f)
        )  
    );

    yu::IconButton* returnBtn = (yu::IconButton*) addComponent(
        std::make_unique<yu::IconButton>(
            "return-btn",
            "assets/scenes/deck-builder/return-btn.png",
            [this]() { this->currentScene->submitSceneChangeRequest(yu::SceneId::MainMenuSceneId); },
            sf::Vector2f(200.f, 300.f),
            1
        )
    );
    
    returnBtn->setBottom(header->bottom() + 15.f);
    returnBtn->setLeft(cornerTopLeft->left() - 25.f);    

    
}


void yu::ChooseDeckScene::update(const double dt) {
    yu::Scene::update(dt);    
}


void yu::ChooseDeckScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}