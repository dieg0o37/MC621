#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)
#define MAX 1000LL
vector<ll> adj[MAX];
vector<bool> visited(MAX, false);
vector<bool> removido(MAX, false);
void dfs(int start, int end) {
    if (visited[start] || visited[end]) return;
    if (start == end) {
        visited[start] = true;
        removido[start] = true;
        return;
    }
    visited[start] = true;
    for (int i = 0; i < adj[start].size(); i++) { 
        if (!removido[i])
            dfs(adj[start][i], end); 
    }
}
void solve() {
    ll n, m;
    cin >> n >> m;
    pair<ll, ll> edges[m];
    F(i, m) {
        cin >> edges[i].first >> edges[i].second;
        adj[edges[i].first - 1].push_back(edges[i].second - 1);
    }
    F(i, n) {
        sort(begin(adj[i]), end(adj[i]));
    }
    for(ll i = 0; i <= m; i++) {
        ll h = 0; 
        if (i == 0) {
            F(k, n) {
                F(j, n) {
                    dfs(j, k);
                    if (visited[k]) h++;
                }
            }
        }
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
