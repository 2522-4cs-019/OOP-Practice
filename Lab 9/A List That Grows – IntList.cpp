#include <iostream>
using namespace std;

class IntList{
	
private:
    int* data;
    int count;
    int capacity;

    void grow(){
        int oldCapacity = capacity;
        capacity *= 2;
        int* newData = new int[capacity];

        for (int i = 0; i < count; i++){
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;

        cout << "Resizing: " << oldCapacity << " -> " << capacity << endl;
    }

public:
    IntList(){
        capacity = 2;
        count = 0;
        data = new int[capacity];
    }

    ~IntList(){
        delete[] data;
        cout << "IntList memory freed" << endl;
    }

    void add(int value){
        if (count == capacity){
            grow();
        }
        data[count] = value;
        count++;
    }

    int get(int index){
        if (index < 0 || index >= count){
            cout << "Invalid index " << index << endl;
            return -1;
        }
        return data[index];
    }

    int size(){
        return count;
    }

    void print(){
        cout << "List (" << count << "/" << capacity << "): ";
        for (int i = 0; i < count; i++){
            cout << data[i];
            if (i < count - 1){
                cout << " ";
            }
        }
        cout << "\n";
    }
};

int main(){
	
    IntList list;

    for (int i = 10; i <= 60; i += 10){
        list.add(i);
    }

    list.print();

    int item3 = list.get(3);
    if (item3 != -1){
        cout << "Item at 3: " << item3 << endl;
    }

    int item10 = list.get(10);
    if (item10 != -1){
        cout << "Item at 10: " << item10 << "\n";
    }

    cout << "Size: " << list.size() << "\n";

    return 0;
}