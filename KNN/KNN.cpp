#include "Knn.h"
#include <algorithm>
#include <map>

int find_max(std::map<int, int> counts);

void  Knn::Fit(Dataset &data)
{
	this->Data = data;
}
int  Knn::Predict(std::vector<float> val,int k)
{
	/*
	 * Neighbors: Holds the closest k points after calling prediction
	 * counts:Keeps the label,labelCount pair. is a map
	 * Points: Keeps all points as a float,vector(float) pair. First one is distance
	 * of our value to the 'point' in the dataset, which is also second parameter.
	 * distances: vector of float,int pair which holds distance and label values.
	 * it is used to keep integration with the Points vector.
	 */
	float min = RAND_MAX;
	std::vector<std::pair<float, std::vector<float>>> Points;
	Neighbors.clear();
	std::vector<std::pair<float, int>> distances;

	for (size_t i = 0; i < Data.GetData().size(); ++i)
	{
		std::vector<float> currentPoint = Data.GetData().at(i);
		float dist = euclideanDistance(val, currentPoint);
		int lbl= Data.GetLabels().at(i);

		distances.push_back(std::pair<float, int>(dist,lbl));
		Points.push_back(std::pair<float, std::vector<float>>(dist, currentPoint));

	}
	//Sort vectors by distance.
	std::sort(distances.begin(), distances.end());
	std::sort(Points.begin(), Points.end());

	std::map<int,int> counts;

	for (int i = 0; i < k; i++)
	{
		int lbl = distances.at(i).second;
		Neighbors.push_back(std::pair<std::vector<float>, int>(Points.at(i).second,lbl));

		if (!counts.count(lbl))
			counts.insert(std::pair<int, int>(lbl, 1));
		else
			counts[lbl]++;
	}
	return find_max(counts);
	

}
//our distance function
//TODO:Add different distace functions like Manhattan distance. Each distance function has a specific use.
float  Knn::euclideanDistance(std::vector<float> x, std::vector<float> y) {
	return  std::sqrt(std::pow(x.at(0)-y.at(0),2)+ std::pow(x.at(1) - y.at(1), 2));
}

//find the actual label by extracting the label from the map with biggest value.
int find_max(std::map<int, int> counts)
{
	std::map<int, int>::iterator itr;
	int max = -1;
	int lbl = 0;
	for (itr = counts.begin(); itr != counts.end(); ++itr) {
		if (itr->second > max)
		{
			max = itr->second;
			lbl = itr->first;
		}
	}
	return lbl;
}