#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Declare classes for friends -- should use .h but lazy
class car;
class truck;

class vehicle{
	public:
		// Ctor -- default will init make and vin to empty strings
		vehicle(string make_ = "", string vin_ = "") : make(make_), vin(vin_){
			cout << "vehicle created: " << make << ": " << vin;
		}
	private:
		string make;
		string vin;
		
		// Friend declarations -- car and use car_engine and truck can use truck_engine
		friend string car_engine();
		friend string truck_engine();
};
	string car_engine(){return string("V6");}
	string truck_engine(){return string("V8");}
	
// car is-a vehicle
class car : public vehicle{
	public:
		car(string make_, string vin_) : vehicle(make_, vin_){
			cout << " | " << car_engine() << '\n';
		}
};

// truck is-a vehicle
class truck : public vehicle{
	public:
		truck(string make_, string vin_) : vehicle(make_, vin_){
			cout << " | " << truck_engine() << '\n';
		}
};

int main(){
	car c("Toyota", "123-456-888");
	truck t("Ford", "123-232-1111");
}