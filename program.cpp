/** Jared Dickson
  * CIS 677
  * 2011-09-07
  */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node{
	node* prev;
	node* next;
	int value;
};

void swap(node &, node &);

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

	// Initialize dynamic array and set default values to zero
	int* subset = new int[k];
	for(int i = 0; i < k; i++){
		subset[i] = 0;
	}

	// Set seed for random
	srand(time(0));

	node root;
	node *current;

	root.next = NULL;
	root.prev = NULL;
	root.value = ((rand() % n) + 1);
	current = &root;

	// Generate subset
	for(int i = 1; i < k; i++){
		int tmp = ((rand() % n) + 1);		

		bool found = false;
		while(!found){	

			// Greater than current node
			if(tmp > current->value){
				
				// Next node exists
				if(current->next){

					// Greater than next node
					if(tmp > current->next->value){
						current = current->next;
					}

					// Equal to next node
					else if(tmp == current->next->value){
						i--;
						found = true;
					}

					// Value between current and next nodes
					else{
						node *mid = new node;

						mid->next = current->next;
						mid->prev = current;
						mid->value = tmp;

						current->next->prev = mid;
						current->next = mid;

						current = mid;
						found = true;
					}

				}

				// No next node
				else{
					node *last = new node;
					
					last->next = NULL;
					last->prev = current;
					last->value = tmp;
					
					current->next = last;

					current = last;
					found = true;
				}

			}

			// Lesser than current node
			else if(tmp < current->value){

				// Previous node exists
				if(current->prev){

					// Lesser than previous node
					if(tmp < current->prev->value){
						current = current->prev;
					}

					// Equal to previous node
					else if(tmp == current->prev->value){
						i--;
						found = true;
					}

					// Between current and previous nodes
					else{
						node *mid = new node;

						mid->next = current;
						mid->prev = current->prev;
						mid->value = tmp;

						current->prev->next = mid;
						current->prev = mid;						

						current = mid;
						found = true;
					}

				}

				// No previous node
				else{
					node *first = new node;	

					first->next = current;
					first->prev = NULL;
					first->value = tmp;

					current->prev = first;				

					current = first;				
					found = true;
				}

			}

			// Same value as current node
			else{
				i--;
				found = true;
			}
		}
	}

	node *rotate = &root;

	// Find beginning
	while(rotate->prev){
		rotate = rotate->prev;
	}

	// Print list in ascending order
	while(rotate){
		cout << rotate->value << endl;
		rotate = rotate->next;
	}

	return 0;
}