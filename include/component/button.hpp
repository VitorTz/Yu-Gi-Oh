#ifndef YUGIOH_BUTTON_HPP
#define YUGIOH_BUTTON_HPP
#include "component.hpp"
#include "../util/style.hpp"
#include <functional>


namespace yu {

    typedef std::function<void()> VoidFunction;

    class Button : public yu::Component {        

        private:
            VoidFunction func;
        
        protected:
            yu::style::button_style_t style;

        public:
            Button(
                const std::string& name,
                const sf::Vector2f pos,
                const VoidFunction& func,
                const int zIndex,
                const yu::style::button_style_t& style
            ) : yu::Component(name, zIndex, pos), func(func), style(style) { }
            virtual ~Button() override = default;
            void update([[maybe_unused]] double dt) override {
                if (clicked()) { func(); }
            }

    };

}

#endif