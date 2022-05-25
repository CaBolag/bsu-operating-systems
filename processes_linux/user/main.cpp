#include<iostream>
#include <cstdlib>

std::string KILL_PATH = "../../Killer/cmake-build-debug/Killer";

void KillByName(std::string name) {
    system((KILL_PATH + " name " + name).c_str());
}
void KillById(std::string id) {
    system((KILL_PATH+ " id " + id).c_str());
}

int main() {
    if (setenv("PROC_TO_KILL", "Telegram,firefox", 0) == -1) {
        std::cout << "Error while environment variable creating\n";
    }

    KillByName("");
    unsetenv("PROC_TO_KILL");

    int flag;
    std::string value;

    while(flag!=0) {
        std::cout<<"Enter flag to kill process: ";
        std::cin>>flag;
        switch (flag) {
            case 1: {
                std::cout<<"Enter name: ";
                std::cin >> value;
                KillByName(value);
                break;
            }

            case 2: {
                std::cout<<"Enter id: ";
                std::cin >> value;
                KillById(value);
                break;
            }
            default:
                break;
        }
    }

    return 0;
}