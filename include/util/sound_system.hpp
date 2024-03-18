#pragma once
#include <SFML/Audio.hpp>
#include <filesystem>
#include <map>


namespace yu::audio {

    enum SoundId {
        NoMusic,
        // music
        MainMenuMusic,
        DeckBuilderMusic,
        // sound effect
        ClickSoundEffect,
        HoverSoundEffect
    };

    std::filesystem::path getAudioPath(yu::audio::SoundId soundId);


    class MusicPlayer {

        private:
            sf::SoundBuffer buffer;
            sf::Sound sound;            
            yu::audio::SoundId lastSoundPlayed = yu::audio::SoundId::NoMusic;

        public:
            MusicPlayer();            
            void playOnce(yu::audio::SoundId soundId);
            void playLoop(yu::audio::SoundId soundId);
            void stop();            
            bool isPlaying() const;
            yu::audio::SoundId getLastSoundPlayed() const;

    };


    inline yu::audio::MusicPlayer music;
    inline yu::audio::MusicPlayer soundEffect;


} // namespace yu
