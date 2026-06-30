#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fi(i, n) for(int i = 1; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

vector<ll> calc_lps(string& s) {
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


void solve() {
    int N, Q;
    cin >> N >> Q;
    string txt;
    string p = "";
    cin >> txt;
    int n = txt.size();
    int res[n][n];
    F(x, n) {
        F(y, n) {
            p = txt.substr(0, x + 1) + txt.substr(n - y - 1, y + 1);
            int np = p.size();
            int j = 0;
            ll resp = 0;
            auto lps = calc_lps(p);
            F(i, n) {
                if (txt[i] == p[j]) {
                    j++;
                    if (j == np) {
                        resp++;
                        j = lps[j - 1];
                    }
                } else {
                    if (j != 0) {
                        j = lps[j - 1];
                        i--;
                    } 
                }
            }
            res[x][y] = resp;
        }
    }
    while (Q--){
        ll x, y;
        cin >> x >> y;
        cout << res[x - 1][y - 1] << '\n';
    }
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
