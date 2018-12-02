#include"Graph.h"
#include<fstream>
#include<sstream>
#include <string>
//#include <time.h>

 Graph G;
 void main()
{
	ifstream rfile("input.txt");
	if (!rfile)
	{
		cout << "不可以打开文件" << endl;
		exit(1);
	}
	ofstream outfile;
	outfile.open("output.txt");
	if (!outfile)
	{
		cout << "不可以打开文件" << endl;
		exit(1);
	}
	int count = 0, count1 = 0;  //count为总的计算次数，count1为每次计算时的地铁线条数
	int ind,k = 3, p = 3;  //p代表顶点编号，k代表存入第k-2条地铁线，它们都从3开始计数
	Vertex s, e;
	Vertex t;
	rfile >> count;
	for (int i = 0;i < count;i++)  //读入起点和终点
	{
		rfile >> s.x >> s.y >> e.x >> e.y >> ind;
		s.num = 1; s.info = 1;
		e.num = 2; e.info = 2;
		G.InsertVertex(s);
		G.InsertVertex(e);
		rfile >> count1;
		for (int i = 0;i < count1;i++)  //读入地铁站点
		{
			while (rfile >> t.x >> t.y && t.x != -1 && t.y != -1)
			{
				t.info = k;
				t.num = p++;
				G.InsertVertex(t);  //往图中加入顶点
			}
			k++;
		}
		G.CreateMGraph(ind);  //构建邻接矩阵
		double result = G.ShortestPath(s, e);  //计算最短路径
		outfile << round(result) << endl;  //用round函数进行四舍五入的取整
		p = 3, k = 3;
		G.clear();
	}
	G.clear();
	rfile.close();
	outfile.close();
	//cout << 1.0*(time2 - time1) / CLOCKS_PER_SEC << endl;
}	

