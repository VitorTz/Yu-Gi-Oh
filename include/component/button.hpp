#pragma once
#include "component.hpp"
#include <functional>


namespace yu {

    typedef std::function<void()> VoidFunc;

    class Button : public yu::Component {

        private:
            yu::VoidFunc func;

        public:
            Button(
                const std::string& name,
                const yu::VoidFunc& func,
                const sf::Vector2f pos,
                int zIndex
            );
            void handleClick() override;
            virtual void handleMouseEntry() override;            

    };
    
} // namespace yu
