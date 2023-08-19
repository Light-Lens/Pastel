#include "../pastelpch.h"
#include "fileio.h"

void create_dir(const std::filesystem::path& folderpath)
{
    // Check if the folder already exists
    if (!std::filesystem::exists(folderpath))
    {
        // Create the folder
        if (!std::filesystem::create_directory(folderpath))
            std::cout << "Failed to create folder." << std::endl;
    }
    
    else
        std::cout << "Folder already exists." << std::endl;
}
