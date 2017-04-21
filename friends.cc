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
		
		// Friend declarations -- The below functions are defined outside the vehicle class
                // but are declared inside the class. Can use private variables within the vehicle class
		friend string car_engine(vehicle);
		friend string truck_engine(vehicle);
};

string car_engine(vehicle v){
	return string("V6: " + v.make);
}
string truck_engine(vehicle v){
	return string("V8: " + v.make);
}
	
// car is-a vehicle
class car : public vehicle{
	public:
		car(string make_, string vin_) : vehicle(make_, vin_){
			cout << " | " << car_engine(*this) << '\n';
		}
};

// truck is-a vehicle
class truck : public vehicle{
	public:
		truck(string make_, string vin_) : vehicle(make_, vin_){
			cout << " | " << truck_engine(*this) << '\n';
		}
};

int main(){
	car c("Toyota", "123-456-888");
	truck t("Ford", "123-232-1111");
}
