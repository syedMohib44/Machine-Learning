#include "DataDictionary.h"

DataDictionary::DataDictionary(char *_town, unsigned int _storeId,
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
                               bool _performance)
{
    town = _town;
    storeId = _storeId;
    managerName = _managerName;
    staffNumbers = _staffNumbers;
    space = _space;
    carParking = _carParking;
    demographicScore = _demographicScore;
    location = _location;
    populations = _populations;
    storeAge = _storeAge;
    clearenceSpace = _clearenceSpace;
    competitionNum = _competitionNum;
    competitionScore = _competitionScore;
    performance = _performance;
}

DataDictionary::~DataDictionary()
{
}

void DataDictionary::setData(char *_town, unsigned int _storeId,
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
                             bool _performance)
{
    town = _town;
    storeId = _storeId;
    managerName = _managerName;
    staffNumbers = _staffNumbers;
    space = _space;
    carParking = _carParking;
    demographicScore = _demographicScore;
    location = _location;
    populations = _populations;
    storeAge = _storeAge;
    clearenceSpace = _clearenceSpace;
    competitionNum = _competitionNum;
    competitionScore = _competitionScore;
    performance = _performance;
}

char *DataDictionary::GetTown() { return town; }
unsigned int DataDictionary::GetStoreID() { return storeId; }
char *DataDictionary::GetManagerName() { return managerName; }
unsigned int DataDictionary::GetStaffNumbers() { return staffNumbers; }
unsigned int DataDictionary::GetSpace() { return space; }
bool DataDictionary::GetCarParking() { return carParking; }
unsigned int DataDictionary::GetDemographicScore() { return demographicScore; }
Location DataDictionary::GetLocation() { return location; }
unsigned int DataDictionary::GetStoreAge() { return storeAge; }
unsigned int DataDictionary::ClearenceSpace() { return clearenceSpace; }
unsigned int DataDictionary::CompetitionNumber() { return competitionNum; }
unsigned int DataDictionary::CompetitionScore() { return competitionScore; }
bool DataDictionary::GetPerformance() { return performance; }
Population DataDictionary::Population_40() { return populations[0]; }
Population DataDictionary::Population_30() { return populations[1]; }
Population DataDictionary::Population_20() { return populations[2]; }
Population DataDictionary::Population_10() { return populations[3]; }