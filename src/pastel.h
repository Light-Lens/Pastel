#pragma once

#include "utils/Utils/strings.h"
#include "utils/FileIO/fileio.h"
#include "Pastel/Errors/errors.h"
#include "Pastel/Lexer/lexer.h"
#include "Pastel/Parser/parser.h"

// initialize .pastel folder with it's subdirectories
// this folder will contain content such as external installable libraries, building scripts and files
// the entire code will be converted from pastel code to c++ code and then copied to the cache folder to compile.
void init_folders()
{
    utils::create_dir(".pastel");
    utils::create_dir(".pastel/vendor");
    utils::create_dir(".pastel/scripts");
    utils::create_dir(".pastel/cache");
}

// install any libraries into the vendor folder to be used by c++
// for eg, SDL2 or spdlog, it will automatically be included during compilation
void install_lib(const std::string& lib_name)
{
    if (!utils::strings::is_empty(lib_name))
        utils::copy_dir(lib_name, ".pastel/vendor/" + lib_name);
}

// push each line into a string vector then close the file
// throw error if the file can't be opened.
std::vector<std::string> load_file(const std::string& filename)
{
    std::fstream file;
    std::string current_line;
    std::vector<std::string> code;

    file.open(filename);

    if (!file)
        Pastel::errors::open_file(filename);

    while (std::getline(file, current_line))
        code.push_back(current_line);

    file.close();
    return code;
}

// tokenizse the file line by line.
// then translate the each line to c++ syntax using the parser.
void run(const std::vector<std::string>& code)
{
    Pastel::lexer lex(code);
    Pastel::parser parse(lex.tokenized_code, code);
}
