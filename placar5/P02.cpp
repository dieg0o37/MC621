#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
#define MAX (ll)1e6

vector<ll> sieve(MAX + 1);
set<ll> primos;

void solve() {
    ll n;
    cin >> n;
    fill(sieve.begin(), sieve.end(), 0);
    sieve[1] = 1;
    sieve[0] = 1;
    for(ll i = 2; i <= MAX; i ++) {
        if (sieve[i]) continue;
        primos.insert(i*i);
        for(ll j = 2*i; j <= MAX; j += i) {
            sieve[j] = i;
        }
    }
    while (n--) {
        ll X;
        cin >> X;
        if (X % 2 == 0) {
            if (X == 4) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
            continue;
        }
        if (primos.find(X) != primos.end()) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
