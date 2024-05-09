#include "city.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

City::City()
	: city_name(""), city_country(""), city_population(0)
{

}

City::City(std::string name, std::string country, int population)
	: city_name(name), city_country(country), city_population(population)
{

}

City::City(const City& C)
	: city_name(C.city_name), city_country(C.city_country), city_population(C.city_population)
{

}
City::~City()
{

}


std::string City::getCityName() const
{
	return city_name;
}
std::string City::getCityCountry() const
{
	return city_country;
}
int City::getCityPopulation() const 
{
	return city_population;
}


void City::readFrom(std::istream& is)
{
	is >> city_name >> city_country >> city_population;
}
void City::writeTo(std::ostream& os) const
{
	os << "City: name = " << city_name << ", country = " << city_country << ", population = " << city_population << "\n";
}


bool City::operator<(const City& C) const
{
	return city_population < C.city_population;
}
bool City::operator>(const City& C) const
{
	return city_population > C.city_population;
}
bool City::operator==(const City& C) const
{
	return city_population == C.city_population;
}


std::istream& operator>>(std::istream& is, City& C)
{
	C.readFrom(is);
	return is;
}
std::ostream& operator<<(std::ostream& os, const City& C)
{
	C.writeTo(os);
	return os;
}

std::vector<City> readTxtFile(const std::string& name) {
	size_t size;
	std::vector<City> cities;
	std::ifstream fin(name);

	fin >> size;

	for (size_t i = 0; i < size; i++)
	{
		City city;
		fin >> city;
		cities.push_back(city);
	}

	fin.close();
	return cities;
}

void printCitiesByCountryAndCountPopulation(int& totalPopulation, std::vector<City> country) {
	std::cout << "\n" << country[0].getCityCountry() << ":\n";
	for (City city : country) {
		std::cout << city;
		totalPopulation += city.getCityPopulation();
	}
}