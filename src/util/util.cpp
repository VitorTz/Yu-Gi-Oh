#include "../../include/util/util.hpp"


int yu::randint(const int start, const int end) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> d(start, end - 1);
    return d(rng);
}


std::vector<std::filesystem::path> yu::get_files_from_dir(const std::filesystem::path &dir) {
    std::vector<std::filesystem::path> files;
    for (const auto& p : std::filesystem::directory_iterator(dir)) {
        files.push_back(p.path());
    }
    return files;
}


std::filesystem::path yu::get_random_file_from_dir(const std::filesystem::path &dir) {
    std::vector<std::filesystem::path> files = yu::get_files_from_dir(dir);
    std::filesystem::path file;
    if (files.empty()) {    
        return file;
    }
    file = files[yu::randint(0, files.size())];
    return file;
}