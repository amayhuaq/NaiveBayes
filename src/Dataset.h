#ifndef SRC_DATASET_H_
#define SRC_DATASET_H_

#include "definedVariables.h"

class Dataset {
private:
	void loadData(std::string fileName, std::vector<Pattern> &data);

protected:
	uint numCls;
	uint numAttr;
	std::vector<Pattern> trainData;
	std::vector<Pattern> testData;

public:
	Dataset(uint nCls=0, uint nAttr=0);
	virtual ~Dataset();

	Dataset& operator =(const Dataset &db);
	void loadTrainData(std::string fileName);
	void loadTestData(std::string fileName);

friend class NaiveBayes;
};

#endif /* SRC_DATASET_H_ */
