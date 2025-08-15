#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long b[2*n];
    for (int i = 0; i < 2*n; ++i) {
        cin >> b[i];
    }
    sort(b, b + 2*n);
    long long a[2*n + 1];
    a[0] = b[2*n - 1];
    a[1] = a[0];
    int odd_indexes = 2, even_indexes = 3; 
    int i;
    for (i = 0; i < n - 1; ++i) {
        a[even_indexes] = b[i];
        a[1] -= b[i];
        even_indexes += 2;
    }
    for (; i < 2*n - 1; ++i) {
        a[odd_indexes] = b[i];
        a[1] += b[i];
        odd_indexes += 2;
    }
     for (int i = 0; i < 2*n; ++i) {
        cout << a[i] << " ";
    }
    cout << a[2*n] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}