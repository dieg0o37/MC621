#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i, n) for(int i = 0; i < n; i++)
#define Fr(i, n) for(int i = n; i >=0; i--)



void solve() {
    ll n;
    cin >> n;
    vector<ll> vec(n);
    set<ll> lista;


    F(i, n) {
        cin >> vec[i];
    }

    F(i, n) {
        if (vec[i] == -1) {
            if (i > 0 && vec[i - 1] != -1)  {
                lista.insert(vec[i - 1]);
            }

            if (i < n - 1 && vec[i + 1] != -1) {
                lista.insert(vec[i + 1]);
            }
        }
    }

    ll m = 0;
    if (lista.empty()) {
        ll k = 42;
        cout << m << " " << k << "\n";
        return;
    }

    ll media = (*lista.rbegin() + *lista.begin())/2;
    m = *lista.rbegin() - media;
    
    F(i, vec.size() - 1) {
        if (vec[i] != -1 && vec[i + 1] != -1) {
            m = max(m, abs(vec[i] - vec[i + 1]));
        }
    }

    cout << m << " " << media << "\n";
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
