#include <iostream>
#include <fstream>
using namespace std;
int readchar(){
    char c;
    //stops when end of file - nothing left to read. if reading from terminal ^d
    while(cin >> c){ //reading from terminal and printing back to terminal
        cout << c;
    }
}

int main(){
    readchar();
}