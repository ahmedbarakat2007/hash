#ifndef DIR_H
#define DIR_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <unistd.h>
#include <string>
#include <cstring>


void print_dir();

void change_dir(const char* dir);

std::string get_dir();

#endif