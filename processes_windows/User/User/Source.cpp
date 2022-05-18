#include "ProcessesManager.h"
int main() {
	ProcessesManager manager;
	SetEnvironmentVariableA("PROC_TO_KILL", "Telegram;browser");
	LPCSTR killer_process_path="D:\\study\\2\\bsu-operating-systems\\processes_windows\\Killer\\Debug\\Killer.exe";
	manager.CreateProcessW(killer_process_path,L"");
	_putenv("PROC_TO_KILL");

	if (!manager.IsActiveProccess(L"Telegram")) {
		std::cout << "Telegram.exe process is terminaded" << std::endl;
	} else{
		std::cout << "Telegram.exe process is not terminaded" << std::endl;
	}

	if (manager.IsActiveProccess(L"browser")) {
		std::cout << "browser.exe process is terminaded"<<std::endl;
	}
	else {
		std::cout << "browser.exe process is not terminaded" << std::endl;
	}


	std::wstring process_argument;
	while (process_argument != L"end") {
		std::wcin >> process_argument;
		manager.CreateProcessW(killer_process_path,process_argument);

	}

	return 0;
}