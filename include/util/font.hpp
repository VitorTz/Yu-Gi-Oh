#pragma once
#include <map>
#include <filesystem>


namespace yu {


    enum FontId {
        Light,
        Regular,
        Semibold,
        Bold
    };  


    const std::map<yu::FontId, std::filesystem::path> fontPathById = {
        {yu::FontId::Light, "assets/font/Poppins-Light.ttf"},
        {yu::FontId::Regular, "assets/font/Poppins-Regular.ttf"},
        {yu::FontId::Semibold, "assets/font/Poppins-SemiBold.ttf"},
        {yu::FontId::Bold, "assets/font/Poppins-Bold.ttf"}
    };
    
    
} // namespace yu
