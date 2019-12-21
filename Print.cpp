#include"print.h"
void Print(Graphcnt& G, int v, int dist[], int path[])
{
	//输出path数组中存储的图G从顶点v到其余各顶点的路径和距离
	cout << G.NodeTable[v].start << "'s route table:" << endl;
	int i, j, k, n = G.numnode;
	int* d = new int[n];
	for (i = 0; i < n; i++)
	{
		if (i != v)
		{
			j = i;
			k = 0;
			while (j != v)
			{
				d[k++] = j;
				j = path[j];
			}


			if (k == 1)
			{
				cout << "\tDestination network-> " << G.NodeTable[d[0]].start << " ";
				cout << "Direct delivery" << " ";//直接交付
			}
			else
			{
				cout << "\tDestination network-> " << G.NodeTable[d[0]].start << " ";
				cout << "Next jump --> " << G.NodeTable[d[k - 1]].start << " ";//下一跳
			}
			cout << "Shortest path length：" << dist[i] << endl;//最短路径长度
		}
	}
	delete[] d;
}
