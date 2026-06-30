#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 2; i <= n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
set<ll> result;
vector<bool> calculados;
void solver(ll n){
    if (n == 2) {
        result.insert(2);
        return;
    }
    if (n == 3) {
        result.insert(3);
        return;
    }
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            ll prime = p;
            while (n % p == 0){
                result.insert(prime);
                prime = p*prime;
                n /= p;
            }
        }
    }
    if (n > 1)
        result.insert(n);
}
void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    F(i, n) {
        solver(i);
    }
    cout << result.size() << "\n";
    ll i = 0;
    for(auto u: result) {
        cout << u << (i == result.size() - 1? "\n" : " ");
        i++;
    }
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
