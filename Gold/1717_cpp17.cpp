#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class DisjointSet {
public:
    explicit DisjointSet(int numElements);

    void unionSets(T a, T b);
    bool findJoint(T a, T b);  // Checks if a and b belong to the same set
    T findSet(T a);  // Finds the representative of set containing a

private:
    vector<T> parent;
    vector<T> rank;
};

template<typename T>
DisjointSet<T>::DisjointSet(int numElements) {
    parent.resize(numElements);
    rank.resize(numElements, 0);
    
    for (int i = 0; i < numElements; i++)
        parent[i] = i;  // Initially, each element is its own leader
}

template<typename T>
T DisjointSet<T>::findSet(T a) {
    if (parent[a] != a)
        parent[a] = findSet(parent[a]);  // Path compression
    return parent[a];
}

template<typename T>
void DisjointSet<T>::unionSets(T a, T b) {
    T rootA = findSet(a);
    T rootB = findSet(b);

    if (rootA != rootB) {
        if (rank[rootA] > rank[rootB])
            parent[rootB] = rootA;
        else if (rank[rootA] < rank[rootB])
            parent[rootA] = rootB;
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

template<typename T>
bool DisjointSet<T>::findJoint(T a, T b) {
    return findSet(a) == findSet(b);
}

int main() {
    int n, m, c, a, b;
    cin >> n >> m;

    DisjointSet<int> ds(n + 1); 

    while (m--) {
        cin >> c >> a >> b;
        if (c == 0) {
            ds.unionSets(a, b);
        } else {
            cout << (ds.findJoint(a, b) ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
