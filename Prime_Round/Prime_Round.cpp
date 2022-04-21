#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
int N = 0; //N = 2*n
int total = 0; //Total of solutions
int a[MAX], check[MAX]; //A: store result, check: use to choose number in backtracking
bool isEnough = false; //to exit the backtracking process
string result = ""; //store result string to print after we have total
int isPrime[2*MAX]; //0: prime; 1: composite


void sieve() {
    const int BOUND = (int)sqrt(2*MAX);
    for (int i = 2; i <= BOUND; ++i) {
        if (isPrime[i] == 0) {
            for (int j = 2*i; j <= 2*MAX; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}

void backtracking(int k) {
    if (k > N) {
        //If sum of the last and the first is not a prime
        if (isPrime[a[k-1] + 1] == 1)
            return;
        //If satisfied
        if (++total > 10000) {
            --total;
            isEnough = true;
            return;
        } //break when reach to 10000
        for (int i = 1; i <= N; ++i)
            result += to_string(a[i]) + " ";
        result += "\n";
        return;
    }
    for (int i = 2; i <= N; ++i) {
        if (check[i] == 0) {
            check[i] = 1;
            a[k] = i;
            if (isPrime[a[k] + a[k-1]] == 0)
                backtracking(k + 1);
            if (isEnough)
                return;
            check[i] = 0;
        }
    }
}

int main()
{
    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);

    int n;
    cin >> n;

    isPrime[0] = isPrime[1] = 1;
    sieve();

    a[1] = 1;
    N = 2*n;
    backtracking(2);

    cout << total << "\n" << result;

    return 0;
}
