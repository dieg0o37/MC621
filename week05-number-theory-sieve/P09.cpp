#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
ll calc_sweetness(ll n){
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
bool is_it_prime(ll n) {
    if (n == 1 || n == 0) {
        return false;
    } else if (n == 2 || n==3) {
        return true;
    }
    for(ll p = 2; p*p <= n; p++) {
        if (n%p == 0)  {
            return false;
        }
    }
    return true;
}
vector<ll> v;
vector<ll> seg_tree;
void build(int low, int high, int i) {
    if (low == high) {
        seg_tree[i] = v[low];
        return;
    }
    int mid = (low + high)/2;
    build(low, mid, 2*i + 1);
    build(mid + 1, high, 2*i + 2);
    seg_tree[i] = seg_tree[2*i + 1] + seg_tree[2*i + 2];
}

ll query(int l, int r, int low, int high, int i) {
    if (low >= l && high <= r) {
        return seg_tree[i];
    }
    if (low > r || high < l || low > high) {
        return 0;
    }
    int mid = (low + high)/2;
    ll rt_n = query(l, r, mid + 1, high, 2*i + 2);
    ll lf_n = query(l, r, low, mid, 2*i + 1);
    return rt_n + lf_n;
}
void solve() {
    ll N, Q;
    cin >> N >> Q;
    seg_tree.resize(4*N);
    v.resize(N);
    F(i, N) {
        ll input;
        cin >> input;
        if (is_it_prime(calc_sweetness(input))) {
            v[i] = 1;
        } else {
            v[i] = 0;
        }
    }
    build(0, N - 1, 0);
    ll l, r;
    while (Q--) {
        cin >> l >> r;
        cout << query(l - 1, r - 1, 0, N - 1, 0) << "\n";
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
