#pragma once
#include "component.hpp"
#include <functional>


namespace yu {

    typedef std::function<void()> VoidFunc;

    class Button : public yu::Component {

        private:
            yu::VoidFunc func;
        
        protected:
            virtual void handleMouseEntry() override;
            virtual void handleClick() override;

        public:
            Button(
                const std::string& name,
                const yu::VoidFunc& func,
                const sf::Vector2f pos,
                int zIndex
            );

    };
    
} // namespace yu
