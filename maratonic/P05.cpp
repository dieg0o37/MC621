#include <bits/stdc++.h>
using namespace std;

void print_sol(int t, vector<string> ans) {
    cout << t << "\n";
    for (auto u: ans) {
        cout << u << "\n";
    }
}

void solve() {
    // Your code here
    string init;
    cin >> init;
    vector<string> ans;
    ans.push_back(init);
    int size = init.size();
    int n_T = 0, t = 1;
    for (auto u: init) {
        if (u == 'T') n_T++;
    }
    if (n_T == size) {
        print_sol(t, ans);
        return;
    }
    while (n_T != size) {
        string new_state = ans[t - 1];
        for (int i = 0; i < size; i++) {
            if (ans[t - 1][i] == 'T') {
                new_state[i] = 'H';
                n_T--; 
            }
            else {
                new_state[i] = 'T';
                n_T++;
                break;
            }
        }
        ans.push_back(new_state);
        t++;
    };
    print_sol(t, ans);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    solve();

    return 0;
}
