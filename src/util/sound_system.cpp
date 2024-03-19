#include "../../include/util/sound_system.hpp"


yu::audio::MusicPlayer::MusicPlayer() {
    sound.setBuffer(buffer);
}


void yu::audio::MusicPlayer::playOnce(
    const yu::audio::SoundId soundId
) {    
    std::filesystem::path file = getAudioPath(soundId);
    sound.stop();
    buffer.loadFromFile(file);
    lastSoundPlayed = soundId;
    sound.setLoop(false);
    sound.play();
}


void yu::audio::MusicPlayer::playLoop(
    const yu::audio::SoundId soundId
) {    
    std::filesystem::path file = getAudioPath(soundId);
    sound.stop();
    buffer.loadFromFile(file);
    lastSoundPlayed = soundId;
    sound.setLoop(true);
    sound.play();
}


void yu::audio::MusicPlayer::stop() {
    sound.stop();
    lastSoundPlayed = yu::audio::SoundId::NoMusic;
}


bool yu::audio::MusicPlayer::isPlaying() const {
    return sound.getStatus() == sf::Sound::Status::Playing;
}


yu::audio::SoundId yu::audio::MusicPlayer::getLastSoundPlayed() const {
    return lastSoundPlayed;
}


std::filesystem::path yu::audio::getAudioPath(const yu::audio::SoundId soundId) {
    std::filesystem::path path;
    
    switch (soundId) {
        case yu::audio::SoundId::MainMenuMusic:
            path = "assets/music/music/main-menu.wav";
            break;
        case yu::audio::SoundId::DeckBuilderMusic:
            path = "assets/music/music/deck-editor.wav";
            break;
        case yu::audio::SoundId::ClickSoundEffect:
            path = "assets/music/sound-effect/click.wav";
            break;
        case yu::audio::SoundId::HoverSoundEffect:
            path = "assets/music/sound-effect/hover.wav";
        default:
            break;
    }

    return path;
}