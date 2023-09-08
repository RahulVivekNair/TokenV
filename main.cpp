#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
using namespace std;
int main(int argc, char **argv)
{
    if (argc != 3 || string(argv[1]) != "-t")
    {
        std::cerr << "Usage: main.exe -t <number_of_tokens>" << endl;
        return 1;
    }
    double numTokens = atof(argv[2]);
    if (numTokens <= 0)
    {
        std::cerr << "Invalid number of tokens" << endl;
        return 1;
    }
    vector<string> words = {"Hello", "world", "This", "is", "a", "sample", "output", "from", "the", "program.", "Let's", "see", "how", "it", "works.", "Let's", "see", "how", "fast", "it", "goes."};
    cout << "Hello World!" << endl;
    int delayDuration = static_cast<int>((1.0 / numTokens) * 1000000);
    while (true)
    {
        for (auto token : words)
        {
            cout << token << " ";
            this_thread::sleep_for(chrono::microseconds(delayDuration));
        }
        cout << endl;
    }

    return 0;
}