#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void calc_sums(vector<ll>& v, vector<ll>& out, ll l, ll r) {
    if (l > r) {
        out.push_back(0);
        return;
    }
    for(ll i = 0; i < (1<<(r - l+ 1)); i++ ){
        ll cur_sum = 0;
        for (ll j = 0; j < (r - l + 1); j++) {
            if (i & (1<<j)) cur_sum += v[l + j];
        }
        out.push_back(cur_sum);
        cur_sum = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> l_sum;
    vector<ll> r_sum;

    calc_sums(v, l_sum, 0, n/2 - 1);
    calc_sums(v, r_sum, n/2, n - 1);

    sort(l_sum.begin(), l_sum.end());

    for (auto u: r_sum) {
        if (u > x) continue;
        ll target = x - u;
        auto targ_count = equal_range(l_sum.begin(), l_sum.end(), target);
        res += (targ_count.second - targ_count.first);
    }
    cout << res << "\n";
}