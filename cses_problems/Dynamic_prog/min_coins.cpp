#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
#define MAX (ll)1e6 + 1

void solve() {
    ll n, x;
    cin >> n >> x;
    ll coins[n];
    F(i, n) cin >> coins[i];
    vector<ll> val(x + 1);
    val[0] = 0;
    for(ll i = 1; i <= x; i++) {
        val[i] = MAX;
        for (auto c: coins) {
            if (i - c >= 0)
                val[i] = min(val[i], (val[i - c] + 1));
        }
    }
    if (val[x] == MAX) cout << -1 << "\n";
    else cout << val[x] << "\n";
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
