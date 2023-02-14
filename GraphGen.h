#pragma once
#include<vector>
#include<string>
#include <random>
#include <chrono>
#include<algorithm>


struct Graph
{
	int seed;
	std::vector<std::vector<int>> mtx;
};

auto genTree(int minG = 0, int maxG = 1e7, int seed = std::chrono::steady_clock::now().time_since_epoch().count()/*, std::string add = ""*/) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	std::vector<int> ans;
	ans.push_back(-1);
	std::vector<std::vector<int>> ans2(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	for (unsigned long long i = 1; i < v; i++) 
		ans.push_back(a() % i);
	for (unsigned long long i = 0; i < ans.size(); i++)
		if (ans[i] != -1)
			ans2[i][ans[i]] = ans2[ans[i]][i] = 1;
	Ans.mtx = ans2;
	return Ans;

}
auto genRegul(int minG = 0, int maxG = 1e7, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) { //NotWorked
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<int> g(v);
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	for (int i = 0; i < d - d % 2; i++) {
		std::vector<int> g(v);
		for (int i = 0; i < v; i++)
			g[i] = i;
		for (int i = 0; i < v; i++) {
			int z;
			int r = a() % v;
			z = g[i];
			g[i] = g[r];
			g[r] = z;
		}
		while (g.size() >= 2) {
			int rs = g[g.size() - 1], re = g[g.size() - 2];
			if (ans[rs][re] == 0) {
				g.pop_back();
				g.pop_back();
				ans[rs][re] = 1;
				ans[re][rs] = 1;
			}
			else {
				for (int i = 0; i < g.size(); i++)
				{
					int z;
					int r = a() % g.size();
					z = g[i];
					g[i] = g[r];
					g[r] = z;
				}
			}
		}
	}
	Graph Ans;
	Ans.seed = seed;
	Ans.mtx = ans;
	return Ans;
}

auto genGraph(int minG, int maxG = 1e9, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	maxS = (maxS > (v * (v - 1)) / 2 ? (v * (v - 1)) / 2 : v);
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	for (int i = 0; i < d; i++) {
		int q = a() % v, w = a() % v;
		if (q == w)i--;
		else if (ans[q][w] == 1)i--;
		else ans[q][w] = ans[w][q] = 1;
		
	}
	Graph Ans;
	Ans.seed = seed;
	Ans.mtx = ans;
	return Ans;
}