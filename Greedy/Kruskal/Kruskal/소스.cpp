#include <bits/stdc++.h>

#define MAX_V 100
using namespace std;

int v_num, e_num;
vector<pair<int, int>> adj[MAX_V];

struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) const {
        if (u == parent[u]) return u;
        return find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        parent[u] = v;
    }
};

int kruskal(vector<pair<pair<int, int>, int>>& selected)
{
    int ret = 0;
    selected.clear();

    vector<pair<int, pair<int, int>>> edges;

    for (int u = 0; u < v_num; u++) {
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet sets(v_num);
    for (int i = 0; i < (int)edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;

        if (sets.find(u) == sets.find(v)) continue;

        sets.merge(u, v);
        selected.push_back(make_pair(make_pair(u, v), cost));
        ret += cost;
    }
    return ret;
}

int main()
{
    char vertex1, vertex2;
    int weight;

    cout << "정점과 간선의 개수 각각: "; cin >> v_num >> e_num;
    cout << "연결된 정점과 가중치 입력" << endl;

    for (int i = 0; i < e_num; i++) {
        cin >> vertex1 >> vertex2 >> weight;
        adj[vertex1 - 'A'].push_back(make_pair(vertex2 - 'A', weight));
        adj[vertex2 - 'A'].push_back(make_pair(vertex1 - 'A', weight));
    }

    vector<pair<pair<int, int>, int>> selected;
    int mst = kruskal(selected);

    cout << "최소신장트리의 합: " << mst << endl;
    for (int i = 0; i < (int)selected.size(); i++) {
        cout << (char)(selected[i].first.first + 'A') << " -> " << (char)(selected[i].first.second + 'A') << " Cost: " << selected[i].second << endl;
    }

    return 0;
}