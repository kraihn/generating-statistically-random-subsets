#include<iostream>

using namespace std;

int main(){
	// Variables
	int k;
	int n;
	bool cont = true;


	// Welcome
	cout << "Generating Statistically Random Subsets by Jared Dickson" << endl << endl;

	// Ask for input n	
	cont = true;
	while(cont){
		cout << "Please enter the total number of patients (N): ";
		cin >> n;

		if(cin.fail()){
			cin.clear();
			char c;
			cin >> c;

			cout << "Bad input. Please try again." << endl;
		}
		else if(n < 1){
			cout << "Input must be greater than 0. Please try again." << endl;
		}
		else{
			cont = false;
		}
	}

	// Ask for input k
	cont = true;
	while(cont){
		cout << "Please enter the subset number of patients (K): ";
		cin >> k;

		if(cin.fail()){
			cin.clear();
			char c;
			cin >> c;

			cout << "Bad input. Please try again." << endl;
		}
		else if(k <= 0 || k > n){
			cout << "Input ouside valid range. Please try again." << endl;
		}
		else{
			cont = false;
		}
	}

	// Input summary
	cout << k << " patients will be selected from the group of " << n << "." << endl;

	return 0;
}