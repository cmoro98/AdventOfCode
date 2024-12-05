#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

namespace sct{


/*
Can be used for a specific range.
Complexity O(n+k)
Space complexity O(n)

*/



void counting_sort1()
{
    int lower_bound{0}, upper_bound{9};
    std::vector<int> v = {1,4,1,2,7,5,2};
    std::vector<int> index_count(upper_bound+1,0);// of the total range.
    std::vector<int> output(v.size());
    for (size_t i = 0; i < v.size(); i++)
    {
        index_count[v[i]]++;
    }
    for (size_t i = 1; i < index_count.size(); i++)
    {
        index_count[i]+=index_count[i-1];
    }
    for (size_t i = 0; i < v.size(); i++)
    {
        auto new_pos = index_count[v[i]];
        output[new_pos-1]=v[i];
        index_count[v[i]]--;
    }
    print_vector(v);
    print_vector(index_count);
    print_vector(output);



}






template<typename InputIterator>
void counting_sort(InputIterator first, InputIterator last) {
  auto minmax_el = std::minmax_element(first, last);
  auto min = *minmax_el.first;
  auto max = *minmax_el.second;
  std::vector<std::size_t> counts(max - min + 1, 0);

  std::for_each(first, last, [&](auto x) { 
    ++counts[x - min];  // Store value counts
  }); 

  for (auto it_c = counts.begin(); it_c != counts.end(); ++it_c) { 
    auto idx = std::distance(counts.begin(), it_c);
    first = std::fill_n(first, *it_c, idx + min); // Store in sorted order
    //std::advance(first, *it_c);
  }
}


}