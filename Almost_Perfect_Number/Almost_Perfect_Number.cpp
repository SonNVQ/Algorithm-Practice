#include <bits/stdc++.h>

using namespace std;

int64_t sumOfDivisors(int n) {
    const int BOUND = (int)sqrt(n);
    int64_t sum = 0;
    for (int i = 1; i <= BOUND; ++i)
        if (n % i == 0)
            sum += i + n / i;
    if (BOUND * BOUND == n)
        sum -= BOUND;
    return sum;
}

void solve() {
    int K, N;
    cin >> K;
    while (K) {
        cin >> N;
        if (2 * N <= sumOfDivisors(N))
            cout << "1" << endl;
        else
            cout << "0" << endl;
        --K;
    }
}

int main()
{
//    freopen("GHH.INP", "r", stdin); //Comment out when testing
//    freopen("GHH.OUP", "w", stdout); //Comment out when testing
//
//    solve(); //Comment out when generate test input

//  TESTING SECTION
    freopen("GHH.INP", "w", stdout);
    random_device rd;	// only used once to initialize (seed) engine
    mt19937_64 rng(rd());	// random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(1, 1000000000);
    int k = 10000;
    cout << k << endl;
    for (int i = 1; i <= k; ++i) {
        cout << uni(rng) << endl;
    }

    return 0;
}
