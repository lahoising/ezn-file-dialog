#include <iostream>
#include <cstdio>
#include <ezn_file_dialog.h>

namespace ezn
{

constexpr decltype(&popen) SpawnProcess = popen;
constexpr decltype(&pclose) CloseProcess = pclose;

std::string FileDialog()
{
    std::string selectedFilepath = "";

    FILE *pipe = SpawnProcess("zenity --file-selection", "r");
    if(!pipe)
    {
        fprintf(stderr, "Failed to run process\n");
        return "";
    }

    CloseProcess(pipe);

    return selectedFilepath;
}

}