#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 1; i <= n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
 
void TPS(const std::string& s, std::vector<std::vector<int>>& count) {
    int n = s.length();
    std::vector<std::vector<bool>> is_palindrome(n, std::vector<bool>(n, false));

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            
            if (len == 1) {
                is_palindrome[i][j] = true;
            } else if (len == 2) {
                is_palindrome[i][j] = (s[i] == s[j]);
            } else {
                is_palindrome[i][j] = (s[i] == s[j] && is_palindrome[i + 1][j - 1]);
            }

            if (len == 1) {
                count[i][j] = 1;
            } else {
                count[i][j] = count[i + 1][j] + count[i][j - 1] - count[i + 1][j - 1];
                if (is_palindrome[i][j]) {
                    count[i][j]++;
                }
            }
        }
    }
}
void solve() {
    string s;
    cin >> s;
    int t;
    int r, l;
    int n= s.size();
    std::vector<std::vector<int>> count(n, vector<int>(n, 0));  
    TPS(s, count); 
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << count[l - 1][r - 1] << "\n";
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
