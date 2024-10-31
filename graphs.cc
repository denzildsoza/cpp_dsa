#include <bits/stdc++.h>

using namespace std;

map<int, bool> visited;
queue<int> elements;
int dfs(map<int, list<int>> &graph, int key)
{
    visited[key] = true;
    cout << key << endl;
    for (list<int>::iterator i = graph[key].begin(); i != graph[key].end(); i++)
    {
        if (visited[*i] != true)
            dfs(graph, *i);
    }
}
int bfs(map<int, list<int>> &graph, int key)
{
    visited[key] = true;
    cout << key << endl;
    while (elements.size() > 0)
    {
        int ele = elements.front();
        elements.pop();
        for (list<int>::iterator i = graph[ele].begin(); i != graph[ele].end(); i++)
        {
            if (visited[*i] != true)
            {
                elements.push(*i);
                visited[*i] = true;
                cout << *i << endl;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    map<int, list<int>> graph;
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[3].push_back(5);
    graph[3].push_back(6);
    graph[4].push_back(2);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(4);
    graph[5].push_back(2);
    graph[5].push_back(3);
    graph[5].push_back(7);
    graph[6].push_back(3);
    graph[7].push_back(5);

    elements.push(1);
    bfs(graph, 1);

    return 0;
}
