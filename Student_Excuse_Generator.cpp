#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);  //  allows full name

    // handle empty input
    if (name.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }

    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} was about to finish the homework when the WiFi suddenly disappeared.",
        "{name}'s computer froze right before submission.",
        "{name} lost the file due to a mysterious system crash.",
        "{name}'s keyboard stopped cooperating at the last moment.",
        "{name} accidentally deleted the assignment file.",
        "{name}'s laptop started updating for hours.",
        "{name} couldn't access the internet in time.",
        "{name}'s system ran out of storage suddenly.",
        "{name} forgot to save the assignment before shutdown."
    };

    // better randomness using modern C++
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, excuses.size() - 1);

    int index = dist(gen);

    string excuse = excuses[index];

    //  correct placeholder replacement
    size_t pos = excuse.find("{name}");
    if (pos != string::npos) {
        excuse.replace(pos, 6, name);
    }

    cout << excuse << endl;

    return 0;
}