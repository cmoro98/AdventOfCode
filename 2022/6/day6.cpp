#include "../../../competitivelib/competitive.hpp"

#include <fstream>
#include <iostream>
#include <numeric>
#include <string>

#include <vector>



int star_1(int number_distinct_characters) {
    std::ifstream infile("input.txt");
    std::string code;
    infile >> code;
    infile.close();
    //std::cout << code << std::endl;
    std::unordered_map<char,int> word;
    int count{0};
    int start{0};
    for (size_t i = 0; i < code.size(); i++)
    {
        char c = code[i];

        if(word.find(c) != word.end() and word[c]!=i and word[c]>=start){ // found
            int temp = word[c];
            word[c] = i;
            start = temp+1;
            count = (i-start);
            count++;
           
            // remove elements
        }else{
            word[c] = i;
            count++;
        }
        if(count==number_distinct_characters){return i+1;};
    }
    

    return 0;

}


int main() {
	

	std::cout << "Star_1: " << star_1(4) << std::endl;
	std::cout << "Star_2: " << star_1(14) << std::endl;

	return 0;
}