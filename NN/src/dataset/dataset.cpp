#include "dataset.h"

#include <fstream>
#include <algorithm>
#include "../misc/functions.h"

Dataset::Dataset(){};

// Dataset::Dataset(string filename)
// {
// 	ifstream infile(filename);
// 	vector<double> line;
// 	double a;
// 	while (!infile.eof())
// 	{
// 		infile >> a;
// 		// 1.000000000 2.4455999999 \n
// 		line.push_back(a);

// 		if (infile.get() == '\n')
// 		{
// 			// 2.4455999999
// 			double out = line[line.size() - 1];
// 			line.pop_back();

// 			_ins.push_back(line);
// 			_outs.push_back({out});
// 			line.clear();
// 		}
// 	}
// }

void Dataset::PushIns(vector<double> &in)
{
	_ins.push_back(in);
}

void Dataset::PushOuts(vector<double> &out)
{
	_outs.push_back(out);
}

Dataset::~Dataset()
{
}

void Dataset::split(double ptrain)
{
	for (size_t i = 0; i < _ins.size(); i++)
	{
		if (random(0, 1) < ptrain)
		{
			_train_ins.push_back(&_ins[i]);
			_train_outs.push_back(&_outs[i]);
		}
		else
		{
			_test_ins.push_back(&_ins[i]);
			_test_outs.push_back(&_outs[i]);
		}
	}
}

const vector<const vector<double> *> &Dataset::getIns(Datatype d) const
{
	if (d == Datatype::TRAIN)
		return _train_ins;
	return _test_ins;
}

const vector<const vector<double> *> &Dataset::getOuts(Datatype d) const
{
	if (d == Datatype::TRAIN)
		return _train_outs;
	return _test_outs;
}
