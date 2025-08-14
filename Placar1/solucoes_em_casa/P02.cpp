#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    map<int, int> dict;
    cin >> n;
    vector<int> N_vec(n);
    for (int i = 0; i < n; i++) {
        cin >> N_vec[i];
    }
    long long pares = 0;

    for (int i = 0; i < n; i++) {
        if (dict.count(i + 1 - N_vec[i])) {
            pares += dict[i + 1 - N_vec[i]]; // j
        }
        dict[i + 1 + N_vec[i]]++; // i 
        //apenas futuros j podem ver o i => j > i
    }
    cout << pares << endl;
    return 0;
}