#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

vector<string> loadWordsFromFile(const string &filename)
{
    vector<string> words;
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Failed to open file: " << filename << endl;
        exit(1);
    }

    string word;

    while (file >> word)
    {
        words.push_back(word);
    }

    if (file.bad())
    {
        cerr << "Error: Error reading from file: " << filename << endl;
        exit(1);
    }

    return words;
}

void printUsage()
{
    cerr << "Usage: main.exe -t <number_of_tokens> [-f <filename>]" << endl;
}

void processCommandLineArguments(int argc, char **argv, double &numTokens, string &filename)
{
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
}

bool validateCommandLineArguments(double numTokens, const string &filename)
{
    if (numTokens <= 0)
    {
        cerr << "Invalid number of tokens" << endl;
        return false;
    }

    if (!filename.empty())
    {
        if (!fs::exists(filename))
        {
            cerr << "Error: File does not exist: " << filename << endl;
            return false;
        }

        if (!fs::is_regular_file(filename))
        {
            cerr << "Error: Not a regular file: " << filename << endl;
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    double numTokens = 0.0;
    string filename;

    processCommandLineArguments(argc, argv, numTokens, filename);

    if (argc < 3 || !validateCommandLineArguments(numTokens, filename))
    {
        printUsage();
        return 1;
    }

    vector<string> words;

    if (!filename.empty())
    {
        words = loadWordsFromFile(filename);
    }
    else
    {
        words = {"Hello", "world", "This", "is", "a", "sample", "output", "from", "the", "program.", "Let's", "see", "how", "it", "works.", "Let's", "see", "how", "fast", "it", "goes."};
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
