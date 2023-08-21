#include "../pastelpch.h"
#include "tokens.h"

namespace Pastel
{
    /**
    * Concatenates multiple vectors into a single vector.
    *
    * This template function takes an initializer list of vectors and concatenates
    * their contents into a new vector. The order of concatenation is based on the
    * order of vectors in the initializer list.
    *
    * @tparam T The type of elements in the vectors.
    * @param vectors An initializer list of vectors to be concatenated.
    * @return A new vector containing elements from all input vectors.
    */
    template <typename T>
    std::vector<T> concatenate_vectors(const std::initializer_list<std::vector<T>>& vectors)
    {
        std::vector<T> result;
        for (const auto& vector : vectors)
            result.insert(result.end(), vector.begin(), vector.end()); // Insert the elements from the current vector to the end of the result vector.

        return result;
    }

    const std::vector<std::string> include_keywords = {
        "include",
        "import",
        "using"
    };

    const std::vector<std::string> variable_keywords = {
        "let",
        "auto",
        "const",
        "var",
        "str",
        "string",
        "char",
        "int",
        "float",
        "bool",
        "double",
        "enum"
    };

    const std::vector<std::string> boolean_keywords = {
        "true",
        "false"
    };

    const std::vector<std::string> container_keywords = {
        "fun",
        "void",
        "struct",
        "class",
        "namespace"
    };

    const std::vector<std::string> control_flow_keywords = {
        "return",
        "break",
        "continue",
        "switch",
        "case",
        "if",
        "elif",
        "else"
    };

    const std::vector<std::string> keywords = concatenate_vectors({
        include_keywords,
        variable_keywords,
        boolean_keywords,
        container_keywords,
        control_flow_keywords
    });
}
