#include"delete_edge.h"

bool Graphcnt::Delete_Edge(int v1, int v2){  //ɾ��һ����
	cout << "Li Yufan" << endl;
	if (v1 != -1 && v2 != -1){
		Edge* p = NodeTable[v1].adj, * q = NULL, * s = p;
		while (p != NULL && p->dest != NodeTable[v2].start){q = p; p = p->link;}
		if (p != NULL) {   //�ҵ���ɾ��
			if (p == s) NodeTable[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else{//Ϊ�գ���û���ҵ���Ҫɾ���ı�
			//cout << "\tThere is no edge between two nodes." << endl;//�����û�б�
			return false;
		}
		//����ɾ���ĺ�������
		p = NodeTable[v2].adj; q = NULL; s = p;
		while (p->dest != NodeTable[v1].start){
			q = p; p = p->link;
		}
		if (p == s) NodeTable[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		cout << "Delete successfully." << endl;//ɾ���ɹ�
		return true;
	}
	else{
		cout << "Node error,deletion failed." << endl;//Ҫɾ��㲻���ڣ�ɾ��ʧ��
		return false;
	}
}









