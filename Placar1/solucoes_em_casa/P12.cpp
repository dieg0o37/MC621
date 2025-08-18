#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t != 0) {
        int n;
        int target;
        cin >> n >> target;
        int sum = 0;
        int curr_n;
        for (int i = 0; i < n; i++) {
            cin >> curr_n;
            sum += curr_n;
        }
        if (target*n == sum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        t--;
    }
    return 0;
}