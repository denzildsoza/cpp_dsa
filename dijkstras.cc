#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int, list<pair<int,int>>> graph;
    graph[1].push_front(make_pair(2,3));
    graph[1].push_front(make_pair(4,2));

    graph[2].push_front(make_pair(1,3));
    graph[2].push_front(make_pair(4,2));
    graph[2].push_front(make_pair(3,1));
    graph[2].push_front(make_pair(5,4));
    
    graph[4].push_front(make_pair(1,2));
    graph[4].push_front(make_pair(2,2));
    graph[4].push_front(make_pair(3,3));
    graph[4].push_front(make_pair(7,6));
    graph[4].push_front(make_pair(6,5));

    graph[3].push_front(make_pair(2,1));
    graph[3].push_front(make_pair(4,3));
    graph[3].push_front(make_pair(7,2));

    graph[5].push_front(make_pair(2,4));
    graph[5].push_front(make_pair(7,1));

    graph[6].push_front(make_pair(4,5));
    graph[6].push_front(make_pair(7,2));

    graph[7].push_front(make_pair(5,1));
    graph[7].push_front(make_pair(3,2));
    graph[7].push_front(make_pair(4,6));
    graph[7].push_front(make_pair(6,2));




    return 0;
}
