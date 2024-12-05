#include <algorithm>
#include <days.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <unordered_map>
#include <competitivelib/print.hpp>


namespace day_04 {
              //0, 1, 2, 3,   4, 5,   6,  7
              //S, SE,E, NE,  N, NO,  O , SO
    int dr[] = {1, 1, 0, -1, -1, -1,  0,  1};
    int dc[] = {0, 1, 1,  1,  0, -1, -1, -1};

    int drx[] = {  1,  -1,   -1,   1};// SE, NE, NO, So
    int dcx[] = {  1,   1,   -1,  -1};



    int evalMAS(int i , int j, const std::vector<std::string>& matrix,  const std::string word, int index_word, std::pair<int,int> direction) {
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()){return 0;}
        if(matrix[i][j]!=word[index_word]){return 0;}
        if( word[index_word]==word[word.size()-1]) {
            return 1;
        }
        index_word++;
        int next_i = i+direction.first;
        int next_j = j+direction.second;
        return evalMAS(next_i,next_j, matrix, word, index_word, direction);
    }
    int evalXMAS(int i , int j, const std::vector<std::string>& matrix) {
        int sum {0};
        const std::string word {"MAS"};
        int index_word=0;
        for(int k=0; k<8; k++) {
           sum += evalMAS(i+dr[k], j+dc[k], matrix,  word, index_word,{dr[k],dc[k]});
        }
        return sum;
    }
    bool isWithinBounds(int x, int y, const std::vector<std::string>& matrix) {
        return x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size();
    }
    int evalX_MAS(int i , int j, const std::vector<std::string>& matrix) {
        int sum {0};
        for(int k=0; k<4; k++) {
            if(!isWithinBounds(i+drx[k], j+dcx[k], matrix)) {
                return 0;
            }
        }
        char SE = matrix[i+drx[0]][j+dcx[0]];
        char NE = matrix[i+drx[1]][j+dcx[1]];
        char NO = matrix[i+drx[2]][j+dcx[2]];
        char SO = matrix[i+drx[3]][j+dcx[3]];
        /* Caso 1:
           M.S
           .A.
           M.S
        */
        if (SE == NE && SE == 'S' && SO == NO && SO == 'M') {
            sum++;
        }

        /* Caso 2:
           S.S
           .A.
           M.M
        */
        if (NO == NE && NO == 'S' && SE == SO && SE == 'M') {
            sum++;
        }

        /* Caso 3:
           M.M
           .A.
           S.S
        */
        if (NO == NE && NO == 'M' && SE == SO && SE == 'S') {
            sum++;
        }

        /* Caso 4:
           S.M
           .A.
           S.M
        */
        if (NO == SO && SO == 'S' && SE == NE && SE == 'M') {
            sum++;
        }

        return sum;
    }


    int star_1() {
        std::ifstream infile("../days/days_input/day4.txt");
        std::vector<int> list1;
        std::vector<int> list2;
        std::string line;
        std::vector<std::string> matrix;
        while (std::getline(infile ,line)) {
            matrix.push_back(line);
        }
        int count {0};
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]=='X') {
                    count+=evalXMAS(i, j, matrix);
                }

            }
        }


        return count;
    }

    int star_2()  {
        std::ifstream infile("../days/days_input/day4.txt");
        std::vector<int> list1;
        std::vector<int> list2;
        std::string line;
        std::vector<std::string> matrix;
        while (std::getline(infile ,line)) {
            matrix.push_back(line);
        }
        int count {0};
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j]=='A') {
                    count+=evalX_MAS(i, j, matrix);
                }

            }
        }


        return count;
    }

 }
