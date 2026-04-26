#include <iostream>
using namespace std;

class Bank {
private:
    int id[1000];
    long long bal[1000];
    int n;

public:
    Bank() {
        n = 0;
    }

    int findUser(int x) {
        for (int i = 0; i < n; i++) {
            if (id[i] == x)
                return i;
        }
        return -1;
    }

    bool CREATE(int x, long long y) {
        int i = findUser(x);

        if (i == -1) {
            id[n] = x;
            bal[n] = y;
            n++;
            return true;
        }

        bal[i] = bal[i] + y;
        return false;
    }

    bool DEBIT(int x, long long y) {
        int i = findUser(x);

        if (i == -1 || bal[i] < y)
            return false;

        bal[i] = bal[i] - y;
        return true;
    }

    bool CREDIT(int x, long long y) {
        int i = findUser(x);

        if (i == -1)
            return false;

        bal[i] = bal[i] + y;
        return true;
    }

    long long BALANCE(int x) {
        int i = findUser(x);

        if (i == -1)
            return -1;

        return bal[i];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string op;
        cin >> op;

        int x;
        long long y;

        if (op == "CREATE") {
            cin >> x >> y;
            if (bank.CREATE(x, y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (op == "DEBIT") {
            cin >> x >> y;
            if (bank.DEBIT(x, y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (op == "CREDIT") {
            cin >> x >> y;
            if (bank.CREDIT(x, y))
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }

        else if (op == "BALANCE") {
            cin >> x;
            cout << bank.BALANCE(x) << endl;
        }
    }

    return 0;
}
