#include "../../../competitivelib/competitive.hpp"

#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <vector>

uint64_t modulus{1};
class Monkey
{
private:
    /* data */
public:
    using worry_level = uint64_t;
    Monkey(/* args */);
    ~Monkey();
    std::vector<worry_level> item_list;
    char operation_char;
    uint64_t inspect_items{0};
    uint64_t operation_number;
    uint64_t divisible_number;
    uint64_t true_throw_to;
    uint64_t false_throw_to;
    bool operation_number_is_old{false};

    void process(std::vector<Monkey>& processing_monekeys_list, int div_by=1){
        inspect_items+=item_list.size();
        for (size_t i = 0; i < item_list.size(); i++)
        {
           
            worry_level new_item{0};
            worry_level item = item_list[i];
            if(operation_number_is_old){
                operation_number = item;
            }

            switch (operation_char)
            {
            case '+':
                new_item = item + operation_number;
                break;
            case '*':
                new_item = (item * operation_number);
                break;
            default:
                break;
            }
            if(div_by==1){
                new_item = new_item % modulus;
            }
            new_item = new_item/div_by;

            if((new_item % divisible_number) == 0){
                processing_monekeys_list[true_throw_to].item_list.push_back(new_item);
            }
            else{
                processing_monekeys_list[false_throw_to].item_list.push_back(new_item);
            }

        }
        item_list.clear();
        
    }
};

Monkey::Monkey(/* args */)
{
}

Monkey::~Monkey()
{
}





uint64_t star_1(int rounds, int div_by=1) {
    std::ifstream infile("input.txt");

    std::string line;
    uint64_t temp {0};
    std::string trash;
    std::vector<Monkey> processing_monekeys_list;
    modulus = 1;
    // PARSE
    while (std::getline(infile ,line)) {
        if(!line.empty()){
            // parse monkey.
            Monkey monkey;
            std::getline(infile ,line);
            line = line.substr(18);
            auto starting_items_str = sct::split(line,", ");
            for(auto & s:starting_items_str){
                monkey.item_list.push_back(std::stoi(s));
            }

            // Operation:
            std::getline(infile ,line);
            monkey.operation_char = line[23];
            std::string str_left_op = line.substr(24);
            if(!(str_left_op == " old")){
                monkey.operation_number = std::stoi(line.substr(24));
            }else{
                monkey.operation_number_is_old= true;
            }

            // Test divisible 
            std::getline(infile ,line);
            monkey.divisible_number =  std::stoi(line.substr(20));
            modulus*=monkey.divisible_number;

            // if true
            std::getline(infile ,line);
            monkey.true_throw_to =  std::stoi(line.substr(28));
            // if false
            std::getline(infile ,line);
            monkey.false_throw_to =  std::stoi(line.substr(29));
            processing_monekeys_list.push_back(monkey);
        }
    }

    infile.close();


    for (size_t round = 0; round < rounds; round++)
    {
        for (auto &monkey : processing_monekeys_list)
        {
            monkey.process(processing_monekeys_list,div_by);
        }
    }
    
    std::vector<uint64_t> ret;
    for (auto &monkey : processing_monekeys_list)
    {
        ret.push_back(monkey.inspect_items);
    }
    std::sort(ret.begin(), ret.end());

    return ret[ret.size()-1]*ret[ret.size()-2];



}

int main() {

	

	std::cout << "Star_1: " << star_1(20,3) << std::endl;
	std::cout << "Star_2: " << star_1(10000) << std::endl;

	return 0;
}