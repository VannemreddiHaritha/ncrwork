#include<iostream>
#include<queue>
using namespace std;
class graph_ {
	double **graph;
	int vertices;
public:
	graph_();
	graph_(int, double**);
	graph_(const graph_&);
	//void DFS();
	void BFS();
	friend istream& operator>>(istream&, graph_&);
	friend ostream& operator<<(ostream&, graph_);
 };
graph_::graph_()
{
	graph = NULL;
	vertices = 0;
}
graph_::graph_(int v, double **adj_matrix)
{
	vertices = v;
	int i,j;
	graph = new double*[vertices];
	for (i = 0;i < vertices;i++)
	{
		graph[i] = new double[vertices];
		for (j = 0;j < vertices;j++)
			graph[i][j] = adj_matrix[i][j];
	}


}
graph_::graph_(const graph_ &g)
{
	int i, j;
	vertices = g.vertices;
	graph = new double*[vertices];
	for (i = 0;i < vertices;i++)
	{
		graph[i] = new double[vertices];
		for (j = 0;j < vertices;j++)
			graph[i][j] = g.graph[i][j];
    }
}
istream& operator>>(istream& cin, graph_ &g)
{
	int i, j;
	cout << "enter no of vertices";
	cin >> g.vertices;
	
	g.graph = new double*[g.vertices];
	cout << "enter elements in graph";
	for (i = 0;i < g.vertices;i++)
	{
		g.graph[i] = new double[g.vertices];
		for (j = 0;j < g.vertices;j++)
			cin >> g.graph[i][j];
	}
	return cin;
}
ostream& operator<<(ostream& cout, graph_ g)
{
	int i, j;
	for (i = 0;i < g.vertices;i++)
	{
		for (j = 0;j < g.vertices;j++)
			cout <<g.graph[i][j] << " ";
		cout << endl;
	}
	return cout;
}
void graph_:: BFS()
{
	int currentnode=0,source=0;
	int i;
	queue<int> q_obj;
     bool *visited = new bool[vertices];
	for (i = 0;i < vertices;i++)
		visited[i] = false;
	q_obj.push(source);
	visited[source] = true;
	cout << "the output of bfs is";
	while (!q_obj.empty())//
	{
		currentnode = q_obj.front();
		cout << currentnode << endl;
		q_obj.pop();
		int i;
		for (i = currentnode;i < vertices;i++)
		{
			if (!visited[i] && graph[currentnode][i] != 0)//pushing neighbours of current node to
			{

				q_obj.push(i);
				visited[i] = true;

			}
		}

	}
}
int main()
{
	graph_ g_obj1;
	double **adj_matrix=NULL;
	int vertices;
	cout << "enter number of vertices"<<endl;
	cin >> vertices;
	int i,j;
	cout << "enter the elemnts of adjaceny matrix";
	adj_matrix = new double*[vertices];
	for (i = 0;i < vertices;i++)
	{
		adj_matrix[i] = new double[vertices];
		for (j = 0;j < vertices;j++)
		{
			cin >> adj_matrix[i][j];
		}
	}
	

	graph_ g_obj2(vertices, adj_matrix),g_obj3(g_obj2);
	
	cout << "the matrix is";
	cout << g_obj3<<endl;
	g_obj3.BFS();
	system("pause");
	return 0;

}
