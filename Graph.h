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
	//顶点的信息，1和2表示起点和终点，i(i>2)表示该点属于第i-2条地铁线
	int info;  
    //顶点编号
	int num;  
	//顶点横坐标
	double x;  
	//顶点纵坐标
	double y;  
};

class Graph
{
private:
	int vexsnum;  //存放顶点数
	int linesnum;  //地铁线的数量
	Vertex vexs[VerticleMaxNumber];  //存放顶点
	double Cost[VerticleMaxNumber][VerticleMaxNumber];  //邻接矩阵
	double Dist[VerticleMaxNumber];  //存放从顶点0到其它各顶点的最短路径长度
	int Pre[VerticleMaxNumber];  //存放在最短路径上该顶点的前一顶点的顶点号
    int S[VerticleMaxNumber];  //已求得的在最短路径上的顶点的顶点号
public:
	Graph();
	void clear();
	double ShortestPath(Vertex s, Vertex e);  //求最短路径
	void InsertVertex(Vertex v);  //往图中添加顶点
	double MT_Distance(Vertex s, Vertex e);  //minimum time distance 最小时间的距离
	double SW_Distance(Vertex s, Vertex e);  //shortest walking distance 最短步行距离
	//double SL_Distance(Vertex s, Vertex e); //straight line distance 两点间直线距离
	void CreateMGraph(int ind);  //创建邻接矩阵
};

#endif	