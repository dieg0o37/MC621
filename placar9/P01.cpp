#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

void solve() {
    string s1;
    cin >> s1;
    bool cortar = false;
    int res = 1;
    for(auto u: s1) {
        if (u == '1') {
            cortar = true;
        } else if (cortar) {
            res++;
            cortar = false;
        }
    }
    cout << res << '\n';
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
