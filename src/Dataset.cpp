/*
 * Dataset.cpp
 *
 *  Created on: 15 de nov. de 2016
 *      Author: angela
 */

#include "Dataset.h"
#include <fstream>
#include <iostream>

using namespace std;

Dataset::Dataset(uint nCls, uint nAttr) {
	numCls = nCls;
	numAttr = nAttr;
}

Dataset::~Dataset() {
	// TODO Auto-generated destructor stub
}
/*
Dataset::Dataset(Dataset&& other) {
	if(this != &other)
	{
		numCls = 0; numAttr = 0;
		trainData.clear();
		testData.clear();

		numCls = other.numCls;
		numAttr = other.numAttr;
		trainData = other.trainData;
		testData = other.testData;

		other.numCls = 0;
		other.numAttr = 0;
		other.trainData.clear();
		other.testData.clear();
	}
}
*/

Dataset& Dataset::operator =(const Dataset &db) {
	numAttr = db.numAttr;
	numCls = db.numCls;
	trainData = db.trainData;
	testData = db.testData;
	return *this;
}

void Dataset::loadData(string fileName, vector<Pattern> &data) {
	ifstream fileData(fileName.c_str());

	if(fileData.is_open())
	{
		string str, tmp;
		Pattern patt;

		while(fileData >> str)
		{
			tmp = "";
			patt.clear();
			for(auto c : str) {
				if(c != ',')
					tmp += c;
				else {
					patt.push_back(tmp);
					tmp = "";
				}
			}
			patt.push_back(tmp);
			data.push_back(patt);
		}
		fileData.close();
	}
	else
	{
		cout << "The file is not found" << endl;
	}
}

void Dataset::loadTrainData(string fileName) {
	trainData.clear();
	loadData(fileName, trainData);
	cout << ">>> Train Data is loaded\n";
}

void Dataset::loadTestData(string fileName) {
	testData.clear();
	loadData(fileName, testData);
	cout << ">>> Test Data is loaded\n";
}
