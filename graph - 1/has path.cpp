#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define endl "\n" //delete if interactive
using namespace std;

void dfs(vector<vector<int>>&graph , int n , vector<bool>&visited , int sv)
{
	visited[sv] = true;

	for (int i = 0; i <= n ; i++)
		if (graph[sv][i] and !visited[i])
			dfs(graph, n, visited , i);
}
void solve()
{
	int v, e ;
	cin >> v >> e;

	vector<vector<int>> graph(v + 1, vector<int>(v + 1, 0));

	for (int i = 0 ; i < e  ; i++)
	{
		int s , e ;
		cin >> s >> e ;
		graph[s][e] = 1;
		graph[e][s] = 1;
	}
	vector<bool>visited(v + 1 , false);

	int a , b;
	cin >> a >> b;

	dfs(graph , v , visited , a);  // if they are connected , they have to be in same component

	if (visited[b])
		cout << "true";
	else
		cout << "false";

}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	solve();

	return 0;
}

