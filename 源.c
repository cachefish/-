#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int VType;
typedef int EType;
#define VSIZE 100
#define  QUEUESIZE 100
#define ERROR 1
#define OK  0
typedef struct AdjMGraph
{
	VType vexs[VSIZE];		//顶点数组
	EType arc[VSIZE][VSIZE];	//边弧数组
	int VNum;	//顶点个数
	int ENum;	//边弧个数
}AdjMGraph;
typedef int DataType;
typedef struct Queue {
	DataType data[QUEUESIZE];
	int front;
	int rear;
}Queue;

void initQueue(Queue* q)		//初始化队
{
	q->front = 0;
	q->rear = 0;
}
bool queueEmpty(Queue* q)
{
	return q->front == q->rear;
}
bool queuefull(Queue* q)		//判断队空
{
	return q->front == (q->rear + 1) % QUEUESIZE;
}

int enQueue(Queue* q, DataType e)		//入队
{
	if (queuefull(q))
		return ERROR;
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % QUEUESIZE;
}
int dequeue(Queue* q, DataType *e)		//出队
{
	if (queueEmpty(q))
		return ERROR;
	*e = q->data[q->front];
	q->front = (q->front + 1) % QUEUESIZE;
	return OK;
}



void createdAdjMGraph(AdjMGraph* g)
{
	printf("输入顶点的个数：");
	scanf_s("%d",&g->VNum);
	printf("输入边弧的个数：");
	scanf_s("%d", &g->ENum);
	for (int i = 0; i < g->VNum; i++)
		scanf_s("%d", &g->vexs[i]);		//顶点名称
	for (int i = 0; i < g->VNum; i++)
		for (int j = 0; j < g->VNum; j++)
			g->arc[i][j] = 0;  //边弧初始化
	for (int k = 0; k < g->ENum; k++)
	{
		printf("输入边(vi,vj)下标i,j:");
		int i, j;
		scanf_s("%d %d", &i, &j);
		g->arc[i][j] = g->arc[j][i] = 1;
	}
}

void print(VType t)
{
	printf("%d", t);
}
int BFSTraverse(AdjMGraph g,void(*visitFunc)(VType))
{
	int visited[VSIZE];
	for (int i = 0; i < g.VNum; i++)
	{
		visited[i] = 0;
	}
	Queue q;
	initQueue(&q);
	for (int i = 0; i < g.VNum; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			visitFunc(g.vexs[i]);
			enQueue(&q, i);
			while (queueEmpty(&q) == 0)  //判断队列为空
			{
				dequeue(&q, &i);
				for (int j = 0; j < g.VNum; j++)
				{
					if (g.arc[i][j] == 1 && visited[j] == 0)
					{
						visited[j]= 1;
						visitFunc(g.vexs[j]);
						enQueue(&q, j);
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	AdjMGraph g;
	createdAdjMGraph(&g);
	BFSTraverse(g, print);
}

