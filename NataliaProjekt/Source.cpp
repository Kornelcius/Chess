#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <random>

#include "genetic_algorithm.h"

using std::cout;
using std::endl;

int main() {

	matrix distance;
	distance = read_matrix_from_file("matrix.txt");

	vector<string> city_names;
	int route = 10;
	city_names = read_city_names("matrix.txt");
	int number_of_cities = city_names.size();

	vector<vector<int>> population = initPath(route, number_of_cities);
	for (int i = 0; i < population.size(); i++) {
		for (int j = 0; j < population[i].size(); j++)
		{
			cout << population[i][j] << " ";
		}
		cout << endl;
	}
	vector<double> route_length;
	for (int i = 0; i < route; i++) {
		route_length.push_back(fitness(population[i], distance));
	}

	for (int i = 0; i < route_length.size(); i++) {

		cout << route_length[i] << endl;
	}

}
