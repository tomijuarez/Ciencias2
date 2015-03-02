#include "data.h"

data::data() { }

data::~data() { }

void data::_conversion(char output[], std::string input){

    unsigned int pos = 0;

    while(pos <= input.size()){
        output[pos] = input[pos];
        pos++;
    }

}
