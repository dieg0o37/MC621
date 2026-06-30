# MC621 — Competitive Programming Challenges II

Solutions and reusable algorithm implementations written for **MC621 (Desafios de Programação II)** at **UNICAMP**, a competitive-programming course taught by Prof. Fábio Luiz Usberti. Each week the class ran a timed contest targeting a specific algorithmic theme; this repository collects the code I wrote during those contests, plus extra practice from the [CSES Problem Set](https://cses.fi/problemset/).

> **Languages:** C++17 (primary, ~95 files) and Python (early weeks)
> **Scope:** 13 weekly contests, including the internal **ICPC team-qualifier** (week 11)

---

## Key skills demonstrated

- **Algorithm design under time pressure** — turning problem statements into correct, performant solutions within a contest window.
- **Implementing data structures and algorithms from scratch** instead of relying on black-box libraries (big-integer arithmetic, KMP, suffix arrays, sieves).
- **Complexity-aware coding** — choosing the right paradigm (greedy vs. DP vs. meet-in-the-middle) to fit the input bounds and time limits.
- **Idiomatic modern C++** — STL containers, `std::complex` as a 2D geometry primitive, operator overloading, and fast I/O.

## Week-by-week themes

| Week | Theme | Representative techniques |
|------|-------|---------------------------|
| [01](week01-combinatorics/) | Combinatorics & ad-hoc | inclusion–exclusion, sliding window, hashing (*Python*) |
| [02](week02-graphs-bfs/) | Graphs | BFS shortest paths, graph modeling (word ladder) |
| [03](week03-bignum/) | Big-number arithmetic | from-scratch arbitrary-precision integer library |
| [04](week04-bitmask-meet-in-the-middle/) | Bitmasks | meet-in-the-middle subset sums, binomial coefficients |
| [05](week05-number-theory-sieve/) | Number theory | Sieve of Eratosthenes, divisor counting |
| [06](week06-number-theory-diophantine/) | Number theory | extended Euclid, linear Diophantine equations |
| [07](week07-modular-arithmetic/) | Modular arithmetic | fast (binary) exponentiation under a modulus |
| [08](week08-string-matching/) | String matching | KMP prefix function, Z-function |
| [09](week09-dynamic-programming/) | Dynamic programming | sequence alignment, classic DP tables |
| [10](week10-suffix-arrays/) | Strings | suffix array construction, sorting |
| [11](week11-icpc-qualifier/) | **ICPC team qualifier** | mixed-topic internal UNICAMP selection contest |
| [12](week12-geometry-segments/) | Computational geometry | cross product, segment intersection |
| [13](week13-geometry-lattice/) | Computational geometry | polygon area (shoelace), lattice points (Pick) |

> Some weeks mix several topics; the labels reflect the dominant focus.

## Highlighted implementations

| Area | What I built | Where |
|------|--------------|-------|
| **Big-number library** | Arbitrary-precision signed integers: add/subtract with sign logic, grade-school multiplication, long division, comparison, and digit shifting — manual carry/borrow propagation. | [`week03-bignum/bignumlib.cpp`](week03-bignum/bignumlib.cpp) |
| **Computational geometry** | 2D points modeled as `std::complex`; orientation/cross-product tests, polygon area via the shoelace formula, point-in-polygon, and lattice-point counting (Pick's theorem). | [`cses_problems/geometry/`](cses_problems/geometry/) |
| **String algorithms** | KMP prefix-function (LPS) matching, Z-function, and suffix-array construction. | [`week08-string-matching/`](week08-string-matching/), [`week10-suffix-arrays/`](week10-suffix-arrays/) |
| **Dynamic programming** | Coin-change minimization, dice-combination counting with memoization, and sequence alignment (edit-distance / LCS style). | [`cses_problems/Dynamic_prog/`](cses_problems/Dynamic_prog/), [`week09-dynamic-programming/tema.cpp`](week09-dynamic-programming/tema.cpp) |

## Repository structure

```
mc621/
├── week01 … week13/     # one weekly contest each (P01.cpp, P02.cpp, …)
├── cses_problems/       # extra CSES Problem Set practice
│   ├── geometry/        # cross product, polygon area, point-in-polygon, lattice points
│   └── Dynamic_prog/    # coin change, dice combinations
└── lis.py               # longest increasing subsequence helper
```

Each `weekNN-*/` folder is a self-contained contest; problems are named `P01`–`P12`. Most solutions are C++; the earliest week is in Python. Compiled binaries are git-ignored.

## Building & running

```bash
g++ -std=c++17 -O2 week03-bignum/P01.cpp -o solution
./solution < input.txt
```
