/*
 * NaiveBayes.h
 *
 *  Created on: 15 de nov. de 2016
 *      Author: angela
 */

#ifndef SRC_NAIVEBAYES_H_
#define SRC_NAIVEBAYES_H_

#include "Dataset.h"
#include <vector>
#include <map>

class NaiveBayes {
private:
	Dataset dataset;
	uint numAttr;
	uint numCls;
	std::map<std::string, uint> kClass;
	std::map<std::string, uint> kAttr;
	std::vector<float> pCls;
	std::vector<std::vector<float>> pAttrCls;
public:
	NaiveBayes();
	virtual ~NaiveBayes();

	void setDataset(Dataset db);
	void train();
	void test();
};

#endif /* SRC_NAIVEBAYES_H_ */
