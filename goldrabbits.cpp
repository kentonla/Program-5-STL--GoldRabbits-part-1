// Name: Kenton La
// CECS 325-01
// Prog 5 - STL (GoldRabbits part 1)
// Nov 11, 2024

// I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <time.h>
#include <map>
#include <iomanip>
using namespace std;
long long callsMade = 0;  //keeps track of how many times goldRabbits is called

int goldRabbits(int n){
    static map<int, int> sMap;
    callsMade++;
    if (n==0 || n==1){
        return 1;
    }
    else if(sMap.find(n) != sMap.end()){ //if we dont get the end value back from find then the value exists in the map
        return sMap[n];
    }
    else{   // value not in map
        int total = goldRabbits(n-1) + goldRabbits(n-2);
        if (total < 0){
            throw overflow_error("Overflow at fibo("+to_string(n)+")");
        }
        sMap[n] = total;
        return sMap[n];
    }
}

int main()
{
    int const months = 12 * 10; // this is 10 years or 120 months
    int start = time(0); // number of seconds since Jan 1, 1970
    for(int i=0; i<months; i++)
    {
        int current = time(0); // number of seconds since program started
        cout << setw(5)<<current-start<<":"; // print elapsed seconds
        cout << " GoldRabbits("<<setw(2)<<i<<") = ";
        try{
            cout << setw(11)<< goldRabbits(i) << "\tfiboCount: " << callsMade << endl; // the call to goldRabbits
        }
        catch (...){
            cout << endl << "Overflow at fibo(" << i << ")" << endl;
            break;
        }
    }
}
