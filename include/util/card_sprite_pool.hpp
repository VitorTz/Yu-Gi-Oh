#pragma once
#include "../component/sprite.hpp"
#include <vector>


namespace yu {


    class CardSpritePool {

        private:
            std::vector<std::filesystem::path> files;
            const std::size_t maxSize;

        public:
            CardSpritePool(
                std::size_t maxSize
            );
            void add(const std::filesystem::path& file);
            const std::filesystem::path& get(std::size_t i) const;
            std::size_t getMaxSize() const;
            std::size_t size() const;


    };
    
} // namespace yu
