#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>

using std::cout;
using std::endl;

class myObject {
    
    std::vector<int> myVector;
    
public:
       
    typedef typename std::vector<int>::iterator iterator;
    
    myObject(const std::initializer_list<int> &il){
        for(auto item : il)
            myVector.push_back(item);
        // Tried using std::copy(il.begin(), il.end(), myVector.begin()) but didnt work
        // I dont think copy() works on vects...?
    }
    
    iterator begin(){
        return myVector.begin();
    }
    
    iterator end(){
        return myVector.end();
    }
};

int main(){
    // {10, 20...} is of type 'initializer_list'
    // which is an iterable object
    for (auto item : {10, 20, 30, 40, 50})
        cout << item << endl;
        
    cout << endl;
        
    myObject o = {10, 20, 30, 40, 50};
    for (auto item : o)
        cout << item << endl;
}