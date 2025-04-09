#include <bits/stdc++.h>

using namespace std;

template <typename T>
class rmin_table {
    int n;
    vector<vector<T>> table;
    vector<int> logs;

    void gen_logs() {
        logs.resize(n + 1);
        logs[1] = 0;
        for (int j = 2; j <= n; j++)
            logs[j] = logs[j - 1] + ((j & (j - 1)) == 0);
    }

public:
    rmin_table(vector<T> &array) {
        n = array.size();
        assert(n > 0);
        gen_logs();
        table.resize(n);
        for (int j = n - 1; j >= 0; j--) {
            table[j].resize(logs[n - j] + 1);
            table[j][0] = array[j];
            for (int p = 1; j + (1 << p) - 1 < n; p++)
                table[j][p] = min(table[j][p - 1], table[j + (1 << (p - 1))][p - 1]);
        }
    }

    T get(int l, int r) {
        assert(l >= 0 and l < n and r >= 0 and r < n and l <= r);
        int x = logs[r - l + 1];
        return min(table[l][x], table[r - (1 << x) + 1][x]);
    }
};

template <typename T>
class rmax_table {
    int n;
    vector<vector<T>> table;
    vector<int> logs;

    void gen_logs() {
        logs.resize(n + 1);
        logs[1] = 0;
        for (int j = 2; j <= n; j++)
            logs[j] = logs[j - 1] + ((j & (j - 1)) == 0);
    }

public:
    rmax_table(vector<T> &array) {
        n = array.size();
        assert(n > 0);
        gen_logs();
        table.resize(n);
        for (int j = n - 1; j >= 0; j--) {
            table[j].resize(logs[n - j] + 1);
            table[j][0] = array[j];
            for (int p = 1; j + (1 << p) - 1 < n; p++)
                table[j][p] = max(table[j][p - 1], table[j + (1 << (p - 1))][p - 1]);
        }
    }

    T get(int l, int r) {
        assert(l >= 0 and l < n and r >= 0 and r < n and l <= r);
        int x = logs[r - l + 1];
        return max(table[l][x], table[r - (1 << x) + 1][x]);
    }
};

void solve_cses_static_range_minimum_queries_problem() {
    // USING O(1) RANGE MINIMUM SPARSE TABLE
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int j = 0; j < n; j++)
        cin >> a[j];
    rmin_table<long long> s(a);
    // int q;
    // cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << s.get(l, r) << '\n';
    }
}

void simple_demo() {
    vector<int> a = {1, 5, 1, 4, 2, 1, 4, 1};
    rmax_table<int> st(a);

    cout << st.get(0, 0) << '\n';
    cout << st.get(2, 4) << '\n';
    cout << st.get(1, 4) << '\n';
    cout << st.get(4, 5) << '\n';
}

int main() {
    
    // Good way to test the functionality.
    // Submit this file as is to the CSES
    // judge. If you want to use the simple
    // demo, comment this line and use the
    // next line instead.
    solve_cses_static_range_minimum_queries_problem();

    // simple_demo();   

    return 0;
}