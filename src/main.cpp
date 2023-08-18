#include "manager.h"

using namespace std;

bool endswith(const string& sentence, const string& what_to_find)
{
    return sentence.length() >= what_to_find.length() &&
        sentence.compare(sentence.length() - what_to_find.length(), what_to_find.length(), what_to_find) == 0;
}

int main(int argc, char *argv[])
{
    vector<string> cmd_line_args = manager::arguments(argc, argv);

    string name = cmd_line_args[0];
    if (argc > 1)
    {
        if (endswith(name, ".pastel"))
            cout << name << endl;
    }

    return 0;
}
