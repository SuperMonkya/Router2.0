#include"insert_node.h"

bool Graphcnt::insertnode(){//插入一个结点
	ifstream fin("data1.txt", std::ios::in);
	char line[1024] = { 0 };
	numnode = 0;
	string x = "";
	while (fin.getline(line, sizeof(line)))
	{
		stringstream word(line);
		word >> x;
		NodeTable[numnode].start = x;
		numnode++;
	}

	fin.clear();    //清除缓冲区（文件多次读入）
	fin.close();
	cout << "Node inserted successfully!!" << endl;
	return true;
};
