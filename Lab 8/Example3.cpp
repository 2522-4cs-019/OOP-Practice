#include <iostream>

using namespace std;

class Shape{
	
	
public:
	virtual void calculateArea() = 0;
	
};

class Rectangle : public Shape{
	
private:
	
	int length, width;
	
public:
	
	Rectangle(int l, int w){
		length = l;
		width = w;
	}
	
	void calculateArea(){
		cout << "Rectangle Area: " << length*width << "\n";
	}
};

class Square : public Shape{
	
private:
	
    int side;

public:
	
    Square(int s){
    	side = s;
    }

    void calculateArea() override {
        cout << "Square Area: " << side * side << endl;
    }
};

int main(){
	
    Rectangle r(5, 4);
    Square s(6);

    r.calculateArea();
    s.calculateArea();

    return 0;
}