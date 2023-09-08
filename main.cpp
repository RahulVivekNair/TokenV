#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
    if (argc != 3 || string(argv[1]) != "-t")
    {
        std::cerr << "Usage: main.exe -t <number_of_tokens>" << endl;
        return 1;
    }
    int numTokens = atoi(argv[2]);
    if (numTokens <= 0)
    {
        std::cerr << "Invalid number of tokens" << endl;
        return 1;
    }
    cout << "Hello World!" << endl;
    return 0;
}