#include <iostream>
#include <string>

using namespace std;


class Student{
	
private:
	int rollNo;
	int marks;
	
public:
	
	Student(int rollNo = 0, int marks = 0) : rollNo(rollNo), marks(marks){
		
	}
	
	bool operator>(Student s){
		return marks > s.marks;
	};
};


int main(){
	
	Student s1(101, 85);
	Student s2(102, 75);
//	Student s2(102, 90);
	
	if(s1 > s2){
		cout << "Student 1 has obtained highest marks";
	}
	else{
		cout << "Student 2 has obtained highest marks";
	}
	return 0;
}