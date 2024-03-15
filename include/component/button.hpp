#ifndef YUGIOH_BUTTON_HPP
#define YUGIOH_BUTTON_HPP
#include "component.hpp"
#include "../util/sound_system.hpp"
#include <functional>


namespace yu {

    typedef std::function<void()> VoidFunction;

    class Button : public yu::Component {

        private:
            yu::VoidFunction func;

        private:
            void handleClick() override {
                yu::SoundSystem::soundEffect.play(yu::SoundEffectId::MouseClickSoundEffect);
                func();
            }
            void handleMouseEntry() override { 
                yu::SoundSystem::soundEffect.play(yu::SoundEffectId::MouseHoverSoundEffect);
            }            

        public:
            Button(
                const std::string& name,
                const yu::VoidFunction& func,
                int zIndex
            ) : yu::Component(name, zIndex),
                func(func) { }
            
    };

}


#endif