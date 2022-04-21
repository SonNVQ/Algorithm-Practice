#include <bits/stdc++.h>

using namespace std;

#define int int64_t

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

//Chuyển chuỗi thành số
int stringToInt(string s) {
    int re = 0;
    for (int i = 0; i < s.length(); ++i)
        re = re * 10 + s[i] - 48;
    return re;
}

//Tìm chuỗi con nguyên tố lớn nhất trong xâu chỉ chứa các chữ số
int solveSubString(string s) {
    int re = 0;
    //Xét các xâu con theo chiều từ phải qua trái
    for (int i = s.length() - 1; i >= 0; --i) {
        const int k = (int)(s[i]) - 48; //Chuyển kí tự s[i] thành số k
        //Chỉ lấy các xâu kết thúc bằng chữ số lẻ,
        //nếu kết thúc bằng chữ số chẵn, xét trường hợp bằng 2
        if (k % 2 == 0) {
            if (k == 2) re = max(re, k);
            else continue;
        } else {
            re = max(re, k); //k chính là xâu chỉ chứa 1 kí tự s[i], xét trước
            string temp = "";
            temp += s[i];
            //Xét tiếp các xâu con
            for (int j = i - 1; j >= 0; --j) {
                temp = s[j] + temp;
                const int tempInt = stringToInt(temp);
                if (isPrime(tempInt))
                    re = max(re, tempInt);
            }
        }
    }
    return re;
}

//Tìm tất cả các xâu con chỉ chứa chữ số và xử lý bằng hàm solveSubString()
int solve(string s) {
    int i = s.length() - 1;
    int re = 0;
    while (i >= 0) {
        string temp = "";
        //Chỉ lấy các xâu kết thúc bằng chữ số lẻ,
        //nếu kết thúc bằng chữ số chẵn, xét trường hợp bằng 2
        if (s[i] >= '1' && s[i] <= '9') {
            const int k = s[i] - 48; //Chuyển kí tự s[i] thành số k
            if (k % 2 == 0) {
                if (k == 2) re = max(re, k);
            } else {
                temp = temp + s[i];
                int j = i - 1;
                //Lấy xâu chỉ chứa chữ số dài nhất có thể
                while (j >= 0 && s[j] >= '0' && s[j] <= '9') {
                    temp = s[j] + temp;
                    --j;
                }
                i = j; //Đặt lại i theo j, tránh trùng lặp
                re = max(re, solveSubString(temp));
            }
        }
        --i;
    }
    return re;
}

main()
{
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}
