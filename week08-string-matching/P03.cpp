#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
#define MOD (ll)(1e9 + 7)
ll exp_rap(ll exp) {
    ll base = 26;
    ll resp = 1;
    while (exp > 0) {
        if (exp & 1) resp = (resp*base)%MOD;
        base  = (base*base)%MOD;
        exp >>=1;
    }
    return resp;
}

void solve() {
    ll n, m;
    cin >> n;
    string s;
    cin >> s;

    m = s.size();
    if (m > n) {
        cout << 0 << '\n';
    }
    cout << ((n - m + 1)*exp_rap(n - m))%MOD << '\n';
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
