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
#include "ls.h"

using namespace std;
namespace fs = std::filesystem;

void print_files(const char* file, const char* color){
    cout << "║" << endl;
    cout << "╠══ ";
    print_color(file, color, "endl");
    //cout << "║" << endl;
}
bool is_executable(const fs::path& p) {
    auto perms = fs::status(p).permissions();
    return (perms & fs::perms::owner_exec) != fs::perms::none ||
           (perms & fs::perms::group_exec) != fs::perms::none ||
           (perms & fs::perms::others_exec) != fs::perms::none;
}
void ls() {
    std::string path = fs::current_path().string();
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.path().filename().string().front() == '.' ){
            //do not print
        }
        else if (entry.is_directory() && entry.path().filename().string().front() == '.' ){
            //do not print
        }
        else if (entry.is_directory()) {
            print_files(entry.path().filename().c_str(), "bright_cyan");
        }
        else if (is_executable(entry) || entry.path().extension() == ".apk"){
            print_files(entry.path().filename().c_str(), "bright_green");
        }
        else if (entry.path().filename() == "Makefile" ||
            entry.path().filename() == "meson.build" ||
            entry.path().filename() == "CMakeLists.txt" ||
            entry.path().filename() == "CMakeCache.txt") {
            print_files(entry.path().filename().c_str(), "bright_yellow");
        }
        else if (entry.path().extension() == ".cpp" ||
            entry.path().extension() == ".cc" ||
            entry.path().extension() == ".cxx" ||
            entry.path().extension() == ".h" ||
            entry.path().extension() == ".hpp" ||
            entry.path().extension() == ".hxx" ||
            entry.path().extension() == ".c" ||
            entry.path().extension() == ".py" ||
            entry.path().extension() == ".java" ||
            entry.path().extension() == ".js" ||
            entry.path().extension() == ".mjs" ||
            entry.path().extension() == ".cjs" ||
            entry.path().extension() == ".ts" ||
            entry.path().extension() == ".tsx" ||
            entry.path().extension() == ".html" ||
            entry.path().extension() == ".htm" ||
            entry.path().extension() == ".css" ||
            entry.path().extension() == ".php" ||
            entry.path().extension() == ".rb" ||
            entry.path().extension() == ".rs" ||
            entry.path().extension() == ".sh" ||
            entry.path().extension() == ".bash" ||
            entry.path().extension() == ".zsh" ||
            entry.path().extension() == ".ksh" ||
            entry.path().extension() == ".go" ||
            entry.path().extension() == ".swift" ||
            entry.path().extension() == ".kt" ||
            entry.path().extension() == ".kts" ||
            entry.path().extension() == ".scala" ||
            entry.path().extension() == ".sbt" ||
            entry.path().extension() == ".sql" ||
            entry.path().extension() == ".json" ||
            entry.path().extension() == ".yaml" ||
            entry.path().extension() == ".yml" ||
            entry.path().extension() == ".jl") {
                print_files(entry.path().filename().c_str(), "cyan");
        }
        else if (entry.path().extension() == ".jpg" ||
            entry.path().extension() == ".jpeg" ||
            entry.path().extension() == ".jpe" ||
            entry.path().extension() == ".jfif" ||
            entry.path().extension() == ".png" ||
            entry.path().extension() == ".gif" ||
            entry.path().extension() == ".bmp" ||
            entry.path().extension() == ".dib" ||
            entry.path().extension() == ".tif" ||
            entry.path().extension() == ".tiff" ||
            entry.path().extension() == ".webp" ||
            entry.path().extension() == ".svg" ||
            entry.path().extension() == ".ico" ||
            entry.path().extension() == ".heic" ||
            entry.path().extension() == ".heif" ||
            entry.path().extension() == ".raw" ||
            entry.path().extension() == ".cr2" ||
            entry.path().extension() == ".nef" ||
            entry.path().extension() == ".orf" ||
            entry.path().extension() == ".sr2" ||
            entry.path().extension() == ".arw" ||
            entry.path().extension() == ".dng") {
                print_files(entry.path().filename().c_str(), "bright_blue"); 
        }
        else if (entry.path().extension() == ".so"){
            print_files(entry.path().filename().c_str(), "green"); 
        }
        else if (entry.path().extension() == ".doc" ||
            entry.path().extension() == ".docx" ||
            entry.path().extension() == ".dot" ||
            entry.path().extension() == ".dotx" ||
            entry.path().extension() == ".xls" ||
            entry.path().extension() == ".xlsx" ||
            entry.path().extension() == ".xlsm" ||
            entry.path().extension() == ".csv" ||
            entry.path().extension() == ".ppt" ||
            entry.path().extension() == ".pptx" ||
            entry.path().extension() == ".pps" ||
            entry.path().extension() == ".ppsx" ||
            entry.path().extension() == ".pdf" ||
            entry.path().extension() == ".txt" ||
            entry.path().extension() == ".log" ||
            entry.path().extension() == ".md" ||
            entry.path().extension() == ".rtf" ||
            entry.path().extension() == ".odt" ||
            entry.path().extension() == ".ods" ||
            entry.path().extension() == ".odp" ||
            entry.path().extension() == ".epub" ||
            entry.path().extension() == ".mobi" ||
            entry.path().extension() == ".azw" ||
            entry.path().extension() == ".azw3") {
            print_files(entry.path().filename().c_str(), "bright_red"); 
        }
        else if (entry.path().extension() == ".zip" ||
            entry.path().extension() == ".tar" ||
            entry.path().extension() == ".gz" ||
            entry.path().extension() == ".gzip" ||
            entry.path().extension() == ".bz2" ||
            entry.path().extension() == ".bzip2" ||
            entry.path().extension() == ".xz" ||
            entry.path().extension() == ".lzma" ||
            entry.path().extension() == ".7z" ||
            entry.path().extension() == ".rar" ||
            entry.path().extension() == ".iso" ||
            entry.path().extension() == ".cab" ||
            entry.path().extension() == ".arj" ||
            entry.path().extension() == ".lzh" ||
            entry.path().extension() == ".lz4" ||
            entry.path().extension() == ".img" ||
            entry.path().extension() == ".zst") {
                print_files(entry.path().filename().c_str(), "red"); 
        }
        else if (entry.path().extension() == ".vhd" ||
            entry.path().extension() == ".vhdx" ||
            entry.path().extension() == ".qcow2" ||
            entry.path().extension() == ".vdi" ||
            entry.path().extension() == ".vmdk" ||
            entry.path().extension() == ".hdd" ||
            entry.path().extension() == ".raw") {
                print_files(entry.path().filename().c_str(), "magenta");
        }
        else{
            print_files(entry.path().filename().c_str(), "white");
        }
    }
    cout << "║" << endl;
}