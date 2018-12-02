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
		cout << "�����Դ��ļ�" << endl;
		exit(1);
	}
	ofstream outfile;
	outfile.open("output.txt");
	if (!outfile)
	{
		cout << "�����Դ��ļ�" << endl;
		exit(1);
	}
	int count = 0, count1 = 0;  //countΪ�ܵļ��������count1Ϊÿ�μ���ʱ�ĵ���������
	int ind,k = 3, p = 3;  //p�������ţ�k��������k-2�������ߣ����Ƕ���3��ʼ����
	Vertex s, e;
	Vertex t;
	rfile >> count;
	for (int i = 0;i < count;i++)  //���������յ�
	{
		rfile >> s.x >> s.y >> e.x >> e.y >> ind;
		s.num = 1; s.info = 1;
		e.num = 2; e.info = 2;
		G.InsertVertex(s);
		G.InsertVertex(e);
		rfile >> count1;
		for (int i = 0;i < count1;i++)  //�������վ��
		{
			while (rfile >> t.x >> t.y && t.x != -1 && t.y != -1)
			{
				t.info = k;
				t.num = p++;
				G.InsertVertex(t);  //��ͼ�м��붥��
			}
			k++;
		}
		G.CreateMGraph(ind);  //�����ڽӾ���
		double result = G.ShortestPath(s, e);  //�������·��
		outfile << round(result) << endl;  //��round�����������������ȡ��
		p = 3, k = 3;
		G.clear();
	}
	G.clear();
	rfile.close();
	outfile.close();
	//cout << 1.0*(time2 - time1) / CLOCKS_PER_SEC << endl;
}	

