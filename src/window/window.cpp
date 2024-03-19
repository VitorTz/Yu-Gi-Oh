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
    sf::Image iconImage;
    iconImage.loadFromFile("assets/icons/icon.png");
    window.setIcon(iconImage.getSize().x, iconImage.getSize().y, iconImage.getPixelsPtr());    

    for (const auto& p : std::filesystem::directory_iterator("db/card_info")) {
        const std::filesystem::path path = p.path();
        yu::globals::cards.insert(
            {path.stem(), std::make_unique<yu::Card>(path)}
        );
    }

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
    yu::globals::windowHasFocus = window.hasFocus();

}


void yu::Window::update() {
    const double dt = clock.restart().asSeconds();
    currentScene->update(dt);
}


void yu::Window::render() {
    window.clear(yu::constants::WINDOW_BG_COLOR);
    currentScene->draw(window);
    window.display();
}


void yu::Window::run() {
    while (window.isOpen()) {
        handle_input();
        update();
        render();
    }
}