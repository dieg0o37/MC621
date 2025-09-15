#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

void solve() {
    int n, x;
    cin >> n >> x;
    int coins[n];
    F(i, n) {
        cin >> coins[i];
    }
    int best = INT_MAX;
    int val[x + 1];
    val[0] = 0;
    for (int i = 1; i <= x; i++) {
        val[i] = INT_MAX;
        for (auto u: coins) {
            if (i >= u)
                val[i] = min(val[i], val[i - u] + 1);
        }
    }
    if (val[x] == INT_MAX) cout << -1 << "\n";
    cout << val[x] << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    ll t;
    cin >> t;
    while(t--)
    */
        solve();

    return 0;
}
