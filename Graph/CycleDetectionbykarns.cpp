#include <bits/stdc++.h>
using namespace std;

bool CycleDetectionKahn(int V)
{
    vector<int> indegree(V, 0);

    // Calculate indegree
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            indegree[adjList[i][j]]++;
        }
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (int j = 0; j < adjList[node].size(); j++)
        {
            indegree[adjList[node][j]]--;

            if (indegree[adjList[node][j]] == 0)
            {
                q.push(adjList[node][j]);
            }
        }
    }

    return count != V;
}

int main() {



    return 0;
}