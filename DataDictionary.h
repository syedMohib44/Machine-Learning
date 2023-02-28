//REF: https://www.analyticsvidhya.com/blog/2020/04/machine-learning-using-c-linear-logistic-regression/

#include <unordered_map>
enum Location
{
    ShoppingCentre = 4,
    HighStreet = 2,
    RetailPark = 3,
    Village = 1
};

enum DataEnum
{
    TOWN = 0,
    STORE_ID = 2,
    MANAGER_NAME = 3,
    STAFF_NUMBERS = 4,
    SPACE = 5,
    CAR_PARKING = 7,
    DEMOGRAPHIC_SCORE = 8,
    LOCATION = 9,
    POPULATION_40 = 10,
    POPULATION_30 = 11,
    POPULATION_20 = 12,
    POPULATION_10 = 13,
    STORE_AGE = 14,
    CLEARENCE_SPACE = 15,
    COMPETITION_NUM = 16,
    COMPETITION_SCORE = 17,
    PERFORMANCE = 18
};

struct Population
{
    Population() = default;
    Population(unsigned int _distanceInMins, unsigned int _population)
    {
        distanceInMins = _distanceInMins;
        population = _population;
    }
    unsigned int distanceInMins = 0;
    unsigned int population = 0;
};

class DataDictionary
{
public:
    explicit DataDictionary(char *_town, unsigned int _storeId,
                            char *_managerName,
                            unsigned int _staffNumbers,
                            unsigned int _space,
                            bool _carParking,
                            unsigned int _demographicScore,
                            Location _location,
                            Population *_populations,
                            unsigned int _storeAge,
                            unsigned int _clearenceSpace,
                            unsigned int _competitionNum,
                            unsigned int _competitionScore,
                            bool _performance);

    // DataDictionary(const DataDictionary &) = delete;            //Disallow copying operation
    // DataDictionary &operator=(const DataDictionary &) = delete; //Disallow copying operation

    // DataDictionary(DataDictionary &&) = delete;                  //Disallow moving operation
    // DataDictionary &operator=(const DataDictionary &&) = delete; //Disallow moving operation

    ~DataDictionary();

    void setData(char *_town, unsigned int _storeId,
                 char *_managerName,
                 unsigned int _staffNumbers,
                 unsigned int _space,
                 bool _carParking,
                 unsigned int _demographicScore,
                 Location _location,
                 Population *_populations,
                 unsigned int _storeAge,
                 unsigned int _clearenceSpace,
                 unsigned int _competitionNum,
                 unsigned int _competitionScore,
                 bool _performance);
    char *GetTown();
    unsigned int GetStoreID();
    char *GetManagerName();
    unsigned int GetStaffNumbers();
    unsigned int GetSpace();
    bool GetCarParking();
    unsigned int GetDemographicScore();
    Location GetLocation();
    unsigned int GetStoreAge();
    unsigned int ClearenceSpace();
    unsigned int CompetitionNumber();
    unsigned int CompetitionScore();
    bool GetPerformance();
    Population Population_40();
    Population Population_30();
    Population Population_20();
    Population Population_10();

private:
    char *town;
    unsigned int storeId;
    char *managerName;
    unsigned int staffNumbers;
    unsigned int space;
    bool carParking;
    unsigned int demographicScore;
    Location location;
    unsigned int storeAge;
    unsigned int clearenceSpace;
    unsigned int competitionNum;
    unsigned int competitionScore;
    bool performance;
    Population *populations;
};