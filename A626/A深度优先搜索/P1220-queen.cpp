#include<iostream>
using namespace std;
int arr[10][10];				//用于存储棋盘以及之后的皇后摆放位置
int ans;						//存储最后的答案
bool judge(int x, int y)		//用于判断这个地方能否放置皇后
{
	int i, j;
	for (j = 1; j <= 8; j++)
	{
		if (arr[j][y])			return false;
	}
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			if (abs(x - i) == abs(y - j) && arr[i][j] == 1)		return false;
		}
	}
	return true;
}
void dfs(int v)					//深搜，这个函数可以理解为前面v-1个皇后已经摆放好，现在摆放第v个皇后，这里的v也代表第v行
{
	if (v > 8)					//深搜结束的条件，即当要摆放的皇后超过八个的时候，就说明前面八个皇后已经摆放完成，就可以结束深搜了
	{
		ans++;					//说明找到了一种摆放的方式，答案++
		return;
	}

	//棋盘上未摆放皇后的位置为0，摆放皇后的位置为1.
	//现在我们要摆放第v行上的皇后，那么我们就要遍历第v行上的所有位置，看看每个位置能不能放
	//由于本题给定的条件是初始情况下有的皇后已经摆放好了
	//所以我们要首先遍历这一行上是否已经有摆放好的皇后，如果有，flag为0，没有的话flag就为1
	int i, j, flag = 1;							
	for (i = 1; i <= 8; i++)
	{
		if (arr[v][i])				
		{
			flag = 0;
			break;
		}
	}
	//如果第v行上没有已经摆放好的皇后，那么我们就进行下一步
	//遍历第v行上的每一个位置，判断该位置能不能摆放皇后
	//如果可以的话，那我们就让arr[v][i]=1，然后dfs（v+1），即摆放第v+1行的皇后
	if (flag)
	{
		for (i = 1; i <= 8; i++)
		{
			if (judge(v, i))
			{
				arr[v][i] = 1;
				dfs(v + 1);
				arr[v][i] = 0;			//注意回溯，因为本题求的是所有的摆放种数，所以当前位置摆放完以后，arr[v][i]要变为0，然后继续摆放下一个位置
			}
		}
	}
	//如果flag为0，那么代表第v行额皇后已经摆放好，我们就直接摆放下一行的皇后
	else
	{
		dfs(v + 1);
	}
}
int main()
{
	int i, j;
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(1);					//从第一行开始摆
	cout << ans << endl;
	return 0;
}
