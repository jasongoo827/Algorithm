#include <bits/stdc++.h>
#define MAX_LEN 10
using namespace std;

// vertex 8 edge 14
int v_num, e_num;
vector<pair<char, int>> graph[MAX_LEN];
int dist[MAX_LEN];
int INF = std::numeric_limits<int>::max();
vector<bool> visited(MAX_LEN, false);

int getShortestNode()
{
    int min = INF;
    int idx = 0;

    for (int i = 0; i < v_num; i++) {
        if ((dist[i] < min) && !visited[i]) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}


void dijkstra(int start)
{
    dist[start] = 0;
    visited[start] = true;

    for (int i = 0; i < (int)graph[start].size(); i++) {
        dist[graph[start][i].first - 'A'] = graph[start][i].second;
    }

    for (int i = 0; i < v_num - 1; i++) {
        int here = getShortestNode();
        visited[here] = true;

        for (int j = 0; j < (int)graph[here].size(); j++) {
            int cost = dist[here] + graph[here][j].second;

            if (cost < dist[graph[here][j].first - 'A']) {
                dist[graph[here][j].first - 'A'] = cost;
            }
        }
    }
}

int main()
{
    char vertex1, vertex2;
    int weight;

    cout << "정점과 간선의 개수 각각: "; cin >> v_num >> e_num;
    cout << "연결된 정점과 가중치 입력" << endl;

    for (int i = 0; i < e_num; i++) {
        cin >> vertex1 >> vertex2 >> weight;
        graph[vertex1 - 'A'].push_back(make_pair(vertex2, weight));
        graph[vertex2 - 'A'].push_back(make_pair(vertex1, weight));
    }

    fill_n(dist, MAX_LEN, INF);

    dijkstra(0);

    for (int i = 1; i < v_num; i++) {
        if (dist[i] == INF) {
            cout << "A 와 " << (char)(i + 'A') << "의 거리: INF" << endl;
        }
        else {
            cout << "A 와 " << (char)(i + 'A') << "의 거리: " << dist[i] << endl;
        }
    }
    return 0;
}