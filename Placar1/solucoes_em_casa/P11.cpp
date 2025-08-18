#include <iostream>
#include <vector>
#include <string>
using namespace std;

void insert(int x);
void remove(int x);
int get_max_xor(int x);

int nodes_count = 0;

struct trie_node {
    int child[2];
    int count;
};
vector<trie_node> trie;



void newNode() {
    trie.emplace_back();
    trie[nodes_count].child[0] = -1; // -1 indicates no child
    trie[nodes_count].child[1] = -1;
    trie[nodes_count].count = 0;
    nodes_count++;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    newNode(); // root
    insert(0); // starts with 0
    
    int q, x;
    char op;
    cin >> q;
    while (q--) {
        cin >> op >> x;
        if (op == '+') {
            insert(x);
        } else if (op == '-') {
            remove(x);
        } else {
            cout << get_max_xor(x) << endl;
        }
    }

}
#define BITS 30 // fits 10^9
void insert(int x) {
    int curr_node = 0; // starting at root
    for (int i = BITS - 1; i >= 0; i--) {
        int curr_bit = (x >> i) & 1;
        if (trie[curr_node].child[curr_bit] == -1) {
            trie[curr_node].child[curr_bit] = nodes_count;
            newNode();
        }
        curr_node = trie[curr_node].child[curr_bit]; // node I just added
        trie[curr_node].count++;
    }
}

void remove(int x) {
    int curr_node = 0; // also starts at root
    for (int i = BITS - 1; i >= 0; i--) {
        int curr_bit = (x >> i) & 1;
        curr_node = trie[curr_node].child[curr_bit];
        trie[curr_node].count--; // leaves the mem alocated and count = 0
    }
}

int get_max_xor(int x) {
    int curr_node = 0;
    int max_xor = 0;
    for (int i = BITS - 1; i >= 0; i--) {
        int curr_bit = (x >> i) & 1;
        int want =  1 - curr_bit;

        if (trie[curr_node].child[want] != -1 && 
            trie[trie[curr_node].child[want]].count > 0) {
            curr_node = trie[curr_node].child[want];
            max_xor |= (1 << i); // se tiver oposto max_xor_aumenta
        } else {
            curr_node = trie[curr_node].child[curr_bit];
        }
    }
    return max_xor;

}