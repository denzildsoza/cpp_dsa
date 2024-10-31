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
    

    elements.push(1);
    bfs(graph, 1);

    return 0;
}
