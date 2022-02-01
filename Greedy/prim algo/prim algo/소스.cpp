#include <bits/stdc++.h>

#define MAX_V 100
using namespace std;

//정점 10 간선 16

int v_num, e_num;
int INF = std::numeric_limits<int>::max();
vector<pair<int, int>> graph[MAX_V];

//최소 신장트리의 합 구하기
int prim(vector<pair<pair<int, int>, int>>& selected)
{
    selected.clear();

    vector<bool> added(v_num, false);
    vector<int> minWeight(v_num, INF), parent(v_num, -1);

    int ret = 0;
    minWeight[0] = parent[0] = 0;

    for (int iter = 0; iter < v_num; iter++) {
        int u = -1;
        for (int v = 0; v < v_num; v++) {
            if (!added[v] && (u == -1 || minWeight[u] > minWeight[v])) {
                u = v;
            }
        }
        if (parent[u] != u) {
            selected.push_back(make_pair(make_pair(parent[u], u), minWeight[u]));
        }

        ret += minWeight[u];
        added[u] = true;

        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].first, weight = graph[u][i].second;
            if (!added[v] && (minWeight[v] > weight)) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
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
        graph[vertex1 - 'A'].push_back(make_pair(vertex2 - 'A', weight));
        graph[vertex2 - 'A'].push_back(make_pair(vertex1 - 'A', weight));
    }

    vector<pair<pair<int, int>, int>> selected;
    int mst = prim(selected);

    cout << "최소신장트리의 합: " << mst << endl;
    for (int i = 0; i < (int)selected.size(); i++) {
        cout << (char)(selected[i].first.first + 'A') << " -> " << (char)(selected[i].first.second + 'A') << " Cost: " << selected[i].second << endl;
    }
    return 0;
}