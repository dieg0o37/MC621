#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

void solve() {
    ll n;
    cin >> n;
    ll t[n];
    F(i, n) cin >> t[i];
    sort(t, t + n);
    ll sum = 0;
    ll total = (n%2 == 0 ? n/2 : n/2 + 1);
    for(ll i = total; i < n; i++) {
        sum += t[i];
    }
    cout << sum << "\n";
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
