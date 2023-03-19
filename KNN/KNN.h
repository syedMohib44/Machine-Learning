#pragma once
#ifndef BLOGS_KNN_H
#define BLOGS_KNN_H
#endif //BLOGS_KNN_H
#include <vector>
#include "Dataset.h"

class Knn {

public:
	Knn() = default;
	void Fit(Dataset &data);
	int Predict(std::vector<float>,int k);
	std::vector<std::pair<std::vector<float>,int>> Neighbors;



private:
	Dataset Data;
	float euclideanDistance(std::vector<float> x, std::vector<float> y);


};