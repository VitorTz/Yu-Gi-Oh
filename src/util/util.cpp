#include "../../include/util/util.hpp"


int yu::randint(const int start, const int end) {
    // https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c#13445752
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> d(start, end-1); // distribution in range [1, 6]
    return d(rng);
}
