#include <bits/stdc++.h>

using namespace std;

//Hàm kiểm tra tính nguyên tố dựa trên nhận xét:
//Mọi số nguyên tố > 3 đều có dạng 6k + 1 hoặc 6k - 1
bool isPrime(int n) {
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int k = -1;
    const int MAX = (int)(sqrt(n));
    while (k <= MAX) {
        k += 6;
        if (n % k == 0 || n % (k+2) == 0) return false;
    }
    return true;
}

void solve(int n) {
    /** Chia 2 trường hợp để giải, n lẻ và chẵn
      * Ta dùng giả thuyết Goldback sau để giải: Mọi số nguyên lẻ đều có thể phân tích thành
      * tổng của 2 số nguyên tố(đã được kiểm chứng đến 4*10^18).
      *
      * Trong trường hợp n lẻ, ta có nhận xét sau: khoảng cách giữa các số nguyên tố liên tiếp
      * nhau là không quá lớn, trong phạm vi 10^9, khoảng cách tối đa chỉ gần 300.
      * Vì vậy, ta xét từ n - 300 đến n để tìm số thứ nhất trong tổng. Sau đó, ta brute force
      * để tìm hai số còn lại do tổng của chúng lẻ, tức luôn tồn tại.
      * Độ phức tạp 300.căn(n)
      *
      * Trong trường hợp n chẵn, tổng phải luôn tồn tại 2, nên phần còn lại là n - 2 ta dùng
      * cách brute force để tìm hai số còn lại. Test trong phạm vi 2000000000 luôn tìm được với
      * thời gian rất nhanh.
      */

    if (n % 2 != 0) {
        int firstNum = 0, sum = 0;
        for (int i = n - 1; i >= n - 300; --i) {
            if (isPrime(i)) {
                firstNum = i;
                sum = n - i;
                break;
            }
        }
        const int temp2 = sum - 2;
        if (isPrime(temp2) && temp2 != 2) {
            cout << firstNum << " " << temp2 << " " << 2; //Comment this line when testing
        } else {
            for (int i = 3; i <= n/2; i += 2) {
            const int temp = sum - i;
                if (isPrime(i)) {
                    if (isPrime(temp) && temp != i) {
                        cout << firstNum << " " << temp << " " << i; //Comment this line when testing
                        break;
                    }
                }

            }
        }
    } else {
        const int firstNum = 2, sum = n - 2;
        for (int i = 3; i <= n/2; i += 2) {
            const int temp = sum - i;
            if (isPrime(i)) {
                if (isPrime(temp) && temp != i) {
                    cout << firstNum << " " << temp << " " << i; //Comment this line when testing
                    break;
                }
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

    solve(n);

//    TESTING SECTION
//    for (int i = 1; i <= 100000000; ++i) {
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
