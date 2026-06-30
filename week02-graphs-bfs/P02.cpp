#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)

#define MAX 200
typedef struct node {
    int word_size;
    string word;
    vector<node*> adj;
    int i;
} node;

queue<node*> q;
bool visited[MAX];
int distance_c[MAX];


int bfs(node* start, string end) {
    visited[start->i] = true;
    q.push(start);
    distance_c[start->i] = 0;
    while (!q.empty()) {
        node* cur = q.front();
        //cerr << "current node: " << cur->word << "\n";
        q.pop();
        for (node* s: cur->adj){
            if (visited[s->i]) continue;
            //cerr << cur->word << " visitando: " <<  s->word << "\n";
            visited[s->i] = true;
            distance_c[s->i] = distance_c[cur->i] + 1;
            if (s->word == end) {
                while (!q.empty()) q.pop();
                return distance_c[s->i];
            }
            q.push(s);
        }
    }
    return -1;
}


int count_difs(string s1, string s2, int n) {
    int difs = 0;
    F(i, n) {
        if (s1[i] != s2[i])  difs++;
    }
    return difs;
}

void solve() {
    int i = 0;
    node* word;
    vector<node*> s[10];
    while (true) {

        node* word = new node;
        cin >> word->word;
        if (word->word == "*")
            break;
        word->i = i;
        i++;
        word->word_size = word->word.size();
        if (!s[word->word_size - 1].empty())
            F(j, s[word->word_size - 1].size()) {
                if (count_difs(word->word, s[word->word_size - 1][j]->word, word->word_size) == 1){
                    word->adj.push_back(s[word->word_size - 1][j]);
                    s[word->word_size - 1][j]->adj.push_back(word);
                }
            }
        (s[word->word_size - 1]).push_back(word);
    } 
    cin.ignore();
    while (true) {
        string test_line;
        getline(cin, test_line, '\n');
        if (test_line.empty()) return;

        fill(visited, visited + MAX, false);

        stringstream ss(test_line);
        string params[2];
        int i = 0;
        while (ss >> params[i++]);
        string start = params[0];


        int size = start.size();
        for (auto u: s[size - 1]) {
            if (u->word == start) {
                cout << u->word << " " << params[1] << " " << bfs(u, params[1]) << "\n";
                break;
            }
        }
    }
   

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        solve();
        cout << (t == 0 ? "" : "\n");
    }
        

    return 0;
}
