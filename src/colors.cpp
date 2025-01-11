#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <unistd.h>
#include "exec.h"
#include "colors.h"
#include <cstring>


using namespace std;

void print_color(const char* text, const char* color, const char* line){
    if (strcmp(color, "black") == 0){
        cout << "\033[30m" << text << "\033[0m";
    }
    else if (strcmp(color, "red") == 0){
        cout << "\033[31m" << text << "\033[0m";
    }
    else if (strcmp(color, "green") == 0){
        cout << "\033[32m" << text << "\033[0m";
    }
    else if (strcmp(color, "yellow") == 0){
        cout << "\033[33m" << text << "\033[0m";
    }
    else if (strcmp(color, "blue") == 0){
        cout << "\033[34m" << text << "\033[0m";
    }
    else if (strcmp(color, "magenta") == 0){
        cout << "\033[35m" << text << "\033[0m";
    }
    else if (strcmp(color, "cyan") == 0){
        cout << "\033[36m" << text << "\033[0m";
    }
    else if (strcmp(color, "white") == 0){
        cout << "\033[37m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_black") == 0){
        cout << "\033[90m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_red") == 0){
        cout << "\033[91m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_green") == 0){
        cout << "\033[92m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_yellow") == 0){
        cout << "\033[93m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_magenta") == 0){
        cout << "\033[95m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_cyan") == 0){
        cout << "\033[96m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_blue") == 0){
        cout << "\033[94m" << text << "\033[0m";
    }
    else if (strcmp(color, "bright_white") == 0){
        cout << "\033[97m" << text << "\033[0m";
    }

    if (strcmp(line, "endl") == 0){
        printf("\n");
    }else{
        // do nothing
    }
}