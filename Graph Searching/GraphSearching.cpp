#include <iostream>
#include <vector>
#include <queue>
using namespace std;

enum State {NotFound, Found, FullyVisited};
class Graph
{
    int numberOfNodes;
    vector<vector<int>> adjMatrix;
    vector<bool> visited; // For DFS
    vector<State> states; //For BFS
    queue<int> Q; // For BFS
    bool isDirected;
    
    void DepthFirstSearch (int Node)
    {
        visited[Node] = true;
        cout << Node << " ";
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (adjMatrix[Node][i] == 1 && visited[i] == false)
                DepthFirstSearch(i);
        }
    }

    void BreadthFirstSearch (int StartNode)
    {
        cout << StartNode << " ";
        Q.push(StartNode);
        states[StartNode] = Found;
        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();
            for (int i = 0; i < numberOfNodes; i++)
            {
                if (adjMatrix[node][i] == 1 && states[i] == NotFound)
                {
                    states[i] = Found;
                    cout << i << " ";
                    Q.push(i);
                }
            }
            states[node] = FullyVisited;
        }
    }
    
public:
    Graph(int numberOfNodes, bool isDirected)
        : numberOfNodes(numberOfNodes), isDirected(isDirected)
    {
        adjMatrix = vector<vector<int>>(numberOfNodes, vector<int>(numberOfNodes, false));
        visited = vector<bool>(numberOfNodes, false);
        states = vector<State>(numberOfNodes, NotFound);
    }

    void ConnectNodes()
    {
        int node1, node2, numberOfEdges;
        cout << "Number of edges?: ";
        cin >> numberOfEdges;
        for (int i = 0; i < numberOfEdges; i++)
        {
            cin >> node1 >> node2;
            if (isDirected)
            {
                adjMatrix[node1][node2] = 1;
            }
            else
            {
                adjMatrix[node1][node2] = 1;
                adjMatrix[node2][node1] = 1;
            }
        }
    }

    void DepthFirstSearch()
    {
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (!visited[i])
            {
                DepthFirstSearch(i);
                cout << endl;
            }
        }
    }

    void BreadthFirstSearch ()
    {
        for (int i = 0; i < numberOfNodes; i++)
        {
            if (states[i] == NotFound)
            {
                BreadthFirstSearch(i);
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph graph(7, false);
    graph.ConnectNodes();
    graph.DepthFirstSearch();
    graph.BreadthFirstSearch();
}