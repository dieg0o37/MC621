#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
#define MOD (ll)10
#define val (ll)1378

ll exp_rapida(ll n){
    ll base = val;
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        n >>= 1;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    cout << exp_rapida(n) << "\n";
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
