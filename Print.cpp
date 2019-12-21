#include"print.h"
void Print(Graphcnt& G, int v, int dist[], int path[])
{
	//���path�����д洢��ͼG�Ӷ���v������������·���;���
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
				cout << "Direct delivery" << " ";//ֱ�ӽ���
			}
			else
			{
				cout << "\tDestination network-> " << G.NodeTable[d[0]].start << " ";
				cout << "Next jump --> " << G.NodeTable[d[k - 1]].start << " ";//��һ��
			}
			cout << "Shortest path length��" << dist[i] << endl;//���·������
		}
	}
	delete[] d;
}
