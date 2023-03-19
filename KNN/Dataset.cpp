#include "Dataset.h"

std::vector<std::vector<float>> Dataset::GetData()
{
	return Data;
}
std::vector<int> Dataset::GetLabels()
{
	return Labels;
}
void Dataset::Print()
{
	for (size_t i = 0; i < Data.size(); i++) {
		std::cout << "x:" << Data.at(i).at(0) << +" y:" << Data.at(i).at(1) << " " << Labels.at(i) << std::endl;
	}
}