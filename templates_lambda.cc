#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>

using namespace std;

// Template Class 
template <typename T>
class Point{
	private:
		T x, y;
	public:
		Point(T x_, T y_) : x(x_), y(y_){
			cout << "Initialized P\n";
		}
		T getx() const {return x;}
		T gety() const {return y;}
		friend ostream &operator<<(ostream &out, const Point<T> &p){
			return out << "[" << p.x << ", " << p.y << "]\n";
		}
};

// Functor
class Adder {
	public:
		double operator()(double a, double b){
			return a + b;
		}
};

int main(){
	// Templates
	Point<double> a(3.4, 2.1);
	cout << a;
	
	// Functors
	Adder add;
	cout << "Adding resolves to: " << add(12.3, 1039.32) << endl;
	
	// Lambda Functions
	set<int> s = {2,3,4,5,6,23,5,6,34,23,34,5,65,32,213,23,45,63,2};
	// iterates until it finds a value > 20 begining at the set begin() and
	// ending at set end() using a lambda function to determine > 20
	auto itor = find_if(s.begin(), s.end(), [](int n){return n>20;});
	// Should print 23
	cout << *itor << endl;
}