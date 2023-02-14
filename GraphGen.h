#pragma once
#include<vector>
#include<string>
#include <random>
#include <chrono>
#include<algorithm>
#include<iostream>


struct Graph
{
	int seed, e, v;
	std::vector<std::vector<int>> mtx;
	std::vector<std::pair<int, int>> edges;
};

auto genTree(int minG = 0, int maxG = 1e7, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
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
		if (ans[i] != -1) {
			ans2[i][ans[i]] = ans2[ans[i]][i] = 1;
			Ans.edges.emplace_back(i, ans[i]);
		}
	Ans.mtx = ans2;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genGraph(int minG = 0, int maxG = 1e9, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	maxS = (maxS > (v * (v - 1)) / 2 ? (v * (v - 1)) / 2 : maxS);
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	for (int i = 0; i < d; i++) {
		int q = a() % v, w = a() % v;
		if (q == w)i--;
		else if (ans[q][w] == 1)i--;
		else {
			ans[q][w] = ans[w][q] = 1;
			Ans.edges.emplace_back(q, w);
		}
	}
	Ans.seed = seed;
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}

auto genMulti(int minG = 0, int maxG = 1e9, int minS = 0, int maxS = 1e5, int seed = std::chrono::steady_clock::now().time_since_epoch().count()) {
	std::mt19937 a(seed);
	long long v = a() % (maxG - minG + 1) + minG;
	long long d = a() % (maxS - minS + 1) + minS;
	std::vector<std::vector<int>> ans(v, std::vector<int>(v, 0));
	Graph Ans;
	Ans.seed = seed;
	if(v!=1)
	for (int i = 0; i < d; i++) {
		int q = a() % v, w = a() % v;
		if (q == w)i--;
		else {
			ans[q][w] = ans[w][q] = ans[w][q] + 1;
			Ans.edges.emplace_back(q, w);
		}
	}
	Ans.mtx = ans;
	Ans.v = v;
	Ans.e = Ans.edges.size();
	return Ans;
}