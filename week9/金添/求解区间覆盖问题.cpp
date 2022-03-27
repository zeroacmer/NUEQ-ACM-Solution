#include <bits/stdc++.h>
using namespace std;
int interval[100];//记录区间
int gap[100];//记录区间的间隔
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>interval[i];
    }
    sort(interval,interval+n);//将区间长度从小到大排序
    int len=interval[n-1]-(interval[0]-1);//假设一条线段将所有区间全覆盖，然后再减去大的间隔即可；
    for(int i=0;i<n-1;i++)
    {
        gap[i]=interval[i+1]-(interval[i]+1);//计算每两个区间之间的间隔
    }    
    sort(gap,gap+n-1,cmp);//将区间间隔从大到小排序
    for(int i=0;i<=m-2;i++)//尽可能的删去大区间
    {
        len-=gap[i];
    }
    cout<<len;
    return 0;  
}



