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
	srand(time(NULL));

	matrix distance;
	distance = read_matrix_from_file("matrix.txt");

	vector<string> city_names;
	int route = 20;
	city_names = read_city_names("matrix.txt");
	int number_of_cities = city_names.size();

	vector<vector<int>> population = initPath(route, number_of_cities); //wielkoœæ populacji poczatkowej, iloœæ miast ogó³em
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

		cout << route_length.at(i) << endl;
	}



	//selekcja turniejowa
	vector<vector<int>> winners;

		while (winners.size() != population.size()) {
			auto chosen = tournament_selection(population, 2);
			int indexOfFirstChosen = chosen.at(0);
			int indexOfSecondChosen = chosen.at(1);

			auto fit1 = route_length.at(indexOfFirstChosen);
			auto fit2 = route_length.at(indexOfSecondChosen);
			vector<int> chosenGenome;
			if (!(fit1 > 1000000 && fit2 > 1000000)) {

				if (fit1 < fit2) {
					chosenGenome = population.at(indexOfFirstChosen);
				}
				else {
					chosenGenome = population.at(indexOfSecondChosen);
				}
				winners.push_back(chosenGenome);
			}
		}
	
	std::cout << "Winners: " << std::endl;
	for (auto i : winners) {
		for (auto j : i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}


	//krzy¿owanie

}
