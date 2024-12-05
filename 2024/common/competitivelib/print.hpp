#include <iostream>
#include <vector>
#include <tuple>
namespace sct {


    template<typename T>
    void print_vector(std::vector<T> vect){
        for(auto &v:vect){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    void print_vector_tuple(std::vector<std::tuple<T,T>> vect){
        for(auto &[a,b]:vect){
            std::cout << a << " " << b << std::endl;
        } 
    }

    inline void print_binary(unsigned int num)
    {
        for(int i = 256; i > 0; i = i/2) {
            if(num & i) 
                std::cout << "1 ";
            else
                std::cout << "0 ";
        }
        std::cout << std::endl;
    }

	template <typename T> 
    void print_vector_v(std::vector<T> a){
        for(auto &&e:a){
            std::cout << e <<" " << std::endl;
        }
    }

    template <typename T>
    void print_grid(std::vector<std::vector<T>> a){
        for (unsigned int i = 0; i < a.size(); i++)
        {
            for (unsigned int j = 0; j < a[i].size(); j++)
            {
                std::cout << a[i][j] << " ";
            }
            std::cout << "\n";
            
        }
    }


}

