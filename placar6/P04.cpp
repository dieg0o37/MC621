#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

void solve() {
    ll n, m;
    cin >> n >> m;
    ll n_n[5];
    ll n_m[5];

    ll n_seq = n/5;
    ll m_seq = m/5;
    for (int i = 0; i < 5; i++) {
        n_m[i] = m_seq;
        n_n[i] = n_seq;
    }

    ll resto = n%5;
    for (int i = 0; i < resto; i++) { 
        n_n[i]++;
    }
    resto = m%5;
    for (int i = 0; i < resto; i++) { 
        n_m[i]++;
    }

    ll res = 0;
    for (int i = 0; i < 4; i++) {
        res += n_m[3 - i]*n_n[i];
    }
    res += n_m[4]*n_n[4];

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
