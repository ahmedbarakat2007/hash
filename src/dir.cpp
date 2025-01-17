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
#include <filesystem>
#include "dir.h"
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

namespace fs = std::filesystem;
using namespace std;

string get_home(){
    struct passwd *pw = getpwuid(getuid());
    return pw->pw_dir;
}

void print_dir(){
    const size_t size = 1024; 
    char current_dir[size];        
    if (getcwd(current_dir, size) != NULL) {
        if (filesystem::current_path() == get_home())
        {
            cout << "\033[30;47m" << ":~/" << "\033[0m";
        }else{
            cout << "\033[30;47m" << ":" << filesystem::current_path() << "\033[0m";
        }
    } 
    else {
        cerr << "hash : Error getting current working directory" << endl;
        exit(0);
    }
}
void change_dir(const char* dir){
    if (strcmp(dir, "~/") == 0){
        fs::current_path(get_home());
        return;
    }
    if (fs::exists(dir) && fs::is_directory(dir)) {
        fs::current_path(dir);
    }else{
        cerr << "cd : No Such Directory" << endl;
    }

}

string get_dir(){
    return filesystem::current_path();
}
