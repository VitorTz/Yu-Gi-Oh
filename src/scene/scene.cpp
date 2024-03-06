#include "../../include/scene/scene.hpp"


yu::Scene::Scene(
    const yu::ChangeScene& change_scene
) : change_scene(change_scene) {

}


yu::Scene::~Scene() {
    
}


void yu::Scene::addComponent(std::unique_ptr<yu::Component> component) {
    componentMap.insert({component->getName(), std::move(component)});
}


yu::Component* yu::Scene::getComponent(const std::string& componentName) {
    return componentMap.at(componentName).get();
}


void yu::Scene::update(const double dt) {
    for (auto& [name, component] : componentMap) {
        component->update(dt);
    }
}


void yu::Scene::draw(sf::RenderWindow& window) {
    for (auto& [name, component] : componentMap) {
        component->draw(window);
    }
}