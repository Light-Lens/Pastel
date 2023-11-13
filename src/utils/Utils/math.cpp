#include "pastelpch.h"
#include "math.h"

namespace utils
{
    int math::calculate_padding(const size_t& count, const size_t& max_padding_len)
    {
        size_t column_width = 0;
        for (size_t i = 0; i < count; i += 2)
            column_width = std::max(column_width, max_padding_len);

        return column_width;
    }
}
