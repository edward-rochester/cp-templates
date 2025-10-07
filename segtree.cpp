#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct tree {
private:
    tree *left;
    tree *right;
    int bound_left;
    int bound_right;
    T val;

    tree(int bound_left,
         int bound_right,
         vector<T> &arr) {
        assert(bound_right >= bound_left);
        this->bound_left = bound_left;
        this->bound_right = bound_right;
        if (bound_left != bound_right) {
            int mid = (bound_right + bound_left) / 2;
            left = new tree(bound_left, mid, arr);
            right = new tree(mid + 1, bound_right, arr);

            // NOTE: Change here for different operation
            val = left->val + right->val;
        } else {
            val = arr[bound_left];
            left = right = nullptr;
        }
    }

public:
    tree(vector<T> &arr) : tree(0, arr.size() - 1, arr) {}

    void update(int i, T val) {
        assert (i >= bound_left and i <= bound_right);
        if (bound_left == bound_right)
            this->val = val;
        else {
            int mid = (bound_left + bound_right) / 2;
            if (i <= mid) 
                left->update(i, val);
            else
                right->update(i, val);
            
            // NOTE: Change here for different operation
            this->val = left->val + right->val;
        }
    }

    T get(int l, int r) {
        assert (l >= bound_left and r <= bound_right);
        if (l == bound_left and r == bound_right)
           return val;
        int mid = (bound_left + bound_right) / 2;
        if (l <= mid) {
            if (r <= mid)
                return left->get(l, r);
            else {
                
                // NOTE: Change here for different operation
                return left->get(l, mid) + right->get(mid + 1, r);
            }
        } else {
            return right->get(l, r);
        } 
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int j = 0; j < n; j++)
        cin >> a[j];
    tree<long long> s(a);
    // int q;
    // cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            long long p, x;
            cin >> p >> x;
            p--;
            s.update(p, x);
        }   
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << s.get(l, r) << '\n';
        }
    }

    return 0;
}