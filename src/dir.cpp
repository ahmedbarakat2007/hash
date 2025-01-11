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

void print_dir(){
    const size_t size = 1024; 
    char current_dir[size];        
    if (getcwd(current_dir, size) != NULL) {
        cout << "\033[30;47m" << ":" << filesystem::current_path() << "\033[0m";
    } 
    else {
        cerr << "hash : Error getting current working directory" << endl;
        exit(0);
    }
}
void change_dir(const char* dir){
    if (strcmp(dir, "~/") == 0){
        struct passwd *pw = getpwuid(getuid());
        const char *homedir = pw->pw_dir;
        fs::current_path(homedir);
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