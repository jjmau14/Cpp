#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> v = {1, 23, 542, 12, 42, 652, 72, 45, 86};
	for (auto v_item : v){ 
                cout << v_item << ' ';
        }
        cout << endl;	

	// In place copy using lambda function -- only values greater than 20
	auto itor = copy_if(v.begin(), v.end(),		// copy whole vect  
		v.begin(), [](int i){return i > 20;});	// store starting at v.begin(0)
	v.resize(itor-v.begin());	

	for (auto v_item : v){
		cout << v_item << ' ';
	}
	cout << endl;
}
