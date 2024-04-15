#include <iostream> //brings in delcarations for I/O

int main(){ //called when program is run
    int i = 4;
    int sq = i * i;
    //did not use namespace standard which is why we use std::
    std::cout <<"The square of " << i << " is " << sq << std::endl; //print to terminal with a newline
    return 0; //don't need this line bc compiler automatically adds it 
}

//not everything is an object in c++. Primitives are things like char, int, float - machine oriented
//care not char lolololol
//less freedom than python - need to specify types and shit
//declaration vs definition - declaration is just declared, you don't necessarily know what to do with it
//'char' "string" - can't mix them up
//arrays are good for performance - the modern computer is designed to optimize cache which assumes ur using arrays
//loops also give performance idk what this means tbh
//tuples lists and dictionaries do exist in C++ unfortunately
//c++ has 3 levels. High - like python. Middle - classes and stuff. Low - C/systems programmin
