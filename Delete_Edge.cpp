#include"delete_edge.h"

bool Graphcnt::Delete_Edge(int v1, int v2){  //删除一条边
	cout << "Li Yufan" << endl;
	if (v1 != -1 && v2 != -1){
		Edge* p = NodeTable[v1].adj, * q = NULL, * s = p;
		while (p != NULL && p->dest != NodeTable[v2].start){q = p; p = p->link;}
		if (p != NULL) {   //找到被删边
			if (p == s) NodeTable[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else{//为空，即没有找到需要删除的边
			//cout << "\tThere is no edge between two nodes." << endl;//两点间没有边
			return false;
		}
		//进行删除的后续操作
		p = NodeTable[v2].adj; q = NULL; s = p;
		while (p->dest != NodeTable[v1].start){
			q = p; p = p->link;
		}
		if (p == s) NodeTable[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		cout << "Delete successfully." << endl;//删除成功
		return true;
	}
	else{
		cout << "Node error,deletion failed." << endl;//要删结点不存在，删除失败
		return false;
	}
}









