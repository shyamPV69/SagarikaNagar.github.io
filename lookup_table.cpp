#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, float> distanceTable;
    
    distanceTable["Sagarika Nagar to Kundapura"] = 31.87;
    distanceTable["Sagarika Nagar to Mangalore"] = 52.47;
    distanceTable["Sagarika Nagar to Karkala"] = 34.1;
    
    string query = "Sagarika Nagar to Kundapura";
    if(distanceTable.find(query) != distanceTable.end()) {
        cout << query << ": " << distanceTable[query] << " km\n";
    }
    
    cout << "\nAll distances:\n";
    for(auto& entry : distanceTable) {
        cout << entry.first << " = " << entry.second << " km\n";
    }
    
    return 0;
}
