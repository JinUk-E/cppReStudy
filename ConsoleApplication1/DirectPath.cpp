#include <iostream>
#include <queue>
#define INF 1600000

int N, E;
int graph[801][801];
int v1, v2;
int dist[801];

int dijkstra(int start, int end) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        const int cur_dist =  -pq.top().first;
        const int cur_node = pq.top().second;
        pq.pop();
        for (int i = 0; i <= 801; i++)
        {
            const int next_dist = cur_dist + graph[cur_node][i];
            if (dist[i] > next_dist)
            {
                dist[i] = next_dist;
                pq.emplace(-next_dist,i);
            }
        }
    }
    return dist[end];
}

int main()
{    
    std::cin >> N >> E;
   
    for(int i=0; i< E; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    std::cin >> v1 >> v2;

    const int result = dijkstra(v1, v2);

    const int start_to_v1 = dijkstra(1, v1);
    const int start_to_v2 = dijkstra(1, v2);
    const int v1_to_end = dijkstra(v1, N);
    const int v2_to_end = dijkstra(v2, N);
    
    std::cout << "" << std::endl;
    std::cout << v1 << "to" << v2 << "::" << result << std::endl;
    std::cout << 1 << "to" << v1 << "::" << start_to_v1 << std::endl;
    std::cout << 1 << "to" << v2 << "::" << start_to_v2 << std::endl;
    std::cout << v1 << "to" << N << "::" << v1_to_end << std::endl;
    std::cout << v2 << "to" << N << "::" << v2_to_end << std::endl;
}