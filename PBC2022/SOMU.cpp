#include <iostream>

using namespace std;

int Solve(int N, int K) {
    int result = 0, temp = K;
    while (temp <= N) {
        result += N / temp;
        temp *= K;
    }
    return result;
}

int main() {
    freopen("SOMU.INP", "r", stdin);
    freopen("SOMU.OUT", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << Solve(N, K) << endl;
    }
    return 0;
}
