#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
ll exp_rapida(ll n, ll val, ll MOD){
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
    ll N, X, M;
    cin >> N >> X >> M;
    ll X_sq = ((X%M)*(X%M))%M;
    ll res = X;
    ll temp = exp_rapida(2*N, X, M);
    temp = ((temp%M) + M - (X_sq%M))%M;
    X_sq = ((X_sq%M) + M - (1%M))%M;;
    temp /= X_sq;
    res = (res + temp)%M;
    cout << res << "\n";
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
