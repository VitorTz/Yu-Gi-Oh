#ifndef SFML_TEMPLATE_SCENE_HPP
#define SFML_TEMPLATE_SCENE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <map>
#include <memory>
#include "../util/texture_pool.hpp"
#include "../component/components.hpp"


namespace yu {

    enum SceneId {
        MenuSceneId,
        CampaignSceneId,
        FreeDuelSceneId,
        DeckEditorSceneId,
        SettingsSceneId
    };

    const yu::SceneId main_scene = yu::SceneId::MenuSceneId;

    typedef std::function<void(yu::SceneId)> ChangeScene;

    typedef std::map<int, std::vector<yu::Component*>> ComponentMap;

    class Scene {
        
        private:
            std::map<std::string, std::unique_ptr<yu::Component>> allComponents;
            ComponentMap componentMap;

        protected:
            const yu::ChangeScene& change_scene;
        
        protected:
            void addComponent(std::unique_ptr<yu::Component> component);
            yu::Component* getComponent(const std::string& componentName);

        public:
            Scene(const yu::ChangeScene& change_scene);
            virtual ~Scene();
            virtual void update(double dt);
            virtual void draw(sf::RenderWindow& window);

    };

}


#endif