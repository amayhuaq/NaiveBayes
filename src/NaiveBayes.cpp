/*
 * NaiveBayes.cpp
 *
 *  Created on: 15 de nov. de 2016
 *      Author: angela
 */

#include "NaiveBayes.h"
#include <iostream>
#include <string>
#include "helpers.h"

using namespace std;

NaiveBayes::NaiveBayes() {

}

NaiveBayes::~NaiveBayes() {
	// TODO Auto-generated destructor stub
}

void NaiveBayes::setDataset(Dataset db) {
	dataset = db;
}

void NaiveBayes::train() {
	int N = dataset.trainData.size();
	uint nAttr = dataset.numAttr;
	uint nCls = dataset.numCls;
	string currCls = "", currAttr = "";

	pCls.resize(nCls, 0);

	int c=0, a=0;
	int tc, ta = 0;
	for(auto patt : dataset.trainData)
	{
		currCls = patt[nAttr];

		if(kClass.find(currCls) == kClass.end()) {
			kClass[currCls] = c++;
		}
		tc = kClass[currCls];
		pCls[tc]++;

		for(uint i=0; i<nAttr; i++)
		{
			currAttr = patt[i] + helpers::to_string(i);
			if(kAttr.find(currAttr) == kAttr.end()) {
				kAttr[currAttr] = a++;
				pAttrCls.push_back(vector<float>(nCls,0));
			}
			ta = kAttr[currAttr];
			pAttrCls[ta][tc]++;
		}
	}

	for(auto t : kClass) {
		cout << t.first << " => " << pCls[t.second] << endl;
	}

	for(auto t : kAttr) {
		cout << t.first << endl;
	}
}

void NaiveBayes::test() {

}
