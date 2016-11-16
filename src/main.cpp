#include "Dataset.h"
#include "NaiveBayes.h"

int main() {
	Dataset db(4,6);
	db.loadTrainData("data/car.data");
	db.loadTestData("data/car-test.data");

	NaiveBayes naiBay;
	naiBay.setDataset(db);
	naiBay.train();
	naiBay.test();

	return 0;
}
