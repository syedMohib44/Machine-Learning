//https://github.com/yacineMahdid/artificial-intelligence-and-machine-learning/blob/master/linear_regression_in_cpp/main.cpp

#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include "DataDictionary.cpp"

using namespace std;
bool custom_sort(double a, double b) /* this custom sort function is defined to 
                                     sort on basis of min absolute value or error*/
{
    double a1 = abs(a - 0);
    double b1 = abs(b - 0);
    return a1 < b1;
}

const uint epoch = 4;
void train(std::vector<DataDictionary> dataDict, unordered_map<unsigned int, unsigned int[2]> &MinMax)
{

    /*Intialization Phase*/
    double x1[] = {2.7810836, 1.465489372, 3.396561688, 1.38807019, 3.06407232, 7.627531214, 5.332441248, 6.922596716, 8.675418651, 7.673756466};
    double x2[] = {2.550537003, 2.362125076, 4.400293529, 1.850220317, 3.005305973, 2.759262235, 2.088626775, 1.77106367, -0.2420686549, 3.508563011};
    double y[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}; //Would be performance good or bad as bool 0 / 1

    vector<double> error; // for storing the error values
    double err;           // for calculating error on each stage
    double b0 = 0;        // initializing b0
    double b1 = 0;        // initializing b1
    double b2 = 0;        // initializing b2
    double b3 = 0;        // initializing b3
    double b4 = 0;        // initializing b4
    double b5 = 0;        // initializing b5
    double b6 = 0;        // initializing b6
    double b7 = 0;        // initializing b7
    double b8 = 0;        // initializing b8
    double b9 = 0;        // initializing b9
    double b10 = 0;       // initializing b10
    double b11 = 0;       // initializing b11
    double b12 = 0;

    double alpha = 0.01; // initializing our learning rate
    double e = 2.71828;

    // town = _town;
    // storeId = _storeId;
    // managerName = _managerName;
    // staffNumbers = _staffNumbers;
    // space = _space;
    // carParking = _carParking;
    // demographicScore = _demographicScore;
    // location = _location;
    // populations = _populations;
    // storeAge = _storeAge;
    // clearenceSpace = _clearenceSpace;
    // competitionNum = _competitionNum;
    // competitionScore = _competitionScore;
    // performance = _performance;
    /*Training Phase*/
    double totalPopulation = 0;
    for (int i = 0; i < (dataDict.size() / 2) * epoch; i++)
    {
        //Since there are 10 values in our dataset and we want to run for 4 epochs so total for loop run 40 times
        int idx = i % (dataDict.size() / 2); //for accessing index after every epoch
        double normDemographic = (double)(dataDict[idx].GetDemographicScore() - MinMax[DEMOGRAPHIC_SCORE][0]) / (double)(MinMax[DEMOGRAPHIC_SCORE][1] - MinMax[DEMOGRAPHIC_SCORE][0]);
        double normCompetition = (double)(dataDict[idx].CompetitionScore() - MinMax[COMPETITION_SCORE][0]) / (double)(MinMax[COMPETITION_SCORE][1] - MinMax[COMPETITION_SCORE][0]);
        double normSpace = (double)(dataDict[idx].GetSpace() - MinMax[SPACE][0]) / (double)(MinMax[SPACE][1] - MinMax[SPACE][0]);
        double normClearence = (double)(dataDict[idx].ClearenceSpace() - MinMax[CLEARENCE_SPACE][0]) / (double)(MinMax[CLEARENCE_SPACE][1] - MinMax[CLEARENCE_SPACE][0]);
        double normStaffs = (double)(dataDict[idx].GetStaffNumbers() - MinMax[STAFF_NUMBERS][0]) / (double)(MinMax[STAFF_NUMBERS][1] - MinMax[STAFF_NUMBERS][0]);
        double normCompeteNum = (double)(dataDict[idx].CompetitionNumber() - MinMax[COMPETITION_NUM][0]) / (double)(MinMax[COMPETITION_NUM][1] - MinMax[COMPETITION_NUM][0]);

        // double population40Avg = dataDict[idx].Population_40().population / dataDict[idx].Population_40().distanceInMins;
        // double population30Avg = dataDict[idx].Population_30().population / dataDict[idx].Population_30().distanceInMins;
        // double population20Avg = dataDict[idx].Population_20().population / dataDict[idx].Population_20().distanceInMins;
        // double population10Avg = dataDict[idx].Population_10().population / dataDict[idx].Population_10().distanceInMins;
        totalPopulation = dataDict[idx].Population_40().population + dataDict[idx].Population_30().population + dataDict[idx].Population_20().population + dataDict[idx].Population_10().population;

        double p = -(b0 + b1 * normStaffs + b2 * normSpace + b3 * dataDict[idx].GetCarParking() + b4 * normDemographic +
                     b5 * dataDict[idx].GetLocation() + b6 * ((double)(dataDict[idx].Population_40().population / totalPopulation)) +
                     b7 * ((double)(dataDict[idx].Population_30().population / totalPopulation)) + b8 * ((double)(dataDict[idx].Population_20().population / totalPopulation)) +
                     b9 * ((double)(dataDict[idx].Population_10().population / totalPopulation)) + b10 * normClearence + b11 * normCompetition + b12 * normCompeteNum);
        //making the prediction

        double pred = 1.0 / (1.0 + pow(e, p)); //calculating final prediction applying sigmoid
        err = dataDict[idx].GetPerformance() - pred;

        // std::cout << err << std::endl;
        b0 = b0 - alpha * err * pred * (1 - pred) * 1.0;                                                                  //updating b0 (BIAS)
        b1 = b1 + alpha * err * pred * (1 - pred) * normStaffs;                                                           //updating b1
        b2 = b2 + alpha * err * pred * (1 - pred) * normSpace;                                                            //updating b2
        b3 = b3 + alpha * err * pred * (1 - pred) * dataDict[idx].GetCarParking();                                        //updating b1
        b4 = b4 + alpha * err * pred * (1 - pred) * normDemographic;                                                      //updating b2       b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; //updating b1
        b5 = b5 + alpha * err * pred * (1 - pred) * dataDict[idx].GetLocation();                                          //updating b2       b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; //updating b1
        b6 = b6 + alpha * err * pred * (1 - pred) * (double)(dataDict[idx].Population_40().population / totalPopulation); //updating b2       b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; //updating b1
        b7 = b7 + alpha * err * pred * (1 - pred) * (double)(dataDict[idx].Population_30().population / totalPopulation); //updating b2       b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; //updating b1
        b8 = b8 + alpha * err * pred * (1 - pred) * (double)(dataDict[idx].Population_20().population / totalPopulation); //updating b2       b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; //updating b1
        b9 = b9 + alpha * err * pred * (1 - pred) * (double)(dataDict[idx].Population_10().population / totalPopulation); //updating b2       b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; //updating b1
        b10 = b10 + alpha * err * pred * (1 - pred) * normClearence;                                                      //updating b2       b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx]; //updating b1
        b11 = b11 - alpha * err * pred * (1 - pred) * normCompetition;                                                    //updating b2
        b12 = b12 - alpha * err * pred * (1 - pred) * normCompeteNum;
        // cout << "B0=" << b0 << " "
        //      << "B1=" << b1 << " "
        //      << "B2=" << b2 << " error=" << err << endl; // printing values after every step
        error.push_back(err);
    }
    sort(error.begin(), error.end(), custom_sort); //custom sort based on absolute error difference

    /*Testing Phase*/
    // DataDictionary test1, test2; //enter test x1 and x2
    // cin >> test1 >> test2;
    for (int i = (dataDict.size() / 2); i < dataDict.size(); i++)
    {
        double normDemographic = (double)(dataDict[i].GetDemographicScore() - MinMax[DEMOGRAPHIC_SCORE][0]) / (double)(MinMax[DEMOGRAPHIC_SCORE][1] - MinMax[DEMOGRAPHIC_SCORE][0]);
        double normCompetition = (double)(dataDict[i].CompetitionScore() - MinMax[COMPETITION_SCORE][0]) / (double)(MinMax[COMPETITION_SCORE][1] - MinMax[COMPETITION_SCORE][0]);
        double normClearence = (double)(dataDict[i].ClearenceSpace() - MinMax[CLEARENCE_SPACE][0]) / (double)(MinMax[CLEARENCE_SPACE][1] - MinMax[CLEARENCE_SPACE][0]);
        double normSpace = (double)(dataDict[i].GetSpace() - MinMax[SPACE][0]) / (double)(MinMax[SPACE][1] - MinMax[SPACE][0]);
        double normStaffs = (double)(dataDict[i].GetStaffNumbers() - MinMax[STAFF_NUMBERS][0]) / (double)(MinMax[STAFF_NUMBERS][1] - MinMax[STAFF_NUMBERS][0]);
        double normCompeteNum = (double)(dataDict[i].CompetitionNumber() - MinMax[COMPETITION_NUM][0]) / (double)(MinMax[COMPETITION_NUM][1] - MinMax[COMPETITION_NUM][0]);

        totalPopulation = dataDict[i].Population_40().population + dataDict[i].Population_30().population + dataDict[i].Population_20().population + dataDict[i].Population_10().population;

        double pred = b0 + b1 * normStaffs + b2 * normSpace + b3 * dataDict[i].GetCarParking() + b4 * normDemographic +
                      b5 * dataDict[i].GetLocation() + b6 * ((double)(dataDict[i].Population_40().population / totalPopulation)) +
                      b7 * ((double)(dataDict[i].Population_30().population / totalPopulation)) + b8 * ((double)(dataDict[i].Population_20().population / totalPopulation)) +
                      b9 * ((double)(dataDict[i].Population_10().population / totalPopulation)) + b10 * normClearence + b11 * normCompetition + b12 * normCompeteNum;
        //make prediction
        cout << "The value predicted by the model= " << pred << endl;
        if (pred > 0.5)
            pred = 1;
        else
            pred = 0;
        // cout << "The class predicted by the model= " << dataDict[i].GetStoreID() << " #### " << pred << endl;
    }
}