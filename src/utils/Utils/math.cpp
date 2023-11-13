#include "pastelpch.h"
#include "math.h"

namespace utils
{
    int math::calculate_padding(const int& count, const int& max_padding_len)
    {
        return std::max(max_padding_len - static_cast<int>(log10(count)), 0);
    }
}
