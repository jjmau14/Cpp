#include <vector>
#include <iostream>
#include "iterable_class.h"

using std::cout;
using std::endl;

void itor_able::add_item(std::string s){
    sentence.push_back(s);
}
    
itor_able::itor &itor_able::itor::operator++(){
    ++current_location;
    return *this;
}
itor_able::itor itor_able::itor::operator++(int){
    const auto save = *this;
    ++*this;
    return save;
}
std::string itor_able::itor::operator*(){
    return sentence.at(current_location);
}
 
bool itor_able::itor::operator==(itor &rhs){
    return current_location == rhs.current_location;
}
bool itor_able::itor::operator!=(itor &rhs){
    return !(*this == rhs);
}
 
itor_able::itor itor_able::begin(){
    return itor_able::itor(sentence,0);
}
itor_able::itor itor_able::end(){
    return itor_able::itor(sentence,sentence.size());
}
std::string itor_able::front(){
    return sentence.at(0);
}
std::string itor_able::back(){
    return sentence.at(sentence.size()-1);
}

int main(){
    itor_able i;
    i.add_item("Hello");
    i.add_item("There");
    i.add_item("World");
    
    for (auto x : i)
        cout << x << endl;

}