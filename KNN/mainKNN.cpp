//https://medium.com/hacettepeaiclub/k-nn-classification-in-c-1f8e6b16be25#:~:text=Save-,K%2DNN%20Classification%20in%20C%2B%2B,K'%20points%20in%20the%20dataset.
#include <iostream>
#include "Dataset.h"
#include "Knn.h"
int main()
{

    Dataset randomized_data(100, 3);
    randomized_data.Print();

    //Create a 2d vector a get prediction
    std::vector<float> value;
    value.push_back(.3f);
    value.push_back(.8f);

    Knn knn = Knn();
    knn.Fit(randomized_data);
    int prediction = knn.Predict(value, 7);

    for (size_t i = 0; i < knn.Neighbors.size(); i++)
    {
        std::cout << knn.Neighbors.at(i).first.at(0) << "   " << knn.Neighbors.at(i).first.at(1) << std::endl;
        std::cout << knn.Neighbors.at(i).second << std::endl;
    }
    std::cout << "Labl:" << prediction;
}