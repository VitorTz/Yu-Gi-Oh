#ifndef YUGIOH_CAMPAIGN_SCENE_HPP
#define YUGIOH_CAMPAIGN_SCENE_HPP
#include "scene.hpp"

namespace yu {


    class CampaignScene : public yu::Scene {

        public:
            CampaignScene(const yu::ChangeScene& change_scene);
            void update(double dt) override;
            void draw(sf::RenderWindow& window) override;

    };

}

#endif