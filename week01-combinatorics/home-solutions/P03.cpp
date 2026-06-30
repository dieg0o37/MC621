#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    
    map<int, int> dict;

    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    int numeros_distintos = 0;
    for (int i = 0; i < k; ++i) {
        if (!dict.count(vec[i])) {
            numeros_distintos++; 
        }
        dict[vec[i]]++;
    }
    cout << numeros_distintos;
    int numero_removido;
    int numero_adicionado;
    for (int i = k; i < n; ++i) {
        numero_removido = vec[i - k];
        numero_adicionado = vec[i];
        dict[numero_removido]--;
        dict[numero_adicionado]++;
        if (dict[numero_removido] == 0){
            numeros_distintos--;
            dict.erase(numero_removido);
        }
        if (dict[numero_adicionado] == 1) {
            numeros_distintos++;
        }
        cout << " " << numeros_distintos;
        
    }
    cout << endl;
    return 0;
}