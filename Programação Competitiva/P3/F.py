import sys
import heapq

def dijkstra(graph, start, end):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    queue = []
    heapq.heappush(queue, [distances[start], start])
    while queue:
        current_distance, current_vertex = heapq.heappop(queue)
        if distances[current_vertex] < current_distance:
            continue
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, [distance, neighbor])
    return distances[end]

def main():
    num_tests = int(sys.stdin.readline())
    for i in range(num_tests):
        num_vertices, num_edges = [int(x) for x in sys.stdin.readline().split()]
        graph = {vertex: {} for vertex in range(1, num_vertices + 1)}
        for j in range(num_edges):
            a, b, weight = [int(x) for x in sys.stdin.readline().split()]
            graph[a][b] = weight
            graph[b][a] = weight
        start, end = [int(x) for x in sys.stdin.readline().split()]
        result = dijkstra(graph, start, end)
        if(result == float('infinity')):
            print("NO")
        else:
            print(result)

if __name__ == '__main__':
    main()