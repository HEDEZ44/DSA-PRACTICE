

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph
{
    int V;
    list<pair<int, int>> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w)
    {
        graph[u].push_back(make_pair(v, w));
    }

    vector<int> shortestPath(int source)
    {

        set<pair<int, int>> setds;

        vector<int> distance(V, INF);

        setds.insert(make_pair(0, source));
        distance = 0;

        while (!setds.empty())
        {

            pair<int, int> tmp = *(setds.begin());
            setds.erase(setds.begin());

            int u = tmp.second;

            list<pair<int, int>>::iterator i;
            for (i = graph[u].begin(); i != graph[u].end(); ++i)
            {

                int v = (*i).first;
                int weight = (*i).second;

                if (distance[v] > distance[u] + weight)
                {

                    if (distance[v] != INF)
                        setds.erase(setds.find(make_pair(distance[v], v)));

                    distance[v] = distance[u] + weight;
                    setds.insert(make_pair(distance[v], v));
                }
            }
        }
        return distance;
    }

    Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V)
    {
        Graph g(V);
        for (int i = 0; i < E; i++)
        {

            g.addEdge(edge[i][0], edge[i][1], 0);

            g.addEdge(edge[i][1], edge[i][0], 1);
        }
        return g;
    }

    int getMinEdgeReversal(int edge[][2], int E, int V, int source, int destination)
    {

        Graph g = modelGraphWithEdgeWeight(edge, E, V);

        vector<int> dist = g.shortestPath(source);

        if (dist[destination] == INF)
            return -1;
        else
            return dist[destination];
    }
};

int main()
{
    int V = 7;
    Graph g(V);

    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);

    int minEdgeToReverse = g.getMinEdgeReversal(edge, E, V, 0, 6);

    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not Possible." << endl;

    return 0;
}

#include <set>

int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
    set<vector<int>> st;
    vector<int> distance(n, n);
    vector<vector<vector<int>>> graph(n);

    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0], v = edgeList[i][1];
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 1});
    }

    distance[0] = 0;
    st.insert({0, start});

    while (st.empty() == false)
    {

        vector<int> u = *st.begin();
        st.erase(u);

        int node = u[1];

        for (int i = 0; i < graph[node].size(); i++)
        {
            int v = graph[node][i][0], weight = graph[node][i][1];

            if (distance[v] > distance[node] + weight)
            {

                if (distance[v] != n)
                {
                    st.erase({distance[v], v});
                }

                distance[v] = distance[node] + weight;
                st.insert({distance[v], v});
            }
        }
    }

    return distance[end];
}