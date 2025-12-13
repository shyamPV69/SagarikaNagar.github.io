#include <iostream>
using namespace std ;

struct City {
    string  name;
    float  distance;
    string  zone;
};

int main() {
    City city1 = {"Sagarika Nagar", 0, "Residential" };
    City city2 = {"Kundapura", 31.87, "Coastal" };
    
    cout << "City: " << city1.name << "\n" ;
    cout << "Distance: " << city1.distance << " km\n" ;
    cout << "Zone: " << city1.zone << "\n" ;
    
    return 0 ;
}
