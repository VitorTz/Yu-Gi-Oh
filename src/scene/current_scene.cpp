#include "../../include/scene/scenes.hpp"


yu::CurrentScene::CurrentScene(

) : idNextScene(yu::firstScene) {
    changeScene();
}   


void yu::CurrentScene::changeScene() {
    haveToChangeScene = false;
    yu::Sprite::textureClear();

    switch (idNextScene) {
        case yu::SceneId::MainMenuSceneId:
            this->scene = std::make_unique<yu::MainMenuScene>(this);
        default:
            break;
    }

}


void yu::CurrentScene::submitSceneChangeRequest(
    const yu::SceneId nextSceneId 
) {
    if (!haveToChangeScene) {
        idNextScene = nextSceneId;
        haveToChangeScene = true;
    }
}


void yu::CurrentScene::update(const double dt) {
    scene->update(dt);
    if (haveToChangeScene) {
        changeScene();
    }
}


void yu::CurrentScene::draw(sf::RenderWindow& window) {
    scene->draw(window);
}