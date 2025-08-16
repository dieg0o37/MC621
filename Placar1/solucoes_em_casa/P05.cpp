#include <iostream>
#include <vector>

using namespace std;

/*


*/
int n;
string input;
void get_input(){
    cin >> n;
    cin >> input;
}
void solve() {
    get_input();
    vector<int> alice;
    vector<int> bob;
    int n_a = 0, n_b = 0;
    for (int i = 0; i < n; i++) {
        if (input[i] == 'A') {
            alice.push_back(i + 1);
            n_a++;
        } else {
            bob.push_back(i + 1);
            n_b++;
        }
    }
    if (n == 2) {
        if (input[0] == 'A') {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
        return;
    }

    if (n_a == n - 1) {
        cout << "Alice" << endl;
        return;
    }

    if (n_b == n - 1) {
        cout << "Bob" << endl;
        return;
    }

    if (alice[n_a - 1] == n && (alice[n_a - 2] == n -1 || alice[0] == 1)) {
        cout << "Alice" << endl;
        return;
    }

    if (bob[n_b - 1] == n && n_b > 1) {
        cout << "Bob" << endl;
        return;
    }

    if (bob[0] == 1 && bob[n_b - 1] == n - 1) {
        cout << "Bob" << endl;
        return;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}