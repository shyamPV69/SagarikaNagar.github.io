#include <iostream>
#include <queue>
using namespace std ;

int main() {
    queue<string > visitQueue;
    
    visitQueue.push("Sagarika Nagar" );
    visitQueue.push("Residential Zone" );
    visitQueue.push("Governance Office" );
    visitQueue.push("Airport" );
    
    cout << "BFS Visit Order:\n" ;
    while (!visitQueue.empty()) {
        cout << "Visiting: " << visitQueue.front() << endl ;
        visitQueue.pop();
    }
    
    return 0 ;
}
