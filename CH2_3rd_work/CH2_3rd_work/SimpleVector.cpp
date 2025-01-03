#include "SimpleVector.h"
using namespace std;

int main() {
	SimpleVector<int> myVector;
	SimpleVector<int> myVector2;
	int c = 0;
	while(c != -1){
		cout << "배열 요소 입력(종료: -1): ";
		cin >> c;
		if (c != -1) {
			myVector.push_back(c);
		}
	}

	for (int i = 0; i < myVector.size(); ++i) {
		cout << myVector.getData()[i] << " ";
	}
	
	cout << endl;

	myVector.sortData();
	
	for (int i = 0; i < myVector.size(); ++i) {
		cout << myVector.getData()[i] << " ";
	}
	
	return 0;


}