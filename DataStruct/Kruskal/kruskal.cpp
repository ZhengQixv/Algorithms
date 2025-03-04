//程序实例8_5
//克鲁斯卡尔算法计算最小生成树
#include<stdio.h>
#define Max 20
typedef struct edge
{
	int u, v, w;
} Edge;  //边上的两个端点u,v，边上的权w

//求顶点v所在连通分量的最后一个顶点
int seeks(int set[], int v)
{
	int i = v;
	while (set[i] > 0)	i = set[i];
	return i;
}

void kruskal(Edge E[], int n, int e)
{
	int set[Max], v1, v2, i, j;
	//初时，每个顶点是一连通分量，即顶点i是连通分量的最后一个顶点
	for (i = 1; i <= n; i++)
		set[i] = 0;
	i = 0;     //选取的边在E[]中的下标
	j = 0;     //T中已生成的边记数

	while (j < n && i < e)          //判断顶点u,v是否属于同一连通分量	
	{
		v1 = seeks(set, E[i].u);
		v2 = seeks(set, E[i].v);
		if (v1 != v2)
		{
			printf("(%d,%d,%d)\n", E[i].u, E[i].v, E[i].w);
			set[v1] = v2;     //合成一个连通分量
			j++;            //T的边数加1
		}
		i++;               //选取E[]中下一条边
	}
}

void main()
{
	//图8.4.4
	Edge E[] = { {1,3,2},{2,7,3},{4,6,4},
				{5,7,5},{3,4,6},{2,5,7},
				{1,4,8},{4,7,11},{3,6,12},
				{6,7,14},{1,2,15},{2,4,18} };
	//T8.3
	/*Edge E[]={{3,4,4},{6,7,5},{1,3,6},
				{1,4,8},{4,6,9},{5,7,10},
				{1,2,12},{3,6,12},{2,5,13},
				{2,4,15},{4,5,16},{4,7,20}};*/

				/*Edge E[]={{2,3,5},{2,4,6},{3,4,10},
							{2,6,11},{4,6,14},{1,2,16},
							{4,5,18},{1,5,19},{1,6,21},
							{5,6,33}};*/

	kruskal(E, 7, 12);
	while (1) {}
}
