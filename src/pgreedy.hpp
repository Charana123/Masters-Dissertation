#ifndef PGREEDY_H
#define PGREEDY_H

#include "ssc_utils.hpp"
#include <algorithm>
#include <random>
#include <map>
#include <chrono>

using namespace std;

struct ProgressiveGreedyInput
{
    Stream* stream;
    vector<int>* universe;
    int n;
    int m;
};

unordered_set<int>* progressive_greedy_naive(ProgressiveGreedyInput* pgin, int p);
#endif