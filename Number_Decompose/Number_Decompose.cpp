#include <bits/stdc++.h>

using namespace std;

///Thuật toán sàng nguyên tố độ phức tạp O(n)
///Reference: https://cp-algorithms.com/algebra/prime-sieve-linear.html
const int N = 35000000;
//cal: mảng tạm dùng trong hàm sievePrime
//isPrime: mảng kiểm tra tính nguyên tố, giá trị = 0 nếu là hợp số, = 1 nếu nguyên tố
int cal[N + 2], isPrime[N + 2];
vector<int> prime; //Mảng lưu các số nguyên tố tìm được
void sievePrime() {
    for (int i = 2; i <= N; ++i) {
        if (cal[i] == 0) {
            cal[i] = i;
            prime.emplace_back(i);
            isPrime[i] = 1;
        }
        for (int j = 0; j < prime.size() && prime[j] <= cal[i] && i * prime[j] <= N; ++j) {
            cal[i * prime[j]] = prime[j];
        }
    }
}

void solve(int n) {
    /** Chia 2 trường hợp để giải, n lẻ và chẵn
      * Giả thuyết Goldback: Mọi số nguyên lẻ đều có thể phân tích thành
      * tổng của 2 số nguyên tố(đã được kiểm chứng đến 4*10^18).
      *
      * Với n lẻ, ta brute force để giải.
      *
      * Với n chẵn, tổng phải luôn tồn tại 2, nên phần còn lại là n - 2 ta dùng
      * cách brute force để tìm.
      */

    if (n % 2 != 0) {
        int firstNum = 0, sum = 0;
        for (int i = n - 1; i >= 2; --i) {
            if (isPrime[i]) {
                firstNum = i;
                sum = n - i;
                for (int i = 0; i < prime.size() && prime[i] <= n / 2; ++i) {
                    const int temp = sum - prime[i];
                    if (temp > 0 && isPrime[temp] && temp != prime[i]) {
                        cout << firstNum << " " << prime[i] << " " << sum - prime[i]; //Comment this line when testing
                        return;
                    }
                }
            }

        }

    } else {
        const int firstNum = 2, sum = n - 2;
        for (int i = 0; i < prime.size() && prime[i] <= n / 2; ++i) {
            const int temp = sum - prime[i];
            if (isPrime[temp] && temp != prime[i]) {
                cout << firstNum << " " << prime[i] << " " << sum - prime[i]; //Comment this line when testing
                return;
            }
        }
    }
}

int main()
{
    freopen("PRIME.INP", "r", stdin);
    freopen("PRIME.OUT", "w", stdout);
    cin.tie(0);

    int n;
    cin >> n;

    sievePrime();

    solve(n);

//    TESTING SECTION
//    for (int i = 1; i <= 100000; ++i) {
//        const clock_t begin_time = clock();
//        solve(i);
//        auto time_lapse = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
//        //cout << " | Time: " << time_lapse << endl;
//        if (time_lapse > 1) {
//            cout << "Break at " << i;
//            break;
//        }
//    }

    return 0;
}
