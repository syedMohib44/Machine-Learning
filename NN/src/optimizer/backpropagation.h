#ifndef BACK_PROPOGATION
#define BACK_PROPOGATION

#include "../misc/functions.h"
#include "../neural/neuralnetwork.h"
#include "../dataset/dataset.h"
#include "optimizer.h"
#include <unordered_map>
#include <vector>
// #include "thread_guard.h"

extern double LEARNING_RATE;

class Backpropagation : public Optimizer
{

public:
	Backpropagation(){};
	~Backpropagation(){};
	void setLearningRate(double lr);

	vector<vector<vector<double> > > getBackpropagationShifts(const vector<double> &in, const vector<double> &out);

	void backpropagate(const vector<const vector<double> *> &ins, const vector<const vector<double> *> &outs){};

	vector<Layer *> getLayers();

	void minimize(){};

	void setBatchSize(size_t bs){};

private:
	size_t _batch_size = 20;
};

#endif