#include <bits/stdc++.h>

using namespace std;

#define long long int;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return (a / GCD(a, b)) * b;
}

int Solve(int m, int n, int x, int y) {
    int lcm = LCM(x, y);
    return (n / lcm) - (m / lcm);
}

int main() {
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    int m, n, x, y;
    cin >> m >> n >> x >> y;
    cout << Solve(m, n, x, y);
    return 0;
}
