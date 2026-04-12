#include <iostream>
using namespace std;

const int N = 10000000;

int cnt[N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= N; i++) {
        if (cnt[i] == 0) { 
            for (int j = i; j <= N; j += i) {
                cnt[j]++;
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int k = cnt[n];

        int ans = 1;
        for (int i = 0; i < k; i++) {
            ans *= 2;
        }

        cout << ans << "\n";
    }

    return 0;
}
