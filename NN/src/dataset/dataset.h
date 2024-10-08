#ifndef DATASET
#define DATASET

#include <vector>

using namespace std;

enum Datatype
{
	TRAIN,
	TEST
};

class Dataset
{
public:
	Dataset(){};
	// Dataset(string filename){};
	~Dataset(){};

	const vector<const vector<double> *> &getIns(Datatype d) const;

	const vector<const vector<double> *> &getOuts(Datatype d) const;

	void split(double ptrain){};

	void PushOuts(vector<double> &out){};
	void PushIns(vector<double> &in){};

private:
	vector<vector<double> > _ins;
	vector<vector<double> > _outs;

	vector<const vector<double> *> _train_ins;
	vector<const vector<double> *> _train_outs;

	vector<const vector<double> *> _test_ins;
	vector<const vector<double> *> _test_outs;
};
#endif