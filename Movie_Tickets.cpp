#include <iostream>
using namespace std;

class MovieTicket {
    bool booked[1001][1001];
    int seats[1001];

public:
    MovieTicket() {
        for (int i = 0; i < 1001; i++) {
            seats[i] = 100;
            for (int j = 0; j < 1001; j++) {
                booked[i][j] = false;
            }
        }
    }

    bool BOOK(int x, int y) {
        if (booked[x][y] || seats[y] == 0)
            return false;

        booked[x][y] = true;
        seats[y]--;
        return true;
    }

    bool CANCEL(int x, int y) {
        if (!booked[x][y])
            return false;

        booked[x][y] = false;
        seats[y]++;
        return true;
    }

    bool IS_BOOKED(int x, int y) {
        return booked[x][y];
    }

    int AVAILABLE_TICKETS(int y) {
        return seats[y];
    }
};

int main() {
    int q;
    cin >> q;

    MovieTicket mt;

    while (q--) {
        string s;
        cin >> s;

        if (s == "BOOK") {
            int x, y;
            cin >> x >> y;

            if (mt.BOOK(x, y))
                cout << "true\n";
            else
                cout << "false\n";
        }

        else if (s == "CANCEL") {
            int x, y;
            cin >> x >> y;

            if (mt.CANCEL(x, y))
                cout << "true\n";
            else
                cout << "false\n";
        }

        else if (s == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;

            if (mt.IS_BOOKED(x, y))
                cout << "true\n";
            else
                cout << "false\n";
        }

        else if (s == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;

            cout << mt.AVAILABLE_TICKETS(y) << "\n";
        }
    }

    return 0;
}
