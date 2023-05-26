#include <bits/stdc++.h>
using namespace std;

class graph
{
    // number of vertices ;
    int v;
    // adjancy list for storing the edges
    vector<list<int>> adj;

public:
    // for dfs
    map<int, bool> visitedd;
    map<int, list<int>> adjj;
    void addedgee(int v, int w);
    void dfs(int s);

    // for bfs :
    graph(int v);
    void addedge(int v, int w);
    void bfs(int s);
};

graph::graph(int v)
{
    this->v = v;
    adj.resize(v);
}

void graph::addedge(int v, int w) // for bfs
{
    adj[v]
        .push_back(w);
}

void graph::addedgee(int v, int w) // for dfs
{
    adjj[v].push_back(w);
}

void graph::dfs(int v)
{
    visitedd[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adjj[v].begin(); i != adjj[v].end(); ++i)
    {
        if (!visitedd[*i])
            dfs(*i);
    }
}
void graph::bfs(int s)
{
    // mark all the vertices as visited
    vector<bool> visited;
    visited.resize(v, false);
    visited[s] = true;

    list<int> queue;
    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main()
{
    int v, e;
    int v1, v2;
    int s;

    cout << "Enter the number of vertices : " << endl;
    cin >> v;
    cout << "Enter the number of edges :" << endl;
    cin >> e;
    graph g(v);
    int choice;
    do
    {
        cout << endl;
        cout << "------MENU------" << endl;
        cout << "1. Breadth First Search" << endl;
        cout << "2. Depth First Search " << endl;
        cout << "3. Exit " << endl;
        cout << endl;
        cout << "Please Enter your choice : " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < e; i++)
            {
                cout << "Enter the two vertices : " << endl;
                cin >> v1 >> v2;
                g.addedge(v1, v2);
            }
            int s1;
            cout << "From where do you want to start the traversal ? " << endl;
            cin >> s;

            cout << "Breadth First Search is :" << endl;
            g.bfs(s);
            break;
        case 2:
            for (int i = 0; i < e; i++)
            {
                cout << "Enter the two vertices : " << endl;
                cin >> v1 >> v2;
                g.addedgee(v1, v2);
            }

            cout << "From where do you want to start the traversal ? " << endl;
            cin >> s;

            cout << "Depth First Search is :" << endl;
            g.dfs(s);
            break;

        case 3:
            cout << "Thankyou for using our program " << endl;
            break;

        default:
            cout << "Please enter valid choice !" << endl;
            break;
        }
    } while (choice != 3);
    //  g.addEdge(0, 1);
    //  g.addEdge(0, 2);
    //  g.addEdge(1, 2);
    //  g.addEdge(2, 0);
    //  g.addEdge(2, 3);
    //  g.addEdge(3, 3);
    return 0;
}