#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "vectorOperations.h"
#include "city.h"

int main() {

	std::vector<std::vector<int>> matrix = { {1, 4}, {2, 5}, {3, 6} };
	std::vector <int> vec1 = { 1, 2, 3 };
	std::vector <int> vec2 = { 2, 2, 2 };

	//1.1
	std::cout << "Scalar product of vec1 and vec2 = " << scalarProduct(vec1, vec2) << "\n";

	//1.2
	std::cout << "Vec2 multiplicate matrix: ";
	for (int el : vecMultiMatrix(vec2, matrix)) {
		std::cout << el << " ";
	}
	std::cout << "\n";

	//2
	std::vector<City> cities1 = readTxtFile("cities1.txt");
	std::vector<City> cities2 = readTxtFile("cities2.txt");
	std::vector<City> cities3 = readTxtFile("cities3.txt");


	cities1.insert(cities1.begin(), cities2.begin(), cities2.end());
	cities1.insert(cities1.end(), cities3.begin(), cities3.end());

	std::sort(cities1.begin(), cities1.end(), [](const City& a, const City& b) {
		return a < b;
		});

	std::vector<City> ukraine;
	std::vector<City> poland;
	std::vector<City> france;
	std::vector<City> usa;
	std::vector<City> spain;

	for (City city : cities1) {
		if (city.getCityCountry() == "Ukraine") {
			ukraine.push_back(city);
		}
		else if (city.getCityCountry() == "Poland") {
			poland.push_back(city);
		}
		else if (city.getCityCountry() == "France") {
			france.push_back(city);
		}
		else if (city.getCityCountry() == "USA") {
			usa.push_back(city);
		}
		else if (city.getCityCountry() == "Spain") {
			spain.push_back(city);
		}
	}

	int totalPopulation = 0;

	printCitiesByCountryAndCountPopulation(totalPopulation, ukraine);
	printCitiesByCountryAndCountPopulation(totalPopulation, poland);
	printCitiesByCountryAndCountPopulation(totalPopulation, france);
	printCitiesByCountryAndCountPopulation(totalPopulation, usa);
	printCitiesByCountryAndCountPopulation(totalPopulation, spain);



	std::cout << "\n\n\nTotal Population = " << totalPopulation << "\n";

	


	system("pause");
	return 0;
}


