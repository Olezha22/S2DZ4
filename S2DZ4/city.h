#pragma once
#include <iostream>
#include <string>
#include <vector>


class City
{
private:
	std::string city_name;
	std::string city_country;
	int city_population;
public:
	City();
	City(std::string name, std::string country, int population);
	City(const City& C);
	~City();


	std::string getCityName() const;
	std::string getCityCountry() const;
	int getCityPopulation() const;


	void readFrom(std::istream& is);
	void writeTo(std::ostream& os) const;


	bool operator<(const City& C) const;
	bool operator>(const City& C) const;
	bool operator==(const City& C) const;
};

std::istream& operator>>(std::istream& is, City& C);
std::ostream& operator<<(std::ostream& os, const City& C);


std::vector<City> readTxtFile(const std::string& name);
void printCitiesByCountryAndCountPopulation(int& totalPopulation, std::vector<City> country);