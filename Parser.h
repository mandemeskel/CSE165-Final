#ifndef PARSER_H
#define PARSER_H
#define ROWS 5
#define COLS 20
#include <string>

using namespace std;

class Parser {

    const short int level[ROWS][COLS];

public:

    // Converts level given in fileName (not including the .txt extension) and puts it in level
    void parseToLevel(string fileName);

    // returns level, if using, take and save elsewhere
    short int* getLevel();

};

#endif
