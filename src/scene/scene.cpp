#include "../../include/scene/scene.hpp"


yu::Scene::Scene(
    const yu::ChangeScene& change_scene
) : change_scene(change_scene) {

}


yu::Scene::~Scene() {
    yu::TexturePool::clear();    
}


void yu::Scene::addComponent(std::unique_ptr<yu::Component> component) {
    const int zIndex = component->getZindex();
    if (componentMap.find(zIndex) == componentMap.end()) {
        componentMap.insert({zIndex, {}});
    }
    componentMap.at(zIndex).push_back(component.get());
    allComponents.insert({component->getName(), std::move(component)});
}


yu::Component* yu::Scene::getComponent(const std::string& componentName) {
    return allComponents.at(componentName).get();
}


void yu::Scene::update(const double dt) {
    for (const auto& [index, componentVector] : componentMap) {
        for (auto& component : componentVector) {
            component->update(dt);
        }
    }
}


void yu::Scene::draw(sf::RenderWindow& window) {
    for (const auto& [index, componentVector] : componentMap) {
        for (auto& component : componentVector) {
            component->draw(window);
        }
    }
}