#pragma once
#ifndef BLOGS_DATASET_H
#define BLOGS_DATASET_H
#include <ctime>

#endif //BLOGS_DATASET_H
#include <iostream>
#include <vector>
class Dataset {

public:
	//n: input size
	//l: class size
	//Create n floats between 0 and 1. And assign them random labels.
	Dataset() = default;
	Dataset(int n, int l) {
		//call this before getting random values or rand() function could return 
		//same sequence of numbers each time.
		srand(time(NULL));
		for (int i = 0; i < n; ++i) {
			float randX = static_cast <float>(rand() / static_cast <float>(RAND_MAX + 1));
			float randY = static_cast <float>(rand() / static_cast <float>(RAND_MAX + 1));
			Data.push_back(std::vector<float>());
			Data.at(i).push_back(randX);
			Data.at(i).push_back(randY);
			Labels.push_back(rand() % l);
		}
	}

	std::vector<std::vector<float>> GetData();
	std::vector<int> GetLabels();
	void Print();
private:
	std::vector<std::vector<float>> Data;
	std::vector<int> Labels;

};