#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)



void solve() {
   int n, t1, t2;
   cin >> n;
   stack<int> d1, d2;
   int next = 1;
   F(i, n) {
        int t;
        cin >> t;
        if (t == next) {
            cout << 1 << "\n";
            cout << -1 << "\n";
            next++;
            continue;
        }
        if (d1.empty()) {
            cout << 1 << "\n";
            d1.push(t);
            continue;
        }
        t1 = d1.top();
        if (t < t1) {
            cout << 1 << "\n";
            d1.push(t);
            continue;
        }
        if (d2.empty()) {
            cout << 2 << "\n";
            d2.push(t);
            continue;
        }
        t2 = d2.top();
        if (t < t2) {
            cout << 2 << "\n";
            d2.push(t);
            continue;
        }
        if (t - t2 > t - t1) { // numeros menores em d2
            while (t > t1) {
                cout << 12 << "\n";
                d2.push(t1);
                d1.pop();
                if (d1.empty()) {
                    cout << 1 << "\n";
                    d1.push(t);
                    break;
                }
                t1 = d1.top();
            }
            if (t < t1) {
                cout << 1 << "\n";
                d1.push(t);
            }
            t2 = d2.top();
            t1 = d1.top();
            while (t2 < t1) {
                cout << 21 << "\n";
                d1.push(t2);
                d2.pop();
                if (d2.empty()) break;
                t1 = t2;
                t2 = d2.top();
            }
        } else {
            while (t > t2) {
                cout << 21 << "\n";
                d1.push(t2);
                d2.pop();
                if (d2.empty()) {
                    cout << 2 << "\n";
                    d2.push(t);
                    break;
                }
                t2 = d2.top();
            }
            if (t < t2) {
                cout << 2 << "\n";
                d2.push(t);
            }
            t2 = d2.top();
            t1 = d1.top();
            while (t1 < t2) {
                cout << 12 << "\n";
                d2.push(t1);
                d1.pop();
                if (d1.empty()) break;
                t2 = t1;
                t1 = d1.top();
            }
        }
   }
   while (!d1.empty() || !d2.empty()){
        if (d1.empty()) {
            cout << -2 << "\n";
            d2.pop();
            continue;
        } else if (d2.empty()) {
            cout << -1 << "\n";
            d1.pop();
            continue;
        }
        t1 = d1.top();
        if (t1 == next) {
            cout << -1 << "\n";
            d1.pop();
        } else {
            cout << -2 << "\n";
            d2.pop();
        }
        next++;
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
