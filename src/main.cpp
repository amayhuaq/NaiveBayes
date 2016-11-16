#include <iostream>
#include "Dataset.h"
#include "NaiveBayes.h"

int main() {
	Dataset db(4,6);
	db.loadTrainData("data/car.data");
	db.loadTestData("data/car-test.data");

	NaiveBayes naiBay;
	naiBay.setDataset(db);
	naiBay.train();

	return 0;
}


/*
#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main()
{
    std::string str = "Hello";
    std::vector<std::string> v;

    // uses the push_back(const T&) overload, which means
    // we'll incur the cost of copying str
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";

    // uses the rvalue reference push_back(T&&) overload,
    // which means no strings will copied; instead, the contents
    // of str will be moved into the vector.  This is less
    // expensive, but also means str might now be empty.
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";

    std::cout << "The contents of the vector are \"" << v[0]
                                         << "\", \"" << v[1] << "\"\n";
}
*/