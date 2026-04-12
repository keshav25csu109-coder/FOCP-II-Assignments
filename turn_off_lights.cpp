#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    for (int L = 1; L <= n; L++) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;     
                i += L - 1;   
            }
        }

        if (count <= k) {
            cout << L;
            break;
        }
    }

    return 0;
}
