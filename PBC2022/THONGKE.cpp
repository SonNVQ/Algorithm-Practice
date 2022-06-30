#include <bits/stdc++.h>

using namespace std;

bool IsNumber(string s) {
    if (s.length() == 0) return false;
    for (int i = 0; i < s.length(); ++i) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

int main() {
    freopen("THONGKE.INP", "r", stdin);
    freopen("THONGKE.OUT", "w", stdout);
    int N;
    cin >> N;
    set<int> years;
    while (N--) {
        string temp = "";
        while (!IsNumber(temp)) {
            cin >> temp;
        }
        int year;
        stringstream convert(temp);
        convert >> year;
        years.emplace(year);
    }
    int Y[N], idx = 0;
    for (auto x: years) {
        Y[idx++] = x;
    }
    int re = -1, y_min, y_max;
    for (int i = 1; i < idx; ++i) {
        int t = Y[i] - Y[i-1] - 1;
        if (t > 0 && t > re) {
            re = t;
            y_min = Y[i-1] + 1;
            y_max = Y[i] - 1;
        }
    }
    if (re == 0) re = -1;
    if (idx == 1 || re == -1)
        cout << "-1";
    else {
        cout << re << endl;
        cout << y_min << " " << y_max;
    }
    return 0;
}
