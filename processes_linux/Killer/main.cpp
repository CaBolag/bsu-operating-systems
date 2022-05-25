#include<iostream>
#include<sstream>
#include<string>
#include <cstring>


class ProcessKiller{
public:
    static void KillProcessByName(const std::string& process_name);
    static void KillProcessByID(const pid_t& process_id);
};


int main(int argc, char* argv[]) {
    ProcessKiller killer;

    char* environment_variable = getenv("PROC_TO_KILL");
    if (environment_variable != nullptr) {
        std::string environment_variable_str(environment_variable );
        std::stringstream ss(environment_variable);
        while (ss.getline(environment_variable, environment_variable_str.size(), ';')) {
            std::string str(environment_variable);
            killer.KillProcessByName(str);
        }
    }

    if (argc != 3){
        //std::cout << "Must be  2 arguments!\n";
        return 0;
    }

    if (strcmp(argv[1], "name") == 0){
        std::string process_name(argv[2]);
        killer.KillProcessByName(process_name);
    } else if(strcmp(argv[1], "id") == 0){
        killer.KillProcessByID(atoi(argv[2]));
    }
    return 0;
}

void ProcessKiller::KillProcessByName(const std::string& process_name) {
    std::string command_to_kill= "killall " + process_name;
    system(command_to_kill.c_str());
}

void ProcessKiller::KillProcessByID(const pid_t& process_id) {
    std::string command_to_kill="kill " + std::to_string(process_id);
    system(command_to_kill.c_str());
}