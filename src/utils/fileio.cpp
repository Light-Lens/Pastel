#include "../pastelpch.h"
#include "fileio.h"

namespace utils
{
    void create_dir(const std::filesystem::path& folderpath)
    {
        // Check if the folder already exists
        if (std::filesystem::exists(folderpath))
            return;

        // Create the folder
        if (!std::filesystem::create_directory(folderpath))
            std::cout << "Failed to create folder." << std::endl;
    }

    void copy_dir(const std::filesystem::path& source, const std::filesystem::path& destination)
    {
        if (std::filesystem::exists(source) && std::filesystem::is_directory(source))
        {
            create_dir(destination);

            for (const auto &entry : std::filesystem::directory_iterator(source))
            {
                const std::filesystem::path currentPath = entry.path();
                const std::filesystem::path newPath = destination / currentPath.filename();

                if (std::filesystem::is_directory(currentPath))
                {
                    copy_dir(currentPath, newPath);
                }

                else if (std::filesystem::is_regular_file(currentPath))
                {
                    std::filesystem::copy_file(currentPath, newPath, std::filesystem::copy_options::overwrite_existing);
                }
            }
        }
    }
}
