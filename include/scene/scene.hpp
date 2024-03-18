#pragma once
#include "../component/components.hpp"
#include <memory>


namespace yu {

    enum SceneId {
        MainMenuSceneId,
        ChooseDeckSceneId,
        DeckEditorSceneId
    };

    const yu::SceneId firstScene = yu::SceneId::MainMenuSceneId;

    class Scene;

    class CurrentScene {

        private:
            std::unique_ptr<yu::Scene> scene;
            yu::SceneId idNextScene;
            bool haveToChangeScene = false;
        
        private:
            void changeScene();
        
        public:
            CurrentScene();
            void submitSceneChangeRequest(yu::SceneId nextScene);
            void update(double dt);
            void draw(sf::RenderWindow& window);

    };

    typedef std::map<int, std::vector<yu::Component*>> ComponentMap;

    class Scene {

        private:
            const yu::SceneId id;
        
        private:
            std::map<std::string, std::unique_ptr<yu::Component>> allComponents;
            ComponentMap componentMap;
        
        protected:
            yu::CurrentScene* currentScene;
        
        protected:
            yu::Component* addComponent(std::unique_ptr<yu::Component> c);
            yu::Component* getComponent(const std::string& componentName);
            void rmvComponent(const std::string& componentName);
        
        public:
            Scene(
                yu::SceneId id, 
                yu::CurrentScene* currentScene
            );
            virtual ~Scene();
            virtual void update(double dt);
            virtual void draw(sf::RenderWindow& window);
            yu::SceneId getSceneId() const;
    };
    
} // namespace yu
