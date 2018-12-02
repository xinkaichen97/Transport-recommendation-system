#ifndef GUARD_PJ_H
#define GUARD_PJ_H
#define MAXINT 99999
#define VerticleMaxNumber 1000
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Vertex
{
public:
	//�������Ϣ��1��2��ʾ�����յ㣬i(i>2)��ʾ�õ����ڵ�i-2��������
	int info;  
    //������
	int num;  
	//���������
	double x;  
	//����������
	double y;  
};

class Graph
{
private:
	int vexsnum;  //��Ŷ�����
	int linesnum;  //�����ߵ�����
	Vertex vexs[VerticleMaxNumber];  //��Ŷ���
	double Cost[VerticleMaxNumber][VerticleMaxNumber];  //�ڽӾ���
	double Dist[VerticleMaxNumber];  //��ŴӶ���0����������������·������
	int Pre[VerticleMaxNumber];  //��������·���ϸö����ǰһ����Ķ����
    int S[VerticleMaxNumber];  //����õ������·���ϵĶ���Ķ����
public:
	Graph();
	void clear();
	double ShortestPath(Vertex s, Vertex e);  //�����·��
	void InsertVertex(Vertex v);  //��ͼ����Ӷ���
	double MT_Distance(Vertex s, Vertex e);  //minimum time distance ��Сʱ��ľ���
	double SW_Distance(Vertex s, Vertex e);  //shortest walking distance ��̲��о���
	//double SL_Distance(Vertex s, Vertex e); //straight line distance �����ֱ�߾���
	void CreateMGraph(int ind);  //�����ڽӾ���
};

#endif	