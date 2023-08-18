#include <iostream>

using namespace std;

bool endswith(const string& sentence, const string& what_to_find)
{
    return sentence.length() >= what_to_find.length() &&
        sentence.compare(sentence.length() - what_to_find.length(), what_to_find.length(), what_to_find) == 0;
}

int main(int argv, char** args)
{
    string name = args[1];
    if (argv > 1)
    {
        if (endswith(name, ".pastel"))
            cout << name << endl;
    }

    return 0;
}
