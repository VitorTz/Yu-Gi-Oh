#include "../../include/window/window.hpp"


yu::Window::Window(

) : window(
    sf::VideoMode(yu::constants::SCREEN_WIDTH, yu::constants::SCREEN_HEIGHT),
    yu::constants::WINDOW_TITLE,
    sf::Style::Close | sf::Style::Titlebar
) {

    window.setFramerateLimit(yu::constants::FPS);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(
        sf::Vector2i(
            desktop.width / 2 - yu::constants::SCREEN_WIDTH / 2,
            desktop.height / 2 - yu::constants::SCREEN_HEIGHT / 2
        )
    );

    this->change_scene = [this](const yu::SceneId id) {
        switch (id) {
            case yu::SceneId::MenuSceneId:
                this->scene = std::make_unique<yu::MenuScene>(this->change_scene);
                break;
            case yu::SceneId::CampaignSceneId:
                this->scene = std::make_unique<yu::CampaignScene>(this->change_scene);
                break;
            default:
                break;
        }
    };

    this->change_scene(yu::main_scene);
    
}


yu::Window::~Window() {
    
}


void yu::Window::handle_input() {
    sf::Event e{};
    while (window.pollEvent(e)) {
        switch (e.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }

    mouseTimer.update();
    yu::globals::mouseIsClicked = sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseTimer.check();
    yu::globals::mousePos = (sf::Vector2f) sf::Mouse::getPosition(window);

}


void yu::Window::update() {
    const double dt = clock.restart().asSeconds();
    scene->update(dt);
}


void yu::Window::render() {
    window.clear(yu::constants::WINDOW_BG_COLOR);
    scene->draw(window);
    window.display();
}


void yu::Window::run() {
    while (window.isOpen()) {
        handle_input();
        update();
        render();
    }
}