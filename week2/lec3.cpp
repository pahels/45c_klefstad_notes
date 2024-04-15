/*
how compilation works
preprocessor - handles #include, #define, #ifdef
compiler - makes one pass over source file. function (variable, class, etc), must be declared before called or error is thrown. translates functions
to relocatable binary machine learning module
linker - called functon must be defined before "program linking", else error: undefined function
loader - binary executable program is loaded into RAM and main() is called

function parameters
- formals are those given in the definition
x and y are the formal parameters for average
actuals are those in the call
fuck you jitty
*/

#include <iostream>
using namespace std;
double average(double x, double y){
    return (x+y)/2.0;
}

//1.0 and 2.0 are actuals
double z = average(1.0, 2.0);

/*
default values for parameters
- like python
*/

double toCent(double farenheit = 32.0){
    return 5.0*(farenheit - 32.0)/9.0;
}

/*
reference parameters  allow us to modify the value in a parameter
& means it is passed by reference, default is "copy value"
copies are expensive but can be valuable
*/


//so basically this will not actually increment x
void inc(int x){
    x = x+1;
}

//this will actually increment x
void increment(int & x){
    x = x+1;
}


/*
copy a file one line at a time
*/
#include <fstream>
using namespace std;
void readline(){
    ifstream in("input.txt"); //opens file
    ofstream out("output.txt"); //new file
    string line;
    while(getline(in, line)){ //get will read input (one line of text until newline). returns false when there is no more input data
        out << line << endl;
    }
    in.close();
    out.close();
}
/*
copy a file one char at a time
*/
#include <fstream>
using namespace std;
void readchar(){
    char c;
    //stops when end of file - nothing left to read. if reading from terminal ^d
    while(cin >> c){ //reading from terminal and printing back to terminal
        cout << c;
    }
}


/*
variables
- must be declared before they are used
- constants have fixed value
- constants may not be assigned - can't re define value

RAM 
- address and value
- Rvalue = value inside, Lvalue = thing on the left
x = y - interested in rvalue, care about x address 

*/

/*
storage areas
3 areas of memory:
- global static
stack
heap (Free store)
*/


int square(int i){
	return i * i;
}

int main(){
	for(int i = 1; i <=10; i++){
		cout << square(i) << endl;
    }
}
