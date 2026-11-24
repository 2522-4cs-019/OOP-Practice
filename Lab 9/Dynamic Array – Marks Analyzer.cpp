#include <iostream>

using namespace std;

int main(){
	
	int n;
	cout << "Number of Students: ";
	cin >> n;
	
	int* marks = new int[n];
	
	for(int i = 0; i < n; i++){
		cout << "Enter 5 marks: ";
		cin >> marks[i];
	}
	
	int total = 0;
	int highest = -1;
	for(int i = 0; i < n; i++){
		total += marks[i];
		
		if(marks[i] > highest){
			highest = marks[i];
		}
	}
	
	cout << "Average: " << total / n << "\n";
	cout << "Highest: " << highest << "\n";
	
	cout << "Above Average: ";
	for(int i = 0; i < n; i++){
		if(marks[i] > total/n){
			cout << marks[i] << " ";
		}
	}
	cout <<  "\n";
	
	delete[] marks;
	marks = nullptr;
	
	return 0;
}