#include <algorithm>
#include <days.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <unordered_map>
#include <competitivelib/print.hpp>
#include <regex>
namespace day_03 {

    int regex_solver(std::string input) {
        std::vector<std::string> results;
        std::regex pattern(R"(mul\(\d+,\d+\))");
        std::sregex_iterator begin(input.begin(), input.end(), pattern);
        std::sregex_iterator end;
        int result {0};

        for (auto it = begin; it != end; ++it) {
            int num1, num2;
            std::sscanf(it->str().c_str(), "mul(%d,%d)", &num1, &num2);
            result += num1 * num2;
        }
        return result;
    }
    bool GetNumbers(const std::string& input, int& num1, int& num2) {
        return std::sscanf(input.c_str(), "mul(%d,%d)", &num1, &num2) == 2;
    }
    int star_1() {
        std::ifstream infile("../days/days_input/day3.txt");
        std::string line;
        int result {0};
        while (std::getline(infile ,line)) {
          result +=  regex_solver(line);
        }

        return result;
    }
    std::string remove_disable_text(const std::string& input,const std::string& enable_word) {
        size_t position = input.find(enable_word);
        if (position != std::string::npos) // found
        {
            auto disabled_line = input.substr(0, position);
            //std::cout << " disable: " << disabled_line << std::endl;

            auto rest_of_the_line = input.substr(position);
            return rest_of_the_line;
        }
        return "";
    }

    std::tuple<int,std::string>  solve_enabled_text(std::string line, std::string disable_word) {
        size_t position = line.find(disable_word);
        int result{0};
        if (position != std::string::npos) // found
        {
            auto enabled_line = line.substr(0, position);
            result +=regex_solver(enabled_line);
            //std::cout << line.substr(0, position) << std::endl;

            auto rest_of_the_line = line.substr(position);
            //std::cout << rest_of_the_line << std::endl;
            return {result, rest_of_the_line};

        }
        result +=regex_solver(line);
        return {result,""};
    }

    int star_2() {
        std::ifstream infile("../days/days_input/day3.txt");
        int result {0};
        std::string enable_word{"do()"};
        std::string disable_word{"don't()"};
        std::stringstream buffer;
        buffer << infile.rdbuf();
        std::string line = buffer.str();
            // get first substring until first don't -> solve that substring
            // now up to that position get until the first do. That substring can be removed or ignored.
            // now get the substring  until the next don't and solveit
            while(true) {
                if(line.empty()){break;}
                auto [ret,rest_of_the_line ] = solve_enabled_text(line, disable_word);
                result+=ret;
                line = remove_disable_text(rest_of_the_line, enable_word);
            }


        return result;
    }

 }
