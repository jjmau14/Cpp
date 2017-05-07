#include <iostream>
#include <vector>

using std::cout;
using std::endl;

// Takes a type T and an int. If int is
// not specified, default = 10
template <typename T, int N = 10>
class group {
    
    std::string name_of_group;
    std::vector<T> myVect = {N};
    
    public:
        // Will not compile without typename: needed because of template class
        typedef typename std::vector<T>::iterator iterator;
        
        // Default Constructor: default value of name_of_group is empty string
        group(std::string name_of_group_ = "") : name_of_group(name_of_group_){
            // Intentionally left empty
        }
        
        // To use enhanced for-each loop, must include
        // begin and end as well as typename above 
        iterator begin(){
            return myVect.begin();
        }
        
        iterator end(){
            return myVect.end();
        }
        
        void add(T item){
            myVect.push_back(item);
        }
};

int main(){
    group<int> group_a;
    for (auto x : group_a)
        cout << x << endl;
    
    group<int, 192> group_b;
    for (auto x : group_b)
        cout << x << endl;
}