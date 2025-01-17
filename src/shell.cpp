#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <unistd.h>
#include "exec.h"
#include "colors.h"
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "dir.h"
#include <sstream>
#include <vector>
#include <string>
#include "shell.h"
#include "ls.h"

using namespace std;

void start_shell(){
    while (true) {
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == 0) {
            string host = hostname;
            cout << "\033[30;47m" << host << "\033[0m";
        } else {
            perror("hash : gethostname failed");
            return;
        }
        print_dir();
        printf("▓█▓▒░ ");

        string input;
        getline(cin, input); 
        stringstream ss(input);
        string word;
        vector<string> arg;

        while (ss >> word) {
            arg.push_back(word);
        }

        if (arg.empty()) {
            continue;
        }

        string command = arg[0]; 

        if (command == "exit") {
            exit(0);  
        } else if (command == "cd") {
            if (arg.size() > 1) {
                change_dir(arg[1].c_str());
            } else {
                go_home();
            }
        } else if (command == "ls") {
            ls();
        }else {
            if (arg.size() > 1) {
                exec(command.c_str(), vector<string>(arg.begin() + 1, arg.end()));  
            } else {
                exec(command.c_str(), {}); 
            }
        }
    }
}