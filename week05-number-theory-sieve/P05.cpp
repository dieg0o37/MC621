#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
#define MAX (ll)1e18

set<ll> n_calculados;
set<pair<ll, ll>>  prime_products;
ll primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}; // maior q isso e estoura
int i = 0;
ll pp = 1;

ll maior_pp_menor_que(ll n) {
    if (!n_calculados.empty() && n <= *(n_calculados.rbegin())) {
        return (prime_products.lower_bound(make_pair(n, 0))->second - 1);
    }
    n_calculados.insert(n);
    
    while (pp <= n) {
        prime_products.insert(make_pair(pp*primos[i], i + 1));
        pp *= primos[i];
        i++;
    }
    return i - 1;
}


void solve() {
    ll n;
    cin >> n;
    if (n >= 614889782588491410) {
        cout << 15 << "\n";
        return;
    }
    cout << maior_pp_menor_que(n) << "\n";
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
