#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <unistd.h>
#include "exec.h"
#include <cstring>
#include <stdlib.h>
#include <sys/wait.h>
#include "dir.h"
#include <sstream>
#include <vector>
#include <string>



using namespace std;

/*string exec(const char* get) {
    array<char, 128> buffer;
    string result;
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(get, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }
    return result;
}*/

// i am not sure how tf does it works but it works anyway :p
void exec(const char* cmd, const vector<string>& args) {
    if (cmd == nullptr || strlen(cmd) == 0) {
        return;
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return;
    }

    if (pid == 0) {  
        close(pipefd[0]); 
        dup2(pipefd[1], STDOUT_FILENO); 
        dup2(pipefd[1], STDERR_FILENO); 
        close(pipefd[1]);  

        vector<const char*> exec_args;
        exec_args.push_back(cmd);
        for (const string& arg : args) {
            exec_args.push_back(arg.c_str());  
        }
        exec_args.push_back(nullptr);

        
        char path[256];
        if (string(cmd).rfind("./", 0) == 0) { 
            snprintf(path, sizeof(path), "%s/%s", get_dir().c_str(), cmd); 
    
            exec_args.insert(exec_args.begin(), "sudo");
            execv("/bin/sudo", (char* const*)exec_args.data());
    
            perror("hash ");
            exit(EXIT_FAILURE); 
        }
        snprintf(path, sizeof(path), "/bin/%s", cmd);
        if (execv(path, (char* const*)exec_args.data()) == -1) {
            snprintf(path, sizeof(path), "/sbin/%s", cmd);
            if (execv(path, (char* const*)exec_args.data()) == -1) {
                perror("hash ");
                exit(EXIT_FAILURE); 
            }
        }
    } else {  
        close(pipefd[1]); 
        char buffer[128];
        ssize_t bytesRead;
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0) {
            buffer[bytesRead] = '\0'; 
            printf("%s", buffer); 
        }
        close(pipefd[0]); 
        waitpid(pid, nullptr, 0); 
    }
}