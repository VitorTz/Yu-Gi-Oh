#ifndef YUGIOH_MUSIC_PLAYER_HPP
#define YUGIOH_MUSIC_PLAYER_HPP
#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <filesystem>
#include <map>


namespace yu {


    enum class SoundEffectId {
        MouseHoverSoundEffect,
        MouseClickSoundEffect

    };
    
    enum class MusicId {
        MainMenuMusic
    };

    const std::map<yu::MusicId, std::filesystem::path> musicPathById = {
        {yu::MusicId::MainMenuMusic, "assets/music/main-menu.wav"}
    };

    
    const std::map<yu::SoundEffectId, std::filesystem::path> soundEffectPathById = {
        {yu::SoundEffectId::MouseClickSoundEffect, "assets/music/sound-effect/click.wav"},
        {yu::SoundEffectId::MouseHoverSoundEffect, "assets/music/sound-effect/hover.wav"}

    };


    class MusicPlayer {

        private:
            sf::SoundBuffer buffer;
            sf::Sound sound;
        
        public:
            MusicPlayer();            
            void play(const std::filesystem::path& wav_file);
            void play(yu::MusicId music);
            void play(yu::SoundEffectId soundEffect);
            void stop();

    };


    class SoundSystem {

        public:
            static MusicPlayer music;
            static MusicPlayer soundEffect;

    };

}


#endif
