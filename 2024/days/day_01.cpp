#include <algorithm>
#include <days.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <unordered_map>

namespace day_01 {

    int star_1() {
        std::ifstream infile("../days/days_input/day1_star1");
        std::vector<int> list1;
        std::vector<int> list2;
        int number1, number2;
        while (infile >> number1 >> number2) {
           list1.push_back(number1);
           list2.push_back(number2);
        }
        std::sort(list1.begin(), list1.end());
        std::sort(list2.begin(), list2.end());
        int sum = 0;
        for(int i = 0; i < list1.size(); i++) {
            sum +=  std::abs(list1[i]-list2[i]);
        }

        return sum;
    }

    int star_2() {
        std::ifstream infile("../days/days_input/day1_star1");
        std::vector<int> list1;
        std::vector<int> list2;
        int number1, number2;
        std::unordered_map<int, int> freq1;
        std::unordered_map<int, int> freq2;
        while (infile >> number1 >> number2) {
            freq1[number1]++;
            freq2[number2]++;
            list1.push_back(number1);
        }
        int sum = 0;
        for(int list1_num : list1) {
            int ret = 0;
            if (freq2.find(list1_num) != freq2.end()) {
                ret = list1_num * freq2[list1_num];
            }
            sum += ret;
        }
        return sum;
    }

 }
