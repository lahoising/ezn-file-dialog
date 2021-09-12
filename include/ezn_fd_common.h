#ifndef __EZN_FD_COMMON_H__
#define __EZN_FD_COMMON_H__

#include <string>
#include <memory>

namespace ezn
{
    
template<typename SpawnFn, typename CloseFn>
std::string ExecuteCommand(const char *cmd, SpawnFn SpawnProcess, CloseFn CloseProcess)
{
    std::unique_ptr<FILE,CloseFn> pipe(SpawnProcess(cmd, "r"), CloseProcess);

    if(!pipe)
    {
        fprintf(stderr, "Failed to run process\n");
        return "";
    }

    std::string output;
    std::array<char,128> buffer;
    while((fgets(buffer.data(), buffer.size(), pipe.get())) != nullptr)
        output += buffer.data();

    if(output[output.size()-1] == '\n')
        output = output.substr(0, output.size()-1);
    return output;
}

} // namespace ezn

#endif