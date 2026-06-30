#include <bits/stdc++.h>
using namespace std;
vector<bool> visited(1001, 0);
vector<int> adj[1001];
vector<int> best_path;
void print_answer() {
    int size = best_path.size();
    for (int i = 0; i < size - 1; i++) {
        cout << best_path[i] + 1 << " ";
    }
    cout << best_path[size - 1] + 1 << "\n";
}

// Always finds the path that travels through the smallest nodes first
void dfs(int start, int end) {
    if (visited[start] || visited[end]) return; // stops after finding the first path
    if (start == end) {
        best_path.push_back(start);
        visited[start] = true;
        print_answer(); 
        return;
    }
    visited[start] = true;
    best_path.push_back(start); 
    for (int i = 0; i < adj[start].size(); i++) { //visits nodes from smallest to largest
        dfs(adj[start][i], end); 
    }
    best_path.pop_back();

}

void solve() {
    // Your code here
    int N, M, start, end;
    cin >> N >> M >> start >> end;

    best_path.clear();
    for (int i = 0; i < N; i++) {
        adj[i].clear();
    }
    fill(visited.begin(), visited.end() + 1, false);

    pair<int, int> edge;
    for (int i = 0; i < M; i++) {
        cin >> edge.first >> edge.second;
        adj[edge.first - 1].push_back(edge.second - 1);
        adj[edge.second - 1].push_back(edge.first - 1);
    }
    for (int i = 0; i < N; i++) { 
        sort(adj[i].begin(), adj[i].end()); // orders the vertices from smallest to largest
    }

    dfs(start - 1, end - 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
