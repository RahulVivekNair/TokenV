#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <filesystem>
using namespace std;

vector<string> loadWordsFromFile(const string &filename)
{
    vector<string> words;
    ifstream file(filename);
    string word;

    while (file >> word)
    {
        words.push_back(word);
    }

    return words;
}
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "Usage: main.exe -t <number_of_tokens> [-f <filename>]" << endl;
        return 1;
    }

    double numTokens = 0.0;
    string filename;
    vector<string> words;

    for (int i = 1; i < argc; ++i)
    {
        if (string(argv[i]) == "-t" && i + 1 < argc)
        {
            numTokens = atof(argv[i + 1]);
        }
        else if (string(argv[i]) == "-f" && i + 1 < argc)
        {
            filename = argv[i + 1];
        }
    }

    if (numTokens <= 0)
    {
        cerr << "Invalid number of tokens" << endl;
        return 1;
    }

    words = {"Hello", "world", "This", "is", "a", "sample", "output", "from", "the", "program.", "Let's", "see", "how", "it", "works.", "Let's", "see", "how", "fast", "it", "goes."};

    if (!filename.empty() && filesystem::exists(filename) && filesystem::is_regular_file(filename))
    {
        words = loadWordsFromFile(filename);
    }

    if (words.empty())
    {
        cerr << "Error: Failed to load words from the file or no default words provided." << endl;
        return 1;
    }
    int delayDuration = static_cast<int>((1.0 / numTokens) * 1000000);

    while (true)
    {
        for (const auto &token : words)
        {
            cout << token << " ";
            this_thread::sleep_for(chrono::microseconds(delayDuration));
        }
    }

    return 0;
}