#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)



string best_path = "";
string cur_path = "";
string graph[50];
vector<bool> visited(50, false);
bool stop = false;
void dfs(int start, int end, char rua, int max_pos) {
    if (visited[start] || stop) return; 
    if (start == end) {
        cur_path += rua;
        int n = cur_path.size();
        if (n == max_pos){
            stop = true;
        }
        int m = best_path.size();
        if (n > m) {
            F(i, n/2){
                if (cur_path[i] != cur_path[n - 1 - i]) return;
            }
            best_path = cur_path;
        }
        return;
    }
    visited[start] = true;
    if (start != 0)
        cur_path += rua; 
    for (int i = start + 1; i < graph[start].size(); i++) {
        dfs(i, end, graph[start][i], max_pos);
        max_pos--;
    }
    if (start != 0)
        cur_path.pop_back();
    visited[start] = false;

}

void solve() {
    best_path = ""; 
    cur_path = "";
    fill(graph, graph + 50, "");
    fill(visited.begin(), visited.end(), false);
    stop = false;
    int N;
    cin >> N;
    F(i, N) {
        cin >> graph[i];
    }
    dfs(0, N-1, '*', N-1);
    if (best_path == "") cout << "NO PALINDROMIC PATH" << "\n";
    else cout << best_path << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
