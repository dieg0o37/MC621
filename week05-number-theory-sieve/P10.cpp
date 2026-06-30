#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
// Inspirado do texto complementar
ll totient(ll n){
    ll result = n;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;

    return result;
}
void solve() {
    ll n;
    cin >> n;
    cout << totient(n) << "\n";
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
