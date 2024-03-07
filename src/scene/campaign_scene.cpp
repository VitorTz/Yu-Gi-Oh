#include "../../include/scene/campaign_scene.hpp"


yu::CampaignScene::CampaignScene(
    const yu::ChangeScene& change_scene
) : yu::Scene(change_scene) {

}


void yu::CampaignScene::update(const double dt) {
    yu::Scene::update(dt);
}


void yu::CampaignScene::draw(sf::RenderWindow& window) {
    yu::Scene::draw(window);
}