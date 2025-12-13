#include <iostream>
using namespace std ;

int main() {
    string cities[] = {"Sagarika Nagar", "Kundapura", "Mangalore", "Karkala" };
    float distances[] = {0, 31.87, 52.47, 34.1 };
    
    cout << "Cities from Sagarika Nagar:\n" ;
    for(int i = 0; i < 4 ; i++) {
        cout << cities[i] << ": " << distances[i] << " km\n" ;
    }
    return 0 ;
}
