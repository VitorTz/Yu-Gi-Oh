#pragma once
#include <filesystem>
#include <fstream>
#include <map>

namespace yu {


    enum CardType {
        FlipEffectMonster
    };

    enum Race {

    };

    enum FrameType {

    };

    enum Attribute {
        None
    };

    const std::map<std::string, yu::CardType> cardTypeByStr = {
        {"Flip Effect Monster", yu::CardType::FlipEffectMonster}
    };

    const std::map<std::string, yu::Race> raceByStr = {
        
    };

    const std::map<std::string, yu::FrameType> frameTypeByStr = {
        
    };

    const std::map<std::string, yu::Attribute> attributeByStr = {
        
    };

    class Card {

        public:
            std::string name;
            std::string stringId;
            int integerId;
            yu::CardType type;
            std::string desc;
            yu::Race race;
            yu::FrameType frameType;
            int atk;
            int def;
            yu::Attribute attribute;
            int level;
            std::filesystem::path imagePath;
        
        public:
            Card(const std::filesystem::path& cardFile) {
                std::ifstream file;
                file.open(cardFile);
                int index = 0;
                std::string line;
                if (!file.is_open()) {
                    std::cerr << "[FALHA AO ABRIR CARTA " << cardFile << "]\n";
                    std::exit(EXIT_FAILURE);
                }                
                while (std::getline(file, line)) {
                    switch (index) {
                        case 0:
                            this->name = line;
                            break;
                        case 1:
                            this->stringId = line;
                            this->integerId = std::stoi(line);
                            break;
                        case 2:
                            this->type = cardTypeByStr.at(line);
                            break;
                        case 3:
                            this->desc = line;
                            break;
                        case 4:
                            this->race = yu::raceByStr.at(line);
                            break;
                        case 5:
                            this->frameType = yu::frameTypeByStr.at(line);
                            break;
                        case 6:
                            this->atk = std::stoi(line);
                            break;
                        case 7:
                            this->def = std::stoi(line);
                            break;
                        case 8:
                            this->attribute = yu::attributeByStr.find(line) != yu::attributeByStr.end() ? yu::attributeByStr.at(line) : yu::Attribute::None;
                            break;
                        case 9:
                            this->level = std::stoi(line);
                            break;
                        case 10:
                            this->imagePath = std::filesystem::path(line);
                            break;
                        default:
                            break;
                    }
                } 
                file.close();

            }

    };
    
} // namespace yu
