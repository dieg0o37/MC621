#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;


bool comp(pr p1, pr p2) {
    return (p1.first - p1.second > p2.first - p2.second);
}
vector<ll> best_K(200000, LONG_MIN);
#define max_suf(p1, p2) max(p1.second, p2.second)
pr build(int low, int high, vector<pr> inp_vals) {
    if (low == high) {
        best_K[0] = max(inp_vals[low].first - inp_vals[low].second, best_K[0]);
        return inp_vals[low];
    }
    int mid = (low + high)/2;
    pr lf_pair = build(low, mid, inp_vals);
    pr rt_pair = build(mid + 1, high, inp_vals);
    pr cur_pair;
    cur_pair.first = lf_pair.first + rt_pair.first;
    cur_pair.second = max(lf_pair.second, rt_pair.second);
    best_K[high - low] = max(best_K[high - low], cur_pair.first - cur_pair.second);
    return cur_pair;
    
}
void solve() {
    // Your code here
    int N;
    cin >> N;
    vector<pr> inp_vals(N);
    for (int i = 0; i < N; i++) {
        cin >> inp_vals[i].first >> inp_vals[i].second;
    }
    sort(inp_vals.begin(),inp_vals.end(), comp);
    for (int i = 0; i < N; i++) {
        cerr << inp_vals[i].first << " " << inp_vals[i].second << endl;
    }
    build(0, N - 1, inp_vals);
    for (int i = 0; i < N; i++) {
        cout << best_K[i] << endl;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the following lines to read from a file instead of stdin
    /*
    #ifndef ONLINE_JUDGE
        freopen("P10.in", "r", stdin);
    #endif
    */
    solve();

    return 0;
}
