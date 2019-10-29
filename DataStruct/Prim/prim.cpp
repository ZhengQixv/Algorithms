//程序实例8_4
//Prim算法求最小生成树
#include<stdio.h>
#define I 9999
#define Max 100

void prim(int cost[][7], int n, int v)  //cost[][7]
{
	int lowcost[Max], min;
	int closest[Max], i, j, k;
	for (i = 1; i <= n; i++)   //先将顶点v放入U中
	{
		lowcost[i] = cost[v - 1][i - 1];	closest[i] = v;
	}
	for (i = 1; i < n; i++)  //在V-U中找出离v最近的顶点,进行n-1次
	{
		min = I;
		for (j = 1; j <= n; j++)
			if ((lowcost[j] != 0) && (lowcost[j] < min))
			{
				min = lowcost[j];	k = j;
			}
		printf("E:(%d,%d),W:%d\n", closest[k], k, min);
		lowcost[k] = 0;     //标记k已加入U
		for (j = 1; j <= n; j++)   //修改数组lowcost和closest
			if ((cost[k - 1][j - 1] != 0) && (cost[k - 1][j - 1] < lowcost[j]))
			{
				lowcost[j] = cost[k - 1][j - 1];
				closest[j] = k;
			}
	}
}
//主函数
void main()
{
	//图8.4.2
	int cost[][7] = { {0,5,2,20,I,15,I},	{5,0,I,3,8,I,6},
					{2,I,0,I,I,25,I},	{20,3,I,0,I,14,16},
					{I,8,I,I,0,I,12},	{15,I,25,14,I,0,10},
					{I,6,I,16,12,10,0} };

	/*int cost[][7]={{0,15,2,8,I,I,I},	{15,0,I,18,7,I,3},
					{2,I,0,6,I,12,I},	{8,18,6,0,I,4,11},
					{I,7,I,I,0,I,5},	{I,I,12,4,I,0,14},
					{I,3,I,11,5,14,0}};*/

					/*int cost[][7]={{0,12,6,8,I,I,I},	{12,0,I,15,13,I,I},
									{6,I,0,4,I,12,I},	{8,15,4,0,16,9,20},
									{I,13,I,16,0,I,10},	{I,I,12,9,I,0,5},
									{I,I,I,20,10,5,0}};*/

	prim(cost, 7, 1);
	while (1) {}
}
