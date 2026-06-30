#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
int string_align(const std::string& s1, const std::string& s2, int match, int mismatch, int gap) {
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i * gap;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j * gap;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int score = (s1[i - 1] == s2[j - 1]) ? match : mismatch;
            int match_mismatch = dp[i - 1][j - 1] + score;
            int del = dp[i - 1][j] + gap;
            int ins = dp[i][j - 1] + gap;
            dp[i][j] = std::max({match_mismatch, del, ins});
        }
    }
    return dp[n][m];
}
void solve() {
    string dump, q, s, blank;
    
    getline(cin, dump, '\n');
    getline(cin, q, '\n');
    int n = q.size();
    vector<string> sim_s;
    int max = INT_MIN;
    while(true){
        getline(cin, blank, '\n');
        getline(cin, dump, '\n');
        if (dump.empty()) break;
        getline(cin, s, '\n');
        int m = s.size();
        int best_possible = 5*min(m, n) - 7*(n >= m ? n - m : m - n);
        if (best_possible < max) {
            continue;
        }
        int sim = string_align(q, s, 5, -4, -7);
        
        if (max > sim) continue;
        if (max < sim){
           max = sim; 
           sim_s.resize(0);
        }   
        sim_s.push_back(s);
    }
    cout << "The query sequence is:" << '\n';
    cout << q << '\n';
    cout << "The most similar sequences are:" << '\n';

    F(i, sim_s.size()){
        cout << sim_s[i] << "\n";
        cout << "The similarity score is: " << max << '\n';
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
