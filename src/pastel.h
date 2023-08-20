#pragma once

#include "utils/strings.h"
#include "utils/fileio.h"
#include "Pastel/errors.h"
#include "Pastel/lexer.h"
#include "Pastel/parser.h"

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
    utils::copy_dir(lib_name, ".pastel/vendor/" + lib_name);
}

// tokenizse the file line by line.
// then translate the each line to c++ syntax using the parser.
void run(std::fstream& file)
{
    int current_line_no = 1;
    std::string current_line;

    while (std::getline(file, current_line))
    {
        Pastel::lexer lex;
        lex.current_line = current_line;
        lex.current_line_no = current_line_no;

        Pastel::parser parse;
        parse.current_line = current_line;
        parse.current_line_no = current_line_no;
        parse.translator(lex.tokenizer());

        ++current_line_no;
    }
}

// void run(const std::string& filename)
// {
//     std::fstream file;

//     // Open the file
//     file.open(filename);

//     // Interpret the file line by line
//     if (file)
//     {
//         int current_line_no = 1;
//         std::string current_line;

//         while (std::getline(file, current_line))
//         {
//             Pastel::lexer lex;
//             lex.current_line = current_line;
//             lex.current_line_no = current_line_no;

//             Pastel::parser parse;
//             parse.current_line = current_line;
//             parse.current_line_no = current_line_no;
//             parse.translator(lex.tokenizer());

//             ++current_line_no;
//         }
//     }

//     // Throw error if the file can't be opened.
//     else
//         Pastel::errors::open_file(filename);

//     // Close the file
//     file.close();
// }
