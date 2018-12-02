#include "Graph.h"

const double man_v = 10;
const double sub_v = 40;

Graph::Graph()
{
	for (int i = 0;i < VerticleMaxNumber;i++)  //�ڽӾ����ʼ��
		for (int j = 0;j < VerticleMaxNumber;j++)
			Cost[i][j] = 0;
	for (int i = 0;i < VerticleMaxNumber;i++)  //Dist��Pre��S�����ʼ��
	{
		Dist[i] = 0;
		Pre[i] = 0;
		S[i] = 0;
	}
	memset(vexs, 0, sizeof(vexs));  //vexs�����ʼ��
	//�������Ͷ�������Ϊ0
	vexsnum = 0;
	linesnum = 0;  
}

void Graph::clear()
{
	memset(Dist, 0, sizeof(Dist));
	memset(Pre, 0, sizeof(Pre));
	memset(S, 0, sizeof(S));
	memset(Cost, 0, sizeof(Cost));
	memset(vexs, 0, sizeof(vexs));
	vexsnum = 0;
	linesnum = 0;
}

double Graph::ShortestPath(Vertex s, Vertex e)
{
	int i, j, k;
	int v = s.num;
	double min;
	for (i = 1;i <= vexsnum;i++)  //����Dist�����S����ĳ�ʼ��
	{
		Dist[i] = Cost[v][i];  
		S[i] = 0;
		if (Dist[i] < MAXINT)
			Pre[i] = v;
		else
			Pre[i] = 0;
	}
	S[v] = 1;
	Pre[v] = 0;
	for (i = 1; i <= vexsnum; i++)
	{  
		min = MAXINT;
		k = 0;
		for (j = 1; j <= vexsnum; j++)  //ѡ��ǰ���ڼ���S�о������·���Ķ���k
			if (S[j] == 0)
				if (Dist[j] != 0 && Dist[j] < min)
				{
					min = Dist[j];
					k = j;
				}
		if (k == 0)  break;  //�Ҳ����µ����·��
		S[k] = 1;   //������k����S���ϣ���ʾ���������·����
		for (j = 1; j <= vexsnum; j++)
			if (S[j] == 0 && Cost[k][j] < MAXINT)  //������ָ��̵�·���������޸�
				if (Dist[k] + Cost[k][j] < Dist[j])
				{
					Dist[j] = Dist[k] + Cost[k][j];
					Pre[j] = k;
				}
	}
	return Dist[e.num];  //����Dist������e�㵽Դ��s��ľ���
}

void Graph::InsertVertex(Vertex v)
{
	vexs[++vexsnum] = v;
	v.num = vexsnum;
}

double Graph::MT_Distance(Vertex s, Vertex e)
{
	double tempDist = 0;
	if (s.info == e.info)
	{
		if (s.info >= 3)
		{

			if (s.num - e.num == -1 )
				return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y)) / (sub_v / 3.6 * 60);
			else return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y)) / (man_v / 3.6 * 60);
		}
		else 
			return -1;
	}
	else
	{
		return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y))/ (man_v / 3.6 * 60);
		
	}
}

double Graph::SW_Distance(Vertex s, Vertex e)
{
	if (s.info >= 3 && e.info >= 3)
	{
		if (s.info == e.info)
			return 0;
		else return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y));
	}
	else
		return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y));
}

/*double Graph::SL_Distance(Vertex s, Vertex e)
{
	return sqrt((s.x - e.x)*(s.x - e.x) + (s.y - e.y)*(s.y - e.y));
}*/

void Graph::CreateMGraph(int ind) //����indicator��ȡֵ��������ͬ���ڽӾ���
{
	if (ind == 0)  //������Ӧʱ����̵��ڽӾ���
	{
		for (int i = 1;i <= vexsnum;i++)
			for (int j = 1;j < i;j++)
			{
				Cost[i][j] = Cost[j][i] = MT_Distance(vexs[j], vexs[i]);
			}
	}
	if (ind == 1)  //������Ӧ��̲��о�����ڽӾ���
	{
		for (int i = 1;i <= vexsnum;i++)
			for (int j = 1;j <i;j++)
			{
				Cost[i][j] = Cost[j][i] = SW_Distance(vexs[i], vexs[j]);
			}
	}
}