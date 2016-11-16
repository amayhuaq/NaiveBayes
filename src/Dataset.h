/*
 * Dataset.h
 *
 *  Created on: 15 de nov. de 2016
 *      Author: angela
 */

#ifndef SRC_DATASET_H_
#define SRC_DATASET_H_

#include "definedVariables.h"

class Dataset {
protected:
	uint numCls;
	uint numAttr;
	std::vector<Pattern> trainData;
	std::vector<Pattern> testData;

	void loadData(std::string fileName, std::vector<Pattern> &data);
public:
	Dataset(uint nCls=0, uint nAttr=0);
	virtual ~Dataset();

	Dataset& operator =(const Dataset &db);
	void loadTrainData(std::string fileName);
	void loadTestData(std::string fileName);

friend class NaiveBayes;
};

#endif /* SRC_DATASET_H_ */
