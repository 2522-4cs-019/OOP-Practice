#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape{
    
public:

    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual string name() = 0;

    void show(){
        cout << name() << ": area = " << area() << ", perimeter = " << perimeter() << endl;
    }

    virtual ~Shape(){
        cout << "Shape destroyed" << endl;
    }
};

class Circle : public Shape{

private:

    double r;

public:

    Circle(double radius){
        r = radius;
    }

    double area() override{
        return 3.14 * r * r;
    }

    double perimeter() override{
        return 2 * 3.14 * r;
    }

    string name() override{
        return "Circle";
    }

    ~Circle(){
        cout << "Circle destroyed" << endl;
    }
};

class Rectangle : public Shape{

private:

    double l, w;

public:

    Rectangle(double length, double width){
        l = length;
        w = width;
    }

    double area() override{
        return l * w;
    }

    double perimeter() override{
        return 2 * (l + w);
    }

    string name() override{
        return "Rectangle";
    }

    ~Rectangle(){
        cout << "Rectangle destroyed" << endl;
    }
};

class Triangle : public Shape{

private:

    double a, b, c;

public:

    Triangle(double side1, double side2, double side3){
        a = side1;
        b = side2;
        c = side3;
    }

    double area() override{
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() override{
        return a + b + c;
    }

    string name() override{
        return "Triangle";
    }

    ~Triangle(){
        cout << "Triangle destroyed" << endl;
    }
};

int main(){

    Shape* shapes[3] ={
        new Circle(3),
        new Rectangle(4, 6),
        new Triangle(3, 4, 5)
    };

    for (int i = 0; i < 3; i++){
        shapes[i]->show();
    }

    int maxIndex = 0;
    for (int i = 1; i < 3; i++){
        if (shapes[i]->area() > shapes[maxIndex]->area()){
            maxIndex = i;
        }
    }
    cout << "Largest shape: " << shapes[maxIndex]->name() << endl;

    for (int i = 0; i < 3; i++){
        delete shapes[i];
    }

    return 0;
}