//https://www.nowcoder.com/pat/6/problem/4061
//这道题数据有问题 没啥参考价值 还是多看看模板
#include <bits/stdc++.h>
using namespace std;

int n, flag;
int ins[101], mer[101], a[101];
//ins进行插入排序, mer进行归并排序, a为排序后某一轮的数组

bool check(int tmp[], string s)
{
	int _flag = 1;
	if(flag)
	{
		cout << s << endl;
		for(int i = 1; i <= n; ++i) cout << tmp[i] << " ";
		return 1;
	}
	for(int i = 1; i <= n; ++i)
		if(tmp[i] != a[i]) _flag = 0;
	flag = _flag;
	return 0;
}

void insert_sort()
{
	int i = 2;
	while(a[i] >= a[i - 1]) i++;
	int now = a[i];
	for(int j = i; j >= 1; --j)
	{
		if(a[j - 1] >= now) a[j] = a[j - 1];
		else
		{
			a[j] = now;
			break;
		}
	}
	cout << "Insertion Sort" << endl;
	for(int i = 1; i <= n; ++i) cout << a[i] << " ";
}

void merge_sort()//归并排序（递推）
{
	int flag = 0, step = 1, begin, end;
	int b[101];//辅助数组
	do
	{
		for(begin = 1; begin <= n - 1; begin += step * 2)
		{
			end = begin + step * 2 - 1;
			if(end > n) end = n;
			int mid = (begin + end) / 2;
			int l = begin, r = mid + 1, k = begin;
			while(l <= mid && r <= end)
			{
				if(mer[l] <= mer[r]) b[k++] = mer[l++];
				else b[k++] = mer[r++];
			}
			while(l <= mid) b[k++] = mer[l++];
			while(r <= end) b[k++] = mer[r++];
			for(int i = begin; i <= end; ++i) mer[i] = b[i];
		}
		if(check(mer, "Merge Sort")) return;
		step *= 2;
	}while(step <= n);
}
/*
void insert_sort()//插入排序
{
	for(int i = 1; i <= n; ++i)
	{
		int now = ins[i];
		for(int j = i; j >= 1; --j)
		{
			if(ins[j - 1] >= now) ins[j] = ins[j - 1];
			else
			{
				ins[j] = now;
				break;
			}
		}
	}
}
void merge_sort(int begin, int end)//归并排序（递归）
{
	if(begin == end) return;
	int mid = (begin + end) / 2;
	merge_sort(begin, mid); merge_sort(mid + 1, end);
	int l = begin, r = mid + 1, k = begin;
	int b[101];
	while(l <= mid && r <= end)
	{
		if(mer[l] <= mer[r]) b[k++] = mer[l++];
		else b[k++] = mer[r++];
	}
	while(l <= mid) b[k++] = mer[l++];
	while(r <= end) b[k++] = mer[r++];
	for(int i = begin; i <= end; ++i) mer[i] = b[i];
}
*/
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> mer[i];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	merge_sort();
	if(!flag) insert_sort();
	return 0;
}
