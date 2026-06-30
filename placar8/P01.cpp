#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

vector<ll> calc_pi(string& s) {
    int n = s.size();
    vector<ll> lps(n, 0);

    int len = 0;
    for (int i = 1; i < n; i++ ){
        if (s[i] == s[len]) {
            len ++;
            lps[i] = len;
        } else {
            if (len == 0) {
                lps[i] = 0;
            } else {
                len = lps[len - 1];
                i--;
            }
        }
    }

    return lps;
}
vector<int> calc_z(string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            z[i] = min(r - i + 1, z[k]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
void solve() {
    string s;
    cin >> s;
    auto lsp = calc_pi(s);
    auto z = calc_z(s);
    for (auto u: lsp) {
        cout << u << '\n';
    }
    cout << '\n';
    for (auto k: z) {
        cout << k << '\n';
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
