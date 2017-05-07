#include <string>
#include <iostream>
#include <fstream>
#include "Parser.h"

using namespace std;

    void Parser::parseToLevel(string fileName){
        ifstream readFile;
        readFile.open((fileName+".txt").c_str());

        string line;

        for (int i = 0; i < ROWS; i++){
            // Converts each line to a char array
            getline(readFile, line);
            char arr[COLS];
            strcpy(arr, line.c_str());

            // Writes each line to the level array
            for (int j = 0; j < COLS; j++) {
                Parser::level[i][j] = arr[j] - '0';
            }

        }

    }


    const short int* Parser::getLevel(){
        return Parser::level;

    }


