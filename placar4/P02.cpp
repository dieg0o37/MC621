#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

ostream& operator<<(ostream& os, __int128_t v) {
    bool neg = false;
    if (v == 0) {
        os << "0";
        return os;
    }
    string n;
    if (v < 0) {
        neg = true; 
        v *= -1;
    }
    while(v) {
        int digito = v%10;
        n.push_back(48 + digito);
        v /= 10;
    }
    if (neg) n.push_back('-');
    reverse(n.begin(), n.end());
    os << n;
    return os;
}

void solve() {
    while(true) {
        string line;
        getline(cin, line, '\n');
        if (line.empty()) break;
        stringstream ss(line);
        ll n, k;
        ss >> n >> k;
        if (k == 1) {
            cout << ((__int128_t)1 << n) - 1 << "\n";
            continue;
        }
        vector<vector<__int128_t>> dp(n + 1, vector<__int128_t>(k,0));
        dp[1][0] = 1;
        dp[1][1] = 1;
        
        for(int i = 2; i < n + 1; i++) {
            F(h, k) {
                dp[i][0] += dp[i - 1][h];
                
            }
            
            for(int j = 1; j < k; j++) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        
        }
        __int128_t n_quero = 0;
        F(i, k) {
            n_quero += dp[n][i];
        }
        __int128_t total = ((__int128_t)1 << n);
        cout << total - n_quero << "\n";
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
