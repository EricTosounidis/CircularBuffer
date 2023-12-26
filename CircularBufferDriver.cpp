#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n\n";
    CircularBuffer<int, 5, array<int, 5>> integerDemo;
    cout << "Initial state \n";
    cout << integerDemo;

    for (int i = 0; i < 8; i++) {
        cout << "Pushing " << i * 10 << endl;
        integerDemo.push_back(i * 10);
        cout << integerDemo;
    }

    for (int i = 0; i < 5; i++) {
        integerDemo.pop();
        cout << integerDemo;
    }

    cout << "\n*************** <string> Circular Buffer Demo ******************\n\n";

    vector<string> strVec{ "welcome", " to", " the", " wonderful", " world", "of", " oz" };
    CircularBuffer < string, 5, array<string, 5>> strDemo;
    cout << "Initial state \n";
    cout << strDemo;

    cout << "After using the back_insert_iterator\n";
    copy(strVec.begin(), strVec.end(), back_inserter(strDemo));
    cout << strDemo;
    

    for (int i = 0; i < 5; i++) {
        cout << "Popping: " << strVec[i] << endl;
        strDemo.pop();
        cout << strDemo;
    }

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n\n";

    CircularBuffer < dog, 5, array<dog, 5>> dogDemo;
    dog temp = dog("Guiness", "Wheaten", 9);
    dogDemo.push_back(temp);
    temp = dog("Grimlock", "Lab", 2);
    dogDemo.push_back(temp);
    temp = dog("Optimus", "Bulldog", 5);
    dogDemo.push_back(temp);
    temp = dog("Murphy", "Lab", 14);
    dogDemo.push_back(temp);
    temp = dog("Floyd", "Beagle", 12);
    dogDemo.push_back(temp);

    cout << dogDemo;
    cout << "dogs Full?: " << boolalpha << dogDemo.full() << endl << endl;

    temp = dog("Snoopy", "Beagle", 100);
    dogDemo.push_back(temp);
    cout << dogDemo;

    temp = dog("Archie", "Brittany", 1);
    dogDemo.push_back(temp);
    cout << dogDemo;

    temp = dog("Penny", "Beagle", 2);
    dogDemo.push_back(temp);
    cout << dogDemo;

    for (int i = 0; i < 5; i++) {
        dogDemo.pop();
        cout << endl << dogDemo;
    }

    cout << endl;
}
