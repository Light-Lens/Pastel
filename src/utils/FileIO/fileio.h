#pragma once

namespace utils
{
    void create_dir(const std::filesystem::path& folderpath);
    void copy_dir(const std::filesystem::path& source, const std::filesystem::path& destination);
}
