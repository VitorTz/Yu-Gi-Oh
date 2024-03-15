#include "../../include/scene/scene.hpp"


yu::Scene::Scene(
    const yu::ChangeScene& changeScene
) : change_scene(changeScene) {

}


yu::Scene::~Scene() {
    allComponents.clear();
    yu::TexturePool::clear();
}


void yu::Scene::addComponent(
    std::unique_ptr<yu::Component> component
) {    
    const int zIndex = component->getZindex();
    if (allComponents.find(component->getName()) == allComponents.end()) {
        if (componentMap.find(zIndex) == componentMap.end()) {
            componentMap.insert({zIndex, { }});
        }
        componentMap.at(zIndex).push_back(component.get());
        allComponents.insert({component->getName(), std::move(component)});
    }
}


yu::Component* yu::Scene::getComponent(const std::string& name) {    
    if (allComponents.find(name) != allComponents.end()) {
        return allComponents.at(name).get();
    }
    return nullptr;
}


void yu::Scene::destroyComponent(const std::string& name) {
    if (allComponents.find(name) != allComponents.end()) {
        const int zIndex = allComponents.at(name)->getZindex();
        std::vector<yu::Component*>& v = componentMap.at(zIndex);
        for (std::size_t i = 0; i < v.size(); i++) {
            if (v[i]->getName() == name) {
                v.erase(v.begin() + i);
                break;
            }
        }
        allComponents.erase(name);
    }
}


void yu::Scene::changeScene(const yu::SceneId sceneId) {
    haveToChangeScene = true;
    nextScene = sceneId;
}


void yu::Scene::update(const double dt) {
    for (const auto& [index, vec] : componentMap) {
        for (yu::Component* c : vec) {  
            c->update(dt);
        }
    }
    if (haveToChangeScene) {
        change_scene(nextScene);
    }
}


void yu::Scene::draw(sf::RenderWindow& window) {
    for (const auto& [index, vec] : componentMap) {
        for (yu::Component* c : vec) {  
            c->draw(window);
        }
    }
}