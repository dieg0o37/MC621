#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9 + 7;

void solve() {
    // Your code here
    ll n, m, k;
    cin >> n >> m >> k;
    pair<ll, ll> edge;
    vector<vector<ll>> adj;
    vector<vector<ll>> adj_sq;
    vector<vector<ll>> adj_t;
    vector<vector<ll>> adj_0;
    adj.resize(n);
    adj_sq.resize(n);
    for (ll i = 0; i < n; i++) {
        adj[i].resize(n);
        fill(adj[i].begin(), adj[i].end(), 0);
    }
    adj_sq = adj;
    adj_0 = adj;
    
    adj_t = adj;
    for (ll i = 0; i < m; i++) {
        cin >> edge.first >> edge.second;
        adj[edge.first - 1][edge.second - 1] = 1;
    }
   for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll r = 0; r < n; r++) {
                adj_sq[i][j] = (adj_sq[i][j] + (adj[i][r]*adj[r][j])%MOD)%MOD;
            }
        }
    } 
    if (k == 1) {
        cout << adj[0][n - 1] << "\n";
        return;
    } 
    if (k == 2) {
        cout << adj_sq[0][n - 1] << "\n";
        return;
    }
    k -= 2;
    while (k--) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                for (ll r = 0; r < n; r++) {
                    adj_t[i][j] = (adj_t[i][j] + (adj[i][r]*adj_sq[r][j])%MOD)%MOD;
                }
            }
        }
        adj_sq = adj_t;
        adj_t = adj_0;
    }
    cout << adj_sq[0][n - 1] << "\n";
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
