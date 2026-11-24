#include <iostream>

using namespace std;

class Assessment{

public:

    virtual void calculateMarks() = 0;

};

class Quiz : public Assessment{

private:
    int quizMarks;

public:
	
    Quiz(int m){
        quizMarks = m;
    }

    void calculateMarks(){
        cout << "Quiz Marks: " << quizMarks << endl;
    }

    int getMarks(){
        return quizMarks;
    }
};

class Assignment : public Assessment{
	
private:
    int assignmentMarks;

public:
	
    Assignment(int m){
        assignmentMarks = m;
    }

    void calculateMarks(){
        cout << "Assignment Marks: " << assignmentMarks << endl;
    }

    int getMarks() {
        return assignmentMarks;
    }
};

class Marks{
	
private:
    int value;

public:
    Marks(int v){
        value = v;
    }

    Marks operator+(Marks obj){
        Marks temp(0);
        temp.value = value + obj.value;
        return temp;
    }

    void display(){
        cout << "Total Assessment Marks: " << value << endl;
    }
};

int main(){
	
    Quiz q(15);
    Assignment a(25);

    q.calculateMarks();
    a.calculateMarks();

    Marks m1(q.getMarks());
    Marks m2(a.getMarks());

    Marks total = m1 + m2;
    total.display();

    return 0;
}