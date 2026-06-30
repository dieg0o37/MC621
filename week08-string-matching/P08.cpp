#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n - 1; i >=0; i--)
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
    getline(cin, s, '\n');
    auto z = calc_z(s);
    set<int> st;
    int n = s.size();
    for(int i = 0; i < n; i++ ){
        if (z[i] + i == n) {
            st.insert(z[i]);
        }
    }
    
    if (st.empty()) {
        return;
    }
    for (auto u: st) cout << u << " ";
    cout << "\n";
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
