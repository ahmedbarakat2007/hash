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

using namespace std;

int main() {
    //exec("export", {"SHELL=hash"});
    start_shell();
    return 0;
}