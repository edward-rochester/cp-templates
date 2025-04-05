#include <bits/stdc++.h> 

using namespace std;

class dsu {
    int n;
    int n_components;
    vector<int> parent, rank;

public:
    dsu(int n) {
        assert(n > 0);
        this->n = n;
        n_components = n;
        parent.resize(n);
        rank.resize(n);

        iota(parent.begin(), parent.end(), 0);
        fill(rank.begin(), rank.end(), 1);
    }

    int number_of_components() {
        return n_components;
    }

    int find_set(int v) {
        assert(v >= 0 and v < n);
        if (parent[v] == v)
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int u, int v) {
        assert(u >= 0 and u < n);
        assert(v >= 0 and v < n);
        u = find_set(u);
        v = find_set(v);

        if (u != v) {
            n_components--;
            if (rank[v] < rank[u])
                swap(u, v);

            parent[u] = v;
            if (rank[u] == rank[v])
                rank[v]++;
        }
    }
};

int main() {
    dsu d(20);

    d.union_sets(1, 5);
    d.union_sets(6, 7);
    d.union_sets(4, 5);

    d.union_sets(8, 11);
    d.union_sets(9, 15);
    d.union_sets(6, 11);

    cout << d.number_of_components() << '\n';

    for (int i = 0; i < 20; i++)
        cout << d.find_set(i) << ' ';
    cout << '\n';
    return 0;
}