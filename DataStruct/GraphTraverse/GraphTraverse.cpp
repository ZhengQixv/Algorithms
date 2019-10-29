//程序实例8_3
//图的遍历(深度优先和广度优先)
#include<stdio.h>
#include<stdlib.h>
#define Max 50

typedef struct e_node
{
	int adjvex;
	int weight;
	struct e_node *next;
}E_node;

typedef struct v_node
{
	int vertex;
	E_node *link;
}V_node;

V_node head[Max];
int visit[Max];

//邻接表的建立
void adjlist(V_node head[], int n, int m, int t)  //t的0、1值分别表示无向、有向图,n=顶点数，m=边数
{
	int i, w = 1, v = 1;
	E_node *p;
	for (i = 1; i <= n; i++)       //顶点结点初始化
	{
		head[i].link = NULL;
		head[i].vertex = i;   //顶点信息设为顶点编号
	}
	i = 1;                    //输入边计数
	while ((v > 0) && (w > 0) && i <= m)   //以起点（或终点）为0，结束边的输入
	{
		printf("Input Edge %d's start point : ", i);
		scanf_s("%d", &v);
		printf("==> end point : ");
		scanf_s("%d", &w);
		if ((v > n) || (w > n))
		{
			printf("Error! Input again.");
			continue;
		}
		if ((v > 0) && (w > 0))
		{
			p = (E_node *)malloc(sizeof(E_node));  //新结点存放w
			p->adjvex = w;    //终点为w的边结点链到第v个链表
			p->next = head[v].link;
			head[v].link = p;
			if (t == 0)        //无向图
			{
				p = (E_node *)malloc(sizeof(E_node));  //结点存放v
				p->adjvex = v;      //终点为v的边结点链到第w个链表
				p->next = head[w].link;
				head[w].link = p;
			}
		}
		printf("Edge %d : (v%d,v%d)\n", i, v, w);  //输出第i条边
		i++;
	}
}

//输出邻接表
void Print(V_node head[], int n)
{
	int i;
	E_node *p;
	for (i = 1; i <= n; i++)
	{
		printf("\nhead[%d]:", i);
		if (head[i].link)
		{
			p = head[i].link;
			while (p)
			{
				printf("[%d]", p->adjvex);
				p = p->next;
			}
			printf("\n");
		}
	}
}

//DFS遍历(递归)
void dfs(int v, V_node head[])    //v为开始结点
{
	E_node *p;
	visit[v] = 1;
	printf("[v%d]", v);
	p = head[v].link;
	while (p != NULL)
	{
		if (visit[p->adjvex] == 0)
			dfs(p->adjvex, head);
		p = p->next;
	}
	printf("\n");
}


//BFS遍历
void bfs(int v, V_node head[])  //使用队列的广度优先搜索
{
	E_node *p;
	int queue[Max];
	int front = 0, rear = 0, w;
	printf("[v%d]", v); visit[v] = 1;   //访问初始点，置v已访问
	queue[rear++] = v;    //并让其进栈

	while (front != rear)
	{
		w = queue[front++];  //队首出队，并送w
		p = head[w].link;   //找与顶点w邻接的顶点
		while (p != NULL)
		{
			if (visit[p->adjvex] == 0)
			{
				printf("[v%d]", p->adjvex); visit[p->adjvex] = 1;
				queue[rear++] = p->adjvex;
			}
			p = p->next;  //找下一个邻接顶点
		}
	}

	printf("\n");
}

void Init()
{
	for (int i = 1; i <= Max; i++)
		visit[i] = 0;
}

//主函数
void main()
{
	int n, m, t;

	while (1)
	{
		printf("\n 0: 无向图");
		printf("\n 1: 有向图");
		printf("\n 2: Exit");
		printf("\nPlease choose=>");
		scanf_s("%d", &t);
		switch (t)
		{
		case 0:
		case 1:
			printf("\n 请输入图的顶点数n、边数m：");
			scanf_s("%d %d", &n, &m);
			printf("\n邻接表的建立：");
			adjlist(head, n, m, t);
			printf("\n输出邻接表: ");
			Print(head, n);

			Init();
			printf("\n深度优先搜索顺序: ");
			dfs(1, head);

			Init();
			printf("\n广度优先搜索顺序: ");
			bfs(1, head);
			break;
		default:
			return;
		}
	}
}
