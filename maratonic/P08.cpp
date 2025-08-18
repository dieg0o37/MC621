#include <bits/stdc++.h>
using namespace std;
double answer = 0;
double calc_rec(int n) {
    if (n == 1) {
        return 1.0;
    }
    if (n == 2) {
        return 2.0;
    }
    if (n %2 ==0) {
        return 1+(calc_rec(n/2));
    }
    int maior_grupo = ceil((double)n/2.0);
    int menor_grupo = floor((double)n/2.0);
    cerr << menor_grupo << endl;
    cerr << maior_grupo << endl;

    return ((maior_grupo*(calc_rec(maior_grupo) + 1))/n + (menor_grupo* (calc_rec(menor_grupo) + 1))/n);
}

void solve() {
    // Your code here
    int N, i = 0; 
    cin >> N;
    vector<string> peixes(N);
    for (i = 0; i < N; ++i) {
        cin >> peixes[i];
    }
    cout << calc_rec(N) << "\n";
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the following lines to read from a file instead of stdin
    /*
    #ifndef ONLINE_JUDGE
        freopen("P05.in", "r", stdin);
    #endif
    */
    solve();

    return 0;
}
