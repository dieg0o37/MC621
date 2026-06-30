#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)


/*
(n k) = n!/(k!(n-k)!) = n*(n-1)*...*(n - k + 1)/(k*(k-1)*...*1)

*/
ll comb(int n, int k) {
    if (k == n || k == 0) return 1;
    if (k == 1) return n;
    if (2*k > n) k = n - k;
    ll res = 1;
    for (int i = 1; i <= k; i ++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}


void solve() {
    int n;
    double p;
    cin >> n >> p;
    double res = pow(p, n);
    for(int i = 1; i < n; i++) {
        int mp = n + i - 1;
        res += (double)((comb(mp, i))*(pow(p, n))*(pow(1-p, i)));
    }
    cout << fixed << setprecision(2)<< res << "\n";
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
