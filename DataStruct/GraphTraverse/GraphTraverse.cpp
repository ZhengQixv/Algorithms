//����ʵ��8_3
//ͼ�ı���(������Ⱥ͹������)
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

//�ڽӱ�Ľ���
void adjlist(V_node head[], int n, int m, int t)  //t��0��1ֵ�ֱ��ʾ��������ͼ,n=��������m=����
{
	int i, w = 1, v = 1;
	E_node *p;
	for (i = 1; i <= n; i++)       //�������ʼ��
	{
		head[i].link = NULL;
		head[i].vertex = i;   //������Ϣ��Ϊ������
	}
	i = 1;                    //����߼���
	while ((v > 0) && (w > 0) && i <= m)   //����㣨���յ㣩Ϊ0�������ߵ�����
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
			p = (E_node *)malloc(sizeof(E_node));  //�½����w
			p->adjvex = w;    //�յ�Ϊw�ı߽��������v������
			p->next = head[v].link;
			head[v].link = p;
			if (t == 0)        //����ͼ
			{
				p = (E_node *)malloc(sizeof(E_node));  //�����v
				p->adjvex = v;      //�յ�Ϊv�ı߽��������w������
				p->next = head[w].link;
				head[w].link = p;
			}
		}
		printf("Edge %d : (v%d,v%d)\n", i, v, w);  //�����i����
		i++;
	}
}

//����ڽӱ�
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

//DFS����(�ݹ�)
void dfs(int v, V_node head[])    //vΪ��ʼ���
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


//BFS����
void bfs(int v, V_node head[])  //ʹ�ö��еĹ����������
{
	E_node *p;
	int queue[Max];
	int front = 0, rear = 0, w;
	printf("[v%d]", v); visit[v] = 1;   //���ʳ�ʼ�㣬��v�ѷ���
	queue[rear++] = v;    //�������ջ

	while (front != rear)
	{
		w = queue[front++];  //���׳��ӣ�����w
		p = head[w].link;   //���붥��w�ڽӵĶ���
		while (p != NULL)
		{
			if (visit[p->adjvex] == 0)
			{
				printf("[v%d]", p->adjvex); visit[p->adjvex] = 1;
				queue[rear++] = p->adjvex;
			}
			p = p->next;  //����һ���ڽӶ���
		}
	}

	printf("\n");
}

void Init()
{
	for (int i = 1; i <= Max; i++)
		visit[i] = 0;
}

//������
void main()
{
	int n, m, t;

	while (1)
	{
		printf("\n 0: ����ͼ");
		printf("\n 1: ����ͼ");
		printf("\n 2: Exit");
		printf("\nPlease choose=>");
		scanf_s("%d", &t);
		switch (t)
		{
		case 0:
		case 1:
			printf("\n ������ͼ�Ķ�����n������m��");
			scanf_s("%d %d", &n, &m);
			printf("\n�ڽӱ�Ľ�����");
			adjlist(head, n, m, t);
			printf("\n����ڽӱ�: ");
			Print(head, n);

			Init();
			printf("\n�����������˳��: ");
			dfs(1, head);

			Init();
			printf("\n�����������˳��: ");
			bfs(1, head);
			break;
		default:
			return;
		}
	}
}
