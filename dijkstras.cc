#include <bits/stdc++.h>

using namespace std;

map<int, int> normalizedValue;
vector<pair<int, int>> path;
map<int, bool> visited;

int minval = 2147483647;

// pair<int, int> *returnMin(pair<int, int> *val)
// {
//     if (minVar == nullptr)
//         return val;
//     if(val->)
// }

void DijkstrasAlgorithm(map<int, list<pair<int, int>>> &graph, int start, int end)
{
    // cout<<start<<end<<endl;
    minval = 2147483647;
    cout<<start<<endl;
    if (start == end)
        return;
    visited[start] = true;
    for (list<pair<int, int>>::iterator i = graph[start].begin(); i != graph[start].end(); i++)
    {
        if (visited[i->first] == true)
        {
            continue;
        }

        normalizedValue[i->first] = normalizedValue[start] + i->second;
        // cout << normalizedValue[i->first] << endl;
        if (normalizedValue[i->first] < normalizedValue[minval])
        {
            minval = i->first;
        }
    }
    // cout<<minval<<endl;
    DijkstrasAlgorithm(graph, minval, 7);
}

int main()
{
    map<int, list<pair<int, int>>> graph;
    graph[1].push_front(make_pair(2, 3));
    graph[1].push_front(make_pair(4, 2));

    graph[2].push_front(make_pair(1, 3));
    graph[2].push_front(make_pair(4, 2));
    graph[2].push_front(make_pair(3, 1));
    graph[2].push_front(make_pair(5, 4));

    graph[4].push_front(make_pair(1, 2));
    graph[4].push_front(make_pair(2, 2));
    graph[4].push_front(make_pair(3, 3));
    graph[4].push_front(make_pair(7, 6));
    graph[4].push_front(make_pair(6, 5));

    graph[3].push_front(make_pair(2, 1));
    graph[3].push_front(make_pair(4, 3));
    graph[3].push_front(make_pair(7, 2));

    graph[5].push_front(make_pair(2, 4));
    graph[5].push_front(make_pair(7, 1));

    graph[6].push_front(make_pair(4, 5));
    graph[6].push_front(make_pair(7, 2));

    graph[7].push_front(make_pair(5, 1));
    graph[7].push_front(make_pair(3, 2));
    graph[7].push_front(make_pair(4, 6));
    graph[7].push_front(make_pair(6, 2));

    normalizedValue[1] = 0;
    normalizedValue[minval] = minval;

    DijkstrasAlgorithm(graph, 1, 7);

    return 0;
}
