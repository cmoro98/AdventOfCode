#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
#include <sstream>
#include "../../../competitivelib/competitive.hpp"

struct Registers{
	int X{1};
};
class CPU
{
private:
	/* data */
public:
	CPU(/* args */);
	~CPU();
	std::vector<Registers> cycle_registers_registry{};
	
	void noop(){
		cycle_registers_registry.push_back(regs);
		cycle++;
		
	}

	void addx(int value){
		cycle++;
		cycle_registers_registry.push_back(regs);
		cycle_registers_registry.push_back(regs);
		cycle++;
		regs.X+=value;
	};


	int cycle{0};
	Registers regs;
};

CPU::CPU(/* args */)
{
}

CPU::~CPU()
{
}


int star_1() {
	std::ifstream infile("input.txt");
	std::string instruction;
    std::string line;
	int value;
    std::vector<int> total_calories_per_elf;
	CPU cpu{}; 
    while (std::getline(infile ,line)) {
		std::stringstream ss(line);
		ss >> instruction;
		//std::cout << instruction << std::endl;

		if(instruction=="noop"){
			cpu.noop();
		}
		else if(instruction=="addx"){
			ss >> value;
			cpu.addx(value);
		}

    }
	infile.close();

	std::vector<int> during_cycles{20,60,100,140,180,220};
	auto lambda = [&](int sum, int cycle)
	{
		int signal_streng = cpu.cycle_registers_registry[cycle-1].X*cycle;
		return sum + signal_streng;
	};
	return std::accumulate(during_cycles.begin(), during_cycles.end(),0,lambda);



}

void print_screen(CPU &cpu){ 
	std::vector<std::string> crt_screen(6,std::string(40,'.'));
	int index_cycle{1};
	std::cout << "\n";
	for ( auto &line : crt_screen)
	{
		for (int i = 0; i < line.size(); i++)
		{
			int value = cpu.cycle_registers_registry[index_cycle-1].X;
			if(i == value or i -1  == value or i+1 == value){
				line[i]='#';
			}
			index_cycle++;
		}
	}
	sct::print_vector_v(crt_screen);
}

int star_2() {
		std::ifstream infile("input.txt");
	std::string instruction;
    std::string line;
	int value;
    std::vector<int> total_calories_per_elf;
	CPU cpu{}; 
    while (std::getline(infile ,line)) {
		std::stringstream ss(line);
		ss >> instruction;
		//std::cout << instruction << std::endl;

		if(instruction=="noop"){
			cpu.noop();
		}
		else if(instruction=="addx"){
			ss >> value;
			cpu.addx(value);
		}

    }
	infile.close();
	print_screen(cpu);
	return 0;

}

int main() {
	std::cout << "Star_1: " << star_1() << std::endl;
	std::cout << "Star_2: " << star_2() << std::endl;

	return 0;
}

