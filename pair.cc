#include <iostream>
#include <utility>

using namespace std;

int main(){
	pair<int, double> p(100, 200.1);
	std::cout << p.first << ", " << p.second << '\n';
	
	auto x = make_pair('a', 100);
	std::cout << x.first << ", " << x.second << '\n';
}
