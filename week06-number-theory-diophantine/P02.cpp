#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

ll ext_mdc(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;

    ll mdc = ext_mdc(b, a%b, x1, y1);

    x = y1;
    y = x1 - (a/b)*y1;

    return mdc;
}


void solve() {
    // xK + yN = -S

    ll K, N, S;
    cin >> N >> S >> K;
    if (S == 0) {
        cout << 0 << "\n";
        return;
    }
    ll x, y;
    ll mdc = ext_mdc(K, N, x, y);
    if (S % mdc != 0) {
        cout << -1 << "\n";
        return;
    }
    x = x * (-S/mdc);
    ll mod = N/mdc;
    x %= mod;
    while (x < 0) {
        x = (x + mod)%mod;
    }
    cout << x << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
