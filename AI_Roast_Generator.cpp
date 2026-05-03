#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin, name);  // read full name including spaces

    if (name.empty()) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }

    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would win gold.",
        "{name}'s code has more bugs than a jungle.",
        "{name} doesn't debug code, they just hope for miracles.",
        "{name}'s logic is like WiFi, nweak and unstable.",
        "{name} compiles confidence, not code.",
        "{name}'s code works....sometimes.... maybe.",
        "{name} treats errors as features.",
        "{name}'s keyboard deserves better.",
        "{name} and deadlines are never in sync."
    };

    // generate random index
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, roasts.size() - 1);

    int index = dist(gen);

    string roast = roasts[index];

    // replace {name} with actual name
    size_t pos = roast.find("{name}");
    if (pos != string::npos) {
        roast.replace(pos, 6, name);
    }

    cout << roast << endl;

    return 0;
}
