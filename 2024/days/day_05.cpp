#include <algorithm>
#include <days.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <unordered_map>
#include <competitivelib/print.hpp>
#include <competitivelib/util.hpp>

namespace day_05 {
    int  are_in_correct_order_01(const std::vector<std::pair<int, int>>& pairs, const std::vector<int>& order) {
        std::unordered_map<int, int> position_map;
        for (int i = 0; i < order.size(); ++i) {
            position_map[order[i]] = i;
        }

        bool is_in_order {true};
        std::vector<int> results;

        for (const auto& [first, second] : pairs) {
            auto it_first = position_map.find(first);
            auto it_second = position_map.find(second);

            if (it_first != position_map.end() && it_second != position_map.end()) {

                if (!(it_first->second < it_second->second)) {
                    is_in_order = false;
                }
            } else {
                //They do not really are in the order, lets ignore them.
            }
        }
        if (is_in_order) {
            //sct::print_vector(order);
            size_t middle_index = order.size() / 2;
            int middle_value = order[middle_index];
            //std::cout << " middle value is : " << middle_value << std::endl;
            return middle_value;
        }

        return 0;
    }


    int  are_in_correct_order_lets_fix_them(const std::vector<std::pair<int, int>>& pairs, std::vector<int>& order) {
        std::unordered_map<int, int> position_map; // value: position
        for (int i = 0; i < order.size(); ++i) {
            position_map[order[i]] = i;
        }
        bool everything_went_smoothly {true};
        bool is_in_order {false};
        std::vector<int> results;

        while (!is_in_order) {
            is_in_order = true;

            for (const auto& [first, second] : pairs) {
                auto it_first = position_map.find(first);
                auto it_second = position_map.find(second);

                if (it_first != position_map.end() && it_second != position_map.end()) {
                    if (!(it_first->second < it_second->second)) {
                        is_in_order = false; // Se detecta que el orden no es correcto
                        int position_first = it_first->second;
                        int position_second = it_second->second;
                        std::swap(order[position_first], order[position_second]);

                        // update positio map
                        position_map[order[position_first]] = position_first;
                        position_map[order[position_second]] = position_second;
                        everything_went_smoothly = false;
                        break;
                    }
                }
            }
        }
        if (!everything_went_smoothly) {
            sct::print_vector(order);
            size_t middle_index = order.size() / 2;
            int middle_value = order[middle_index];
            std::cout << " middle value is : " << middle_value << std::endl;
            return middle_value;
        }

        return 0;
    }


    int star_1() {
        std::ifstream infile("../days/days_input/day5.txt");
        std::string line;
        std::vector<std::string> matrix;
        std::vector<std::vector<int>> page_numbers_updates;
        std::vector<std::pair<int, int >> order_numbers;
        while (std::getline(infile ,line)) {
            int numero1, numero2;
            std::cout << line << "\n";
            sscanf(line.c_str(), "%d|%d", &numero1, &numero2);
            order_numbers.push_back(std::make_pair(numero1, numero2));
            if(line.empty()) {break;}
        }
        while (std::getline(infile ,line)) {
            std::vector<int> page_numbers_update = sct::splitToInt(line, ",");
            page_numbers_updates.push_back(page_numbers_update);
        }
        int sum{0};
        for(auto page: page_numbers_updates) {
            sum+=are_in_correct_order_01(order_numbers, page);
        }



        return sum;
    }

    int star_2() {
        std::ifstream infile("../days/days_input/day5.txt");
        std::string line;
        std::vector<std::string> matrix;
        std::vector<std::vector<int>> page_numbers_updates;
        std::vector<std::pair<int, int >> order_numbers;
        while (std::getline(infile ,line)) {
            int numero1, numero2;
            std::cout << line << "\n";
            sscanf(line.c_str(), "%d|%d", &numero1, &numero2);
            order_numbers.push_back(std::make_pair(numero1, numero2));
            if(line.empty()) {break;}
        }
        while (std::getline(infile ,line)) {
            std::vector<int> page_numbers_update = sct::splitToInt(line, ",");
            page_numbers_updates.push_back(page_numbers_update);
        }
        int sum{0};
        for(auto page: page_numbers_updates) {
            sum+=are_in_correct_order_lets_fix_them(order_numbers, page);
        }
        return sum;
    }

 }
