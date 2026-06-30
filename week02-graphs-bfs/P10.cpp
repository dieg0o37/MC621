#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Your code here
    int n;
    long long k;
    cin >> n;
    if (n == 1) {
        cin >> k;
        cout << "first" << "\n";
        return;
    }
    cin >> k;
    long long sum = k;
    for (int i = 1; i < n; i++) {
        cin >> k;
        sum ^= k;
    }
    cout << (sum != 0 ? "first" : "second") << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the following lines to read from a file instead of stdin
    /*
    #ifndef ONLINE_JUDGE
        freopen("P10.in", "r", stdin);
    #endif
    */
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
