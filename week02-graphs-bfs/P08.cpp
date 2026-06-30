#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> T(N, 0);
    for (int i = N - 1; i >= 0; i--) { 
        T[0] = (i %2 ==0 ? T[0] + A[i] : T[0] - A[i]);
    }
    for (int i = 1; i < N; i++) {  
        T[i] = (2*A[i - 1] - T[i - 1]);
    }
    T[N - 1] = 2*A[N - 1] - T[0];
    for (int i = 0; i < N; i++) { 
        cout << T[i] << (i == N - 1? "\n" : " ");
    } 
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    solve();

    return 0;
}
