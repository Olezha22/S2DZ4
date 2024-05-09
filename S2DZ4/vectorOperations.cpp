#include "vectorOperations.h"
#include <vector>

int scalarProduct(const std::vector <int> vec1, const std::vector <int> vec2) {
	int product = 0;

	for (size_t i = 0; i < vec1.size(); ++i) {
		product += vec1[i] * vec2[i];
	}

	/* ³íøèé âàð³àíò ðåàë³çàö³¿
	std::vector<int>::const_iterator it1 = vec1.begin();
	std::vector<int>::const_iterator it2 = vec2.begin();
	while (it1 != vec1.end()) {
		product += (*it1) * (*it2);
		++it1;
		++it2;
	}*/

	return product;
}

std::vector<int> vecMultiMatrix(const std::vector<int> v, const std::vector<std::vector<int>> matrix) {
	std::vector<int> result(matrix[0].size(), 0);
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix[i].size(); ++j) {
			result[j] += v[i] * matrix[i][j];
		}
	}
	/* ³íøèé âàð³àíò ðåàë³çàö³¿
	size_t i = 0;
	while (i < matrix.size()) {
		size_t j = 0;
		while (j < matrix[i].size()) {
			result[j] += v[i] * matrix[i][j];
			++j;
		}
		++i;
	}*/
	return result;
}