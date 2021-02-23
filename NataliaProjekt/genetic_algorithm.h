#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <random>

using std::vector;
using std::string;
using std::cout;
using std::endl;

typedef vector<vector<double>> matrix;


matrix read_matrix_from_file(const string& filename);

vector<string> read_city_names(const string& FileName);

vector<vector<int>> initPath(int route, int city_number);

double fitness(vector<int> route, matrix distance);
vector<unsigned> tournament_selection(vector<vector<int>> population, int k);

