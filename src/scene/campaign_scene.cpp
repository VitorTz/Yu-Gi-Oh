#include "../../include/scene/campaign_scene.hpp"



yu::CampaignScene::CampaignScene(
    const yu::ChangeScene& changeScene
) : yu::Scene(changeScene) {

}


void yu::CampaignScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::CampaignScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}