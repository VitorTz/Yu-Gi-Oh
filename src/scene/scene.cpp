#include "../../include/scene/scene.hpp"



yu::Scene::Scene(
    const yu::SceneId id,
    yu::CurrentScene* currentScene
) : id(id),
    currentScene(currentScene) {

    }


yu::Scene::~Scene() = default;


yu::Component* yu::Scene::addComponent(
    std::unique_ptr<yu::Component> c
) {
    const std::string componentName = c->getName();
    const int zIndex = c->getZindex();        
    if (allComponents.find(componentName) == allComponents.end()) {
        if (componentMap.find(zIndex) == componentMap.end()) {
            componentMap.insert({zIndex, { }});
        } 
        componentMap.at(zIndex).push_back(c.get());
        allComponents.insert({componentName, std::move(c)});
    }
    return allComponents.at(componentName).get();
}


yu::Component* yu::Scene::getComponent(
    const std::string& componentName
) {
    return allComponents.at(componentName).get();
}


void yu::Scene::rmvComponent(const std::string& componentName) {
    if (allComponents.find(componentName) != allComponents.end()) {
        yu::Component* c = allComponents.at(componentName).get();
        std::vector<yu::Component*> v = componentMap.at(c->getZindex());
        for (std::size_t i = 0; i < v.size(); i++) {
            if (v[i] == c) {
                v.erase(v.begin() + i);
                break;
            }
        }
        allComponents.erase(componentName);
    }
}


void yu::Scene::update(const double dt) {
    for (auto& [index, vec] : componentMap) {
        for (yu::Component* c : vec) {
            c->update(dt);
        }
    }
}

void yu::Scene::draw(sf::RenderWindow& window) {
    for (auto& [index, vec] : componentMap) {
        for (yu::Component* c : vec) {
            c->draw(window);
        }
    }
}


yu::SceneId yu::Scene::getSceneId() const {
    return id;
}