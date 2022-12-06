#include "../../../competitivelib/competitive.hpp"

#include <fstream>
#include <iostream>
#include <numeric>
#include <string>

#include <vector>

std::vector<std::vector<char>> stack_parser(int number_of_stacks, std::ifstream &infile) {
	std::string line;
	std::vector<std::vector<char>> stacks(number_of_stacks);
	while (std::getline(infile, line)) {
		if (line[1] == '1') {
			std::getline(infile, line);
			break;
		}
		int index = 0;
		for (size_t i = 1; i < line.size(); i += 4) {
			index++;
			if (line[i] == ' ') {
				continue;
			}
			//std::cout << line[i] << "(" << index << "),";
			stacks[index - 1].push_back(line[i]);
		}
		//std::cout << std::endl;
	}
    for (size_t i = 0; i < stacks.size(); i++)
    {
        std::reverse(stacks[i].begin(), stacks[i].end());
    }
    
    return stacks;
}

std::string star_1() {
    std::ifstream infile("input.txt");

    std::vector<std::vector<char>> stacks = stack_parser(9,infile);
    std::string trash;
    int quantity, from_i, to_i;


    while (infile >> trash >> quantity  >> trash >> from_i >> trash >> to_i) {
        //std::cout << quantity << "," << from_i << "," << to_i << "\n" ;
        to_i--; from_i--;
        std::copy(stacks[from_i].rbegin(),stacks[from_i].rbegin()+quantity,std::back_inserter(stacks[to_i]));
        stacks[from_i].resize(stacks[from_i].size() - quantity);
    }
    infile.close();
    std::string message;
    for (size_t i = 0; i < stacks.size(); i++)
    {
        message += stacks[i][stacks[i].size()-1];
    }
    
    return message;
}



std::string star_2() {
   
    std::ifstream infile("input.txt");

    std::vector<std::vector<char>> stacks = stack_parser(9,infile);
    std::string trash;
    int quantity, from_i, to_i;


    while (infile >> trash >> quantity  >> trash >> from_i >> trash >> to_i) {
        //std::cout << quantity << "," << from_i << "," << to_i << "\n" ;
        to_i--; from_i--;
        std::copy(stacks[from_i].end()-quantity,stacks[from_i].end(),std::back_inserter(stacks[to_i]));
        stacks[from_i].resize(stacks[from_i].size() - quantity);
    }
    infile.close();
    std::string message;
    for (size_t i = 0; i < stacks.size(); i++)
    {
        message += stacks[i][stacks[i].size()-1];
    }
    
    return message;

}


int main() {
	

	std::cout << "Star_1: " << star_1() << std::endl;
	std::cout << "Star_2: " << star_2() << std::endl;

	return 0;
}