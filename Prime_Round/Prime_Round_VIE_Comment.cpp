#include <bits/stdc++.h>

using namespace std;

const int MAX = 30;
int N = 0; //N = 2*n
int total = 0; //Tổng các cách
int a[MAX], check[MAX]; //A: lưu kết quả, check: mảng trạng thái dùng để chọn số trong quá trình backtracking
bool isEnough = false; //dùng để thoát backtracking nếu vượt quá 10000 cách
string result = ""; //lưu chuỗi kết quả để in ra sau khi in tổng số cách
int isPrime[2*MAX]; //0: nguyên tố; 1: hợp số

//Sàng nguyên tố
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
        //Bỏ qua nếu tổng số cuối và số đầu không phải nguyên tố
        if (isPrime[a[k-1] + 1] == 1)
            return;
        //Nếu thoả mãn
        if (++total > 10000) {
            --total;
            isEnough = true;
            return;
        } //dừng khi đủ 10000 cách
		//Lưu kết quả vào chuỗi result
        for (int i = 1; i <= N; ++i)
            result += to_string(a[i]) + " ";
        result += "\n";
        return;
    }
    for (int i = 2; i <= N; ++i) {
        if (check[i] == 0) {
            check[i] = 1;
            a[k] = i;
            if (isPrime[a[k] + a[k-1]] == 0)  //Nếu thoả mãn nguyên tố thì xét tiếp, nếu không bỏ qua
                backtracking(k + 1);
            if (isEnough) //Thoát backtracking nếu đã đủ tối đa 10000 cách
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
