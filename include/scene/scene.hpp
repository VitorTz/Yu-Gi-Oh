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
        MainSceneId
    };

    const yu::SceneId main_scene = yu::SceneId::MainSceneId;

    typedef std::function<void(yu::SceneId)> ChangeScene;

    class Scene {

        protected:
            const yu::ChangeScene& change_scene;
            std::map<std::string, std::unique_ptr<yu::Component>> componentMap;
        
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