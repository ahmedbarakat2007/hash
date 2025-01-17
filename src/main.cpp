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
#include <csignal>

using namespace std;

void handleSigint(int signal) {
    //do nothing
}

int main() {
    //exec("export", {"SHELL=hash"});
    signal(SIGINT, handleSigint);
    start_shell();
    return 0;
}
