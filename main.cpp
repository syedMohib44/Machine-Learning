// #include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "split.cpp"
// #include "DataDictionary.cpp"
#include "LogesticRegression.cpp"

int main()
{
    string fname = "storedata.csv";
    // cout << "Enter the file name: ";
    // cin >> fname;

    std::vector<std::vector<std::string> > content;
    std::unordered_map<unsigned int, unsigned int[2]> MinMax;

    std::vector<DataDictionary> dictList;
    std::vector<std::string> words;
    std::string line, word;

    fstream file(fname, ios::in);

    // alternative
    // fstream file;
    // file.open(fname, ios::in);

    // TOWN = 0,
    // STORE_ID = 1,
    // MANAGER_NAME = 2,
    // STAFF_NUMBERS = 3,
    // SPACE = 4,
    // CAR_PARKING = 5,
    // DEMOGRAPHIC_SCORE = 6,
    // LOCATION = 7,
    // POPULATION_40 = 8,
    // POPULATION_30 = 9,
    // POPULATION_20 = 10,
    // POPULATION_10 = 11,
    // STORE_AGE = 12,
    // CLEARENCE_SPACE = 13,
    // COMPETITION_NUM = 14,
    // COMPETITION_SCORE = 15,
    // PERFORMANCE = 16
    if (file.is_open())
    {
        int i = 0;
        // getline(file, line);
        // Get and drop a line
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (getline(file, line))
        {
            stringstream str(line);
            split(line, words, ',');

            Population populations[] = {Population(40, std::strtoul(words[POPULATION_40].c_str(), NULL, 0)), Population(30, std::strtoul(words[POPULATION_30].c_str(), NULL, 0)),
                                        Population(20, std::strtoul(words[POPULATION_20].c_str(), NULL, 0)), Population(10, std::strtoul(words[POPULATION_10].c_str(), NULL, 0))};

            // char *_town, unsigned int _storeId,
            //     char *_managerName,
            //     unsigned int _staffNumbers,
            //     unsigned _space,
            //     bool _carParking,
            //     unsigned int _demographicScore,
            //     Location _location,
            //     Population *_population,
            //     unsigned int _storeAge,
            //     unsigned int _clearenceSpace,
            //     unsigned int _competitionNum,
            //     unsigned int _competitionScore,
            //     bool _performance
            // std::cout << (char *)words[0].c_str();

            // ShoppingCentre = 0,
            // HighStreet = 1,
            // RetailPark = 3,
            // Village = 4
            Location location;
            bool carParking = false;
            bool performance = false;

            if (words[LOCATION] == "Shopping Centre")
                location = ShoppingCentre;
            else if (words[LOCATION] == "High Street")
                location = HighStreet;
            else if (words[LOCATION] == "Retail Park")
                location = RetailPark;
            else if (words[LOCATION] == "Village")
                location = Village;

            if (std::toupper(words[CAR_PARKING][0]) == 'Y')
                carParking = true;

            if (std::toupper(words[PERFORMANCE][0]) == 'G')
                performance = true;
            int staffNumber = std::stoi(words[STAFF_NUMBERS]);
            if (staffNumber < 0)
                staffNumber *= -1;
            //Doing this because of this article https://towardsdatascience.com/multivariate-logistic-regression-in-python-7c6255a286ec
            //TODO: Have to assign all min and max value like this

            DataDictionary *dict = new DataDictionary((char *)words[TOWN].c_str(), std::strtoul(words[STORE_ID].c_str(), NULL, 0), (char *)words[MANAGER_NAME].c_str(), staffNumber,
                                                      std::strtoul(words[SPACE].c_str(), NULL, 0), carParking, std::strtoul(words[DEMOGRAPHIC_SCORE].c_str(), NULL, 0),
                                                      location, populations, std::strtoul(words[STORE_AGE].c_str(), NULL, 0), std::strtoul(words[CLEARENCE_SPACE].c_str(), NULL, 0),
                                                      std::strtoul(words[COMPETITION_NUM].c_str(), NULL, 0), std::strtoul(words[COMPETITION_SCORE].c_str(), NULL, 0), performance);

            if (*MinMax[SPACE] == 0)
            {
                MinMax[SPACE][0] = dict->GetSpace();
                MinMax[SPACE][1] = dict->GetSpace();
            }

            if (*MinMax[STAFF_NUMBERS] == 0)
            {
                MinMax[STAFF_NUMBERS][0] = staffNumber;
                MinMax[STAFF_NUMBERS][1] = staffNumber;
            }

            if (*MinMax[DEMOGRAPHIC_SCORE] == 0)
            {
                MinMax[DEMOGRAPHIC_SCORE][0] = dict->GetDemographicScore();
                MinMax[DEMOGRAPHIC_SCORE][1] = dict->GetDemographicScore();
            }

            if (*MinMax[STORE_AGE] == 0)
            {
                MinMax[STORE_AGE][0] = dict->GetStoreAge();
                MinMax[STORE_AGE][1] = dict->GetStoreAge();
            }

            if (*MinMax[CLEARENCE_SPACE] == 0)
            {
                MinMax[CLEARENCE_SPACE][0] = dict->ClearenceSpace();
                MinMax[CLEARENCE_SPACE][1] = dict->ClearenceSpace();
            }

            if (*MinMax[COMPETITION_NUM] == 0)
            {
                MinMax[COMPETITION_NUM][0] = dict->CompetitionNumber();
                MinMax[COMPETITION_NUM][1] = dict->CompetitionNumber();
            }

            if (*MinMax[COMPETITION_SCORE] == 0)
            {
                MinMax[COMPETITION_SCORE][0] = dict->CompetitionScore();
                MinMax[COMPETITION_SCORE][1] = dict->CompetitionScore();
            }

            if (MinMax[SPACE][1] < dict->GetSpace())
                MinMax[SPACE][1] = dict->GetSpace();

            if (MinMax[STAFF_NUMBERS][1] < staffNumber)
                MinMax[STAFF_NUMBERS][1] = staffNumber;

            if (MinMax[DEMOGRAPHIC_SCORE][1] < dict->GetDemographicScore())
                MinMax[DEMOGRAPHIC_SCORE][1] = dict->GetDemographicScore();

            if (MinMax[STORE_AGE][1] < dict->GetStoreAge())
                MinMax[STORE_AGE][1] = dict->GetStoreAge();

            if (MinMax[CLEARENCE_SPACE][1] < dict->ClearenceSpace())
                MinMax[CLEARENCE_SPACE][1] = dict->ClearenceSpace();

            if (MinMax[COMPETITION_NUM][1] > dict->CompetitionNumber())
                MinMax[COMPETITION_NUM][1] = dict->CompetitionNumber();

            if (MinMax[COMPETITION_SCORE][1] < dict->CompetitionScore())
                MinMax[COMPETITION_SCORE][1] = dict->CompetitionScore();

            if (MinMax[SPACE][0] > dict->GetSpace())
                MinMax[SPACE][0] = dict->GetSpace();

            if (MinMax[STAFF_NUMBERS][0] < staffNumber)
                MinMax[STAFF_NUMBERS][0] = staffNumber;

            if (MinMax[DEMOGRAPHIC_SCORE][0] > dict->GetDemographicScore())
                MinMax[DEMOGRAPHIC_SCORE][0] = dict->GetDemographicScore();

            if (MinMax[STORE_AGE][0] > dict->GetStoreAge())
                MinMax[STORE_AGE][0] = dict->GetStoreAge();

            if (MinMax[CLEARENCE_SPACE][0] > dict->ClearenceSpace())
                MinMax[CLEARENCE_SPACE][0] = dict->ClearenceSpace();

            if (MinMax[COMPETITION_NUM][0] > dict->CompetitionNumber())
                MinMax[COMPETITION_NUM][0] = dict->CompetitionNumber();

            if (MinMax[COMPETITION_SCORE][0] > dict->CompetitionScore())
                MinMax[COMPETITION_SCORE][0] = dict->CompetitionScore();

            dictList.push_back(*dict);
            i++;
        }
        file.close();
    }
    else
        cout << "Could not open the file\n";


    train(dictList, MinMax);

    return 0;
}