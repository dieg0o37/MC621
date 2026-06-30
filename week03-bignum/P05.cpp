#include <bits/stdc++.h>
// Using std namespace for clarity in this self-contained file
using namespace std;

// Using a constant for max digits is good practice
const int MAX_DIGITS = 5000;


enum Sign {
    PLUS = 1,
    MINUS = -1
};

/*
TODO from original file:
SOMA - FIXED
SUBTRACAO - FIXED
MULTIPLICACAO - FIXED
DIVISAO - FIXED
XOR - Not implemented
CONVERSAO DE BASE - Added string/ll conversions
MODULO - Not implemented
*/

struct bignum {
    // --- Data Members ---
    // Using vector<char> for safety and proper memory management.
    // Each char stores a single digit (0-9).
    vector<char> num;
    int signbit;
    int lastdigit; // Index of the most significant digit

    // --- Constructor ---
    bignum() {
        num.assign(MAX_DIGITS, 0); // Allocate and zero-out the vector
        signbit = PLUS;
        lastdigit = 0;
    }

    // --- Utility Functions ---
    // (Moved from global scope into the struct for better organization)

    /// @brief Trims leading zeros (e.g., 00123 -> 123)
    void zero_justify() {
        while (lastdigit > 0 && num[lastdigit] == 0) {
            lastdigit--;
        }
        // A number that is just 0 should have PLUS sign
        if (lastdigit == 0 && num[0] == 0) {
            signbit = PLUS;
        }
    }
};

// --- Forward Declarations ---
void big_subtract(bignum* n1, bignum* n2, bignum* result);
int big_compare(bignum* n1, bignum* n2);

// --- Conversion Functions ---

/// @brief Converts a long long to a bignum
void ll_to_bignum(long long s, bignum *n) {
    if (s == 0) {
        n->lastdigit = 0;
        n->num[0] = 0;
        n->signbit = PLUS;
        return;
    }

    n->signbit = (s >= 0) ? PLUS : MINUS;
    
    // Use fill on the vector directly
    fill(n->num.begin(), n->num.end(), 0);
    n->lastdigit = -1;

    long long t = abs(s);
    while (t > 0) {
        n->lastdigit++;
        n->num[n->lastdigit] = t % 10;
        t /= 10;
    }
}

/// @brief Converts a string to a bignum
void string_to_bignum(const string& s, bignum* n) {
    if (s.empty() || (s.length() == 1 && s[0] == '0')) {
        ll_to_bignum(0, n);
        return;
    }

    int start = 0;
    if (s[0] == '-') {
        n->signbit = MINUS;
        start = 1;
    } else if (s[0] == '+') {
        n->signbit = PLUS;
        start = 1;
    } else {
        n->signbit = PLUS;
    }

    fill(n->num.begin(), n->num.end(), 0);
    n->lastdigit = -1;

    for (int i = s.length() - 1; i >= start; i--) {
        n->lastdigit++;
        n->num[n->lastdigit] = s[i] - '0';
    }
    n->zero_justify();
}


/// @brief Converts a bignum to a string for printing
string bignum_to_string(bignum* n) {
    if (n->lastdigit == 0 && n->num[0] == 0) {
        return "0";
    }

    string s = "";
    if (n->signbit == MINUS) {
        s += "-";
    }
    for (int i = n->lastdigit; i >= 0; i--) {
        s += to_string(n->num[i]);
    }
    return s;
}

// Overload << operator for easy printing
ostream& operator<<(ostream& os, bignum* n) {
    os << bignum_to_string(n);
    return os;
}


// --- Core Logic Functions ---

/// @return 1 if n1 > n2, -1 if n2 > n1, and 0 if n1 == n2
int big_compare(bignum* n1, bignum* n2) {
    if (n1->signbit == PLUS && n2->signbit == MINUS) return 1;
    if (n1->signbit == MINUS && n2->signbit == PLUS) return -1;

    // If signs are the same, comparison depends on the sign
    int sign_factor = (n1->signbit == PLUS) ? 1 : -1;

    if (n1->lastdigit > n2->lastdigit) return 1 * sign_factor;
    if (n2->lastdigit > n1->lastdigit) return -1 * sign_factor;

    for (int i = n1->lastdigit; i >= 0; i--) {
        if (n1->num[i] > n2->num[i]) return 1 * sign_factor;
        if (n1->num[i] < n2->num[i]) return -1 * sign_factor;
    }

    return 0; // Numbers are equal
}

void solve() {
    string a, b;
    bignum zero, resto, n1, n2, temp, one;
    ll_to_bignum(0, &zero);
    ll_to_bignum(1, &one);
    cin >> a >> b;
    string_to_bignum(b, &n1);
    string_to_bignum(a, &n2);
    int comp = big_compare(&n1, &n2);
    if (comp == 0) {
        cout << &n1 << "\n";
        return;
    }
    if (comp == 1) {
        cout << 1 << "\n";
        return;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
