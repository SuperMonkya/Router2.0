#include"main.h"
int DefaultVertices = 30;
using namespace std;
int main()
{
	Graphcnt G(30);
	cout << "Read file and insert node." << endl;
	G.insertnode();
	cout << "The total number of nodes:" << G.numnode << endl;
	int i, j, weight;
	ifstream fin("data2.txt", std::ios::in);
	char line[1024] = { 0 };
	string x = "";
	string y = "";
	string m = "";
	int z;
	while (fin.getline(line, sizeof(line)))
	{
		stringstream word(line);
		word >> x;//路由起点 
		word >> y;//路由终点 
		word >> z;//权值 
		word >> m;//网络号 
		i = G.getnode(x);
		j = G.getnode(y);
		weight = z;
		G.insertEdge(i, j, weight, m);
	}

	fin.clear();
	fin.close();
	cout << "\tThe total number of edges:" << G.numEdges << endl;
	int h;
	int r;
	int* dist = new int[G.numnode];
	int* path = new int[G.numEdges];
	string v, u; int a = 1, b;
	//输出路由表 

	while (a)
	{
		cout << "    1.Print routing table(route number)\n    2.Delete a node\n    3.Delete a edge\n    4.Add a node\n    5.Add a edge\n    6.Exit" << endl;
		cin >> b;
		if (b == 1)
		{
			cout << "Please enter the route number to be queried:" << endl;
			cin >> v;
			r = G.getnode(v);
			while (r == -1)
			{
				cout << "There is no such router." << endl;
				cout << "Please enter the router:" << endl;
				cin >> v;
				r = G.getnode(v);
			}

			shortestway(G, r, dist, path);
		}
		if (b == 2)
		{

			//删除一个路由器 
			cout << "Delete node." << endl;
			cin >> v;
			int w = G.getnode(v);
			while (!G.removenode(w))
			{
				cout << "There is no such node." << endl;
				cout << "Delete node." << endl;
				cin >> v;
				w = G.getnode(v);
			}
			cout << "A new routing table has been generated.\tPlease enter the router to view the routing table:" << endl;
			cin >> v;
			r = G.getnode(v);
			if (r == -1)
			{
				cout << "There is no such router." << endl;
			}
			else
			{
				shortestway(G, r, dist, path);
			}
		}
		if (b == 3)
		{
			//删除一条边 
			cout << "Delete a edge." << endl;
			cin >> v;
			cin >> u;
			r = G.getnode(v);
			h = G.getnode(u);
			while (!G.Delete_Edge(r, h))
			{
				cout << "Delete a edge." << endl;
				cin >> v;
				cin >> u;
				r = G.getnode(v);
				h = G.getnode(u);
			}

		}
		if (b == 5)
		{
			cout << "Please enter the front and rear node,weight,network number：\n";
			ofstream fout("data2.txt", ofstream::app);
			char str[1024];
			if (cin >> str)
			{
				gets_s(str);
				fout << str << endl;
			}
			fout.close();
			ifstream fin("data2.txt", ios::in);
			char line[1024] = { 0 };
			string x = "";
			string y = "";
			string m = "";
			string n = "";
			int z;
			while (fin.getline(line, sizeof(line)))
			{
				stringstream word(line);
				word >> x;//路由起点 
				word >> y;//路由终点 
				word >> z;//权值 
				word >> m;//网络号 
				i = G.getnode(x);
				j = G.getnode(y);
				weight = z;
				G.insertEdge(i, j, weight, m);
			}
			fin.clear();
			fin.close();
			cout << "The total number of edges:" << G.numEdges << endl;
			int h;
			int r;
			int* dist = new int[G.numnode];
			int* path = new int[G.numEdges];
		}
		if (b == 4)
		{
			cout << "Please enter the node you want to add：\n";
			ofstream out("data1.txt", ofstream::app);
			char ch[10];
			cin.ignore();
			if (cin >> ch)
			{
				out << ch << endl;
			}
			out.close();
			ifstream fin("data1.txt", std::ios::in);
			char line[1024] = { 0 };
			G.numnode = 0;
			string x = "";
			while (fin.getline(line, sizeof(line)))
			{
				stringstream word(line);
				word >> x;
				G.NodeTable[G.numnode].start = x;
				G.numnode++;
			}
			fin.clear();
			fin.close();
			cout << "Node inserted successfully!!" << endl;
		}

		if (b == 6)
		{
			a = 0;
			cout << "Thank you for using." << endl;
		}

	}

}
