#include "genetic_algorithm.h"
#include <ctime>
#include "windows.h"

matrix read_matrix_from_file(const string& filename) {

	matrix distance;
	std::ifstream matrix_file;
	string row;
	double i;
	vector<string> cities;
	matrix_file.open(filename);
	if (matrix_file.is_open()) {

		getline(matrix_file, row); //odczytanie pierwszego wiersza, aby go pomin��

		while (getline(matrix_file, row)) {

			std::istringstream iss(row);
			vector<double> rows;
			while (iss >> i)
			{
				rows.push_back(i);
			}
			if (distance.size() == 0 || distance[0].size() == rows.size())
			{
				distance.push_back(rows);
			}
		}
	}
	matrix_file.close();
	return distance;
}
vector<string> read_city_names(const string& FileName) {

	vector<string> city_names;
	std::ifstream matrix_file;
	matrix_file.open(FileName);
	if (matrix_file.is_open()) {
		string f;
		string line;
		getline(matrix_file, line);
		std::istringstream fin(line);
		while (fin >> f) {
			city_names.push_back(f);//loop till end of line
		}
	}
	matrix_file.close();

	return city_names;
}

vector<vector<int>> initPath(int route, int city_number) {

	vector<vector<int>> population(route, vector<int>(city_number));

	std::default_random_engine generator(std::random_device{}());

	int city;
	for (int i = 0; i < route; i++) {

		vector<int> place;
		for (int k = 0; k < city_number; k++) {
			place.push_back(k);
		}

		int s = city_number;
		for (int j = 0; j < city_number; j++) {


			std::uniform_int_distribution<int> distribution(0, s - 1);

			city = distribution(generator);
			population[i][j] = place[city];

			int temp = place[s - 1];
			place[city] = temp;
			place.pop_back();
			s = s - 1;
		}
	}
	return population;
}

double fitness(vector<int> route, matrix distance) {

	int s = route.size();

	int length_of_the_route = 0;
	for (int i = 1; i < s; i++) {
		if (distance[i - 1][i] != -1) { distance[i - 1][i] == 1000000; }
		length_of_the_route += distance[route[i - 1]][route[i]];
	}
	if (distance[route[s - 1]][route[0]] != -1) { distance[route[s - 1]][route[0]] == 1000000; }
	length_of_the_route += distance[route[s - 1]][route[0]];

	return length_of_the_route;
}

vector<unsigned> tournament_selection(vector<vector<int>> population, int k) {
	const unsigned range = population.at(0).size();
	const unsigned numberToSelect = k;
	std::vector< unsigned > chosenNumbers(numberToSelect);

	if (numberToSelect > range)
	{
		return chosenNumbers;
	}
	std::vector< unsigned > remainingNumbers(range);

	/* Initialise the list of possible choices */
	for (unsigned i = 0; i < range; i++)   remainingNumbers[i] = i;

	/* Now chose however many you want, without repeats */
	for (unsigned i = 0; i < numberToSelect; i++) {
		/* Generate a random number to select */

		Sleep(10);
		int selectedElement = rand() % (range - i);
		Sleep(10);
		/* Put it in the chosenNumbers vector */
		chosenNumbers[i] = remainingNumbers[selectedElement];

		/* Now erase this number from the possible numbers, so that it can't be chosen again */
		remainingNumbers.erase(remainingNumbers.begin() + selectedElement);
	}
	return chosenNumbers;
}
