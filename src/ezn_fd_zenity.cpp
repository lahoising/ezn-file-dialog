#include <iostream>
#include <cstdio>
#include <array>
#include <memory>
#include <ezn_file_dialog.h>
#include <ezn_fd_common.h>

namespace ezn
{

std::string Execute(const char *cmd)
{
    return ExecuteCommand<decltype(&popen),decltype(&pclose)>(cmd, popen, pclose); 
}

std::string FileDialog()
{
    char cmd[] = "zenity --file-selection";
    return Execute(cmd);
}

}