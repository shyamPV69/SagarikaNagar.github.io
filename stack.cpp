#include <iostream>
#include <stack>
using namespace std ;

int main() {
    stack<string > visitedLocations;
    
    visitedLocations.push("Sagarika Nagar" );
    visitedLocations.push("Commercial City" );
    visitedLocations.push("IT Park" );
    
    cout << "Backtracking path:\n" ;
    while (!visitedLocations.empty()) {
        cout << "Returning to: " << visitedLocations.top() << endl ;
        visitedLocations.pop();
    }
    
    return 0 ;
}
