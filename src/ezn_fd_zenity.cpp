#include <iostream>
#include <cstdio>
#include <array>
#include <memory>
#include <ezn_file_dialog.h>

namespace ezn
{

constexpr decltype(&popen) SpawnProcess = popen;
constexpr decltype(&pclose) CloseProcess = pclose;

std::string FileDialog()
{
    std::string selectedFilepath = "";
    std::array<char,128> buffer;

    char cmd[] = "zenity --file-selection";
    std::unique_ptr<FILE,decltype(CloseProcess)> pipe(SpawnProcess(cmd, "r"), CloseProcess);

    if(!pipe)
    {
        fprintf(stderr, "Failed to run process\n");
        return "";
    }

    while((fgets(buffer.data(), buffer.size(), pipe.get())) != nullptr)
        selectedFilepath += buffer.data();

    printf("selected file: %s\n", selectedFilepath.c_str());

    return selectedFilepath;
}

}