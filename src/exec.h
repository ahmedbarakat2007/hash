#ifndef EXEC_H
#define EXEC_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <unistd.h>
#include <string>
#include <sstream>
#include <vector>
#include <string>

//std::string exec(const char* cmd);


void exec(const char* cmd, const std::vector<std::string>& args);

#endif 
