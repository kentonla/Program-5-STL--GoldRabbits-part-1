#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
long long callsMade = 0;  //keeps track of how many times goldRabbits is called

int goldRabbits(int n){
    try{
        callsMade++;
        if (n==0 || n==1){
            return 1;
        }
        else if(n < 0){
            throw callsMade;
        }
        else{
            return goldRabbits(n-1) + goldRabbits(n-2);
        }
    }
    catch (int num){
        cout << Overflow at fibo(num) << endl;
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
        cout << setw(11)<< goldRabbits(i) <<endl;// the call to goldRabbits
    }
}
