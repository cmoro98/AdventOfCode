#include "../../../competitivelib/competitive.hpp"

#include <fstream>
#include <iostream>
#include <numeric>
#include <string>

#include <vector>

int star_1() {
    std::ifstream infile("input.txt");


    std::string line;

    int temp {0};
    std::vector<int> total_calories_per_elf;
    while (std::getline(infile ,line)) {
        if(line.empty()){
            total_calories_per_elf.push_back(temp);
            temp = 0;
        }
        else{
            //std::cout << line << std::endl;
            temp += stoi(line);
        }
    }
    return *std::max_element(total_calories_per_elf.begin(), total_calories_per_elf.end());



}



int star_2() {
   

    std::ifstream infile("pr.txt");


    std::string line;

    int temp {0};
    std::vector<int> total_calories_per_elf;
    while (std::getline(infile ,line)) {
        if(line.empty()){
            total_calories_per_elf.push_back(temp);
            temp = 0;
        }
        else{
            temp += stoi(line);
        }
    }
    std::sort(total_calories_per_elf.begin(), total_calories_per_elf.end());

    return std::accumulate(total_calories_per_elf.end()-3, total_calories_per_elf.end(),0);


}


int main() {
	

	std::cout << "Star_1: " << star_1() << std::endl;
	std::cout << "Star_2: " << star_2() << std::endl;

	return 0;
}