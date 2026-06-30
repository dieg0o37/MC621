#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

ll mdc(ll x, ll d) {
    if (d == 0) return x;
    return (mdc(d, x%d));
}

void solve() {
    ll x, k, d;
    cin >> x >> k >> d;
    x = (x > 0? x : -x);
    if (x < d) {
        if (k %2 == 0) cout << x << "\n";
        else cout << d - x << "\n";
        return;
    }
    ll c = x/d;
    ll resto = x%d;
    if (c > k) {
        cout << x - k*d << "\n";
        return;
    }
    k -= c;
    cout << (k%2 == 0? resto : d - resto) << "\n";

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
