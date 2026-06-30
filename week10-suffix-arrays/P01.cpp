#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)

struct Suffix {
    int index; 
    int rank[2]; 
};

int compare_suf(const Suffix& a, const Suffix& b) {
    if (a.rank[0] == b.rank[0]) {
        return a.rank[1] < b.rank[1];
    }
    return a.rank[0] < b.rank[0];
}
vector<int> buildSuffixArray(const string& txt) {
    int n = txt.size();
    vector<Suffix> s(n);
    for (int i = 0; i < n; i++) {
        s[i].index = i;
        s[i].rank[0] = txt[i];
        s[i].rank[1] = (i + 1 < n) ? txt[i + 1] : -1;
    }
    sort(s.begin(), s.end(), compare_suf); // sorting pra k = 2
    vector<int> newRank(n);

    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prev_rank = s[0].rank[0];
        s[0].rank[0] = rank;
        newRank[s[0].index] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i].rank[0] == prev_rank && s[i].rank[1] == s[i-1].rank[1]) {
                prev_rank = s[i].rank[0];
                s[i].rank[0] = rank;
            } else {
                prev_rank = s[i].rank[0];
                s[i].rank[0] = ++rank;
            }
            newRank[s[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int next_index = s[i].index + k / 2;
            s[i].rank[1] = (next_index < n) ? s[newRank[next_index]].rank[0] : -1;
        }

        sort(s.begin(), s.end(), compare_suf);
    }

    vector<int> suffixArr(n);
    for (int i = 0; i < n; i++) {
        suffixArr[i] = s[i].index;
    }

    return suffixArr;
}


void solve() {
    string S;
    cin >> S;
    auto v = buildSuffixArray(S);
    int n = S.size();
    F(i, n){
        cout << v[i] << (i == n -1 ? "\n" : " ");
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
