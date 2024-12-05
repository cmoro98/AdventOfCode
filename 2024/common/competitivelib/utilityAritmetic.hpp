	#include <algorithm>
	#include <vector>
	#include <iostream>
	#include <unordered_map>
	namespace sct {
	/*
	Returns the modulus operation like in python: -90 mod 360 = 270
	*/
	template <typename T> 
	T modPythonic(T a , T b) {
		return (b +((a)%b))%b;
	}


	// Median
	/*
	Example {1,1,3,4,6,7} -> [3,4]-> return 3,5
	*/
	// ok for ints and doubles
	template <typename T>
	double median(std::vector<T> values){
		//assert(!values.empty());
  		const auto middleItr = values.begin() + values.size() / 2;
		std::nth_element(values.begin(), middleItr, values.end());
		if (values.size() % 2 == 0) {
			const auto leftMiddleItr = std::prev(middleItr);
			return (*leftMiddleItr + *middleItr) / 2.0;
		} else {
			return *middleItr;
		}
	}


	template <typename T>
	T mode(std::vector<T> values){


		std::unordered_map<T, int > histogram;

		int mode {0};
		for (size_t i = 0; i < values.size(); i++)
		{
			histogram[values[i]]++;
			mode = std::max(histogram[values[i]], mode);
		}



		auto mode_element = *std::max_element(histogram.begin(), histogram.end(),
                             [](const std::pair<T, int> &a,
                                const std::pair<T, int> &b)
                             {
                                 return a.second < b.second;
                             });
		return mode_element.first;
		
	}

	template <typename T>
	std::unordered_map<T, int > mode_c(std::vector<T> values){


		std::unordered_map<T, int > histogram;

		int mode {0};
		for (size_t i = 0; i < values.size(); i++)
		{
			histogram[values[i]]++;
			mode = std::max(histogram[values[i]], mode);
		}


		for (auto  it = histogram.begin(); it != histogram.end();)
		{
			if (it->second != mode){

        		it = histogram.erase(it);
			}
    		else{
        		++it;
			}
		}
		
		return histogram;
		
	}
	// 
	}
	// 
	


