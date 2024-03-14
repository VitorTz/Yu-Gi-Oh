#include "../../include/util/sound_system.hpp"

yu::MusicPlayer yu::SoundSystem::music;
yu::MusicPlayer yu::SoundSystem::soundEffect;


yu::MusicPlayer::MusicPlayer() {
    sound.setBuffer(buffer);
}


void yu::MusicPlayer::play(const std::filesystem::path& file) {
    sound.stop();
    buffer.loadFromFile(file);
    sound.play();
}


void yu::MusicPlayer::play(yu::MusicId music) {
    play(yu::musicPathById.at(music));
}


void yu::MusicPlayer::play(yu::SoundEffectId sound) {
    play(yu::soundEffectPathById.at(sound));
}