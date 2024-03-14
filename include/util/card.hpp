#ifndef YUGIOH_CARD_HPP
#define YUGIOH_CARD_HPP
#include <filesystem>


namespace yu {


    class Card {

        public:
            static std::filesystem::path getPath(const std::string& cardId);

    };

}


#endif