#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
int string_align(const std::string& s1, const std::string& s2) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int score = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            int match_mismatch = dp[i - 1][j - 1] + score;
            int del = dp[i - 1][j] + 1;
            int ins = dp[i][j - 1] + 1;
            dp[i][j] = std::min({match_mismatch, del, ins});
        }
    }
    return dp[n][m];
}
void solve() {
    int x, y;
    string s1, s2;
    string line;
    while(true) {
        getline(cin, line, '\n');
        if (line.empty()) break;
        stringstream ss1(line);
        ss1 >> x >> s1;
        getline(cin, line, '\n');
        stringstream ss2(line);
        ss2 >> y >> s2;
        cout << string_align(s1, s2) << '\n';
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
