#pragma once
#pragma once
#include <iostream>
#include <windows.h>
#include <WtsApi32.h>
#include <vector>
#include <string>
#include <sstream>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>


class ProcessKiller
{
private:
	std::vector<DWORD> ids_to_kill_processes_;
	wchar_t environment_variable_[1000];


public:
	void FindProcessesByName(const wchar_t* name);
	void AddProcessId(DWORD id);
	void KillAllProcesses();
};


void ProcessKiller::FindProcessesByName(const wchar_t* process_name)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32  pEntry;
	pEntry.dwSize = sizeof(PROCESSENTRY32);
	bool hRes = Process32First(hSnapShot, &pEntry);
	std::wstring w_str(process_name);
	w_str += L".exe";
	while (hRes) {
		if (std::wcscmp((wchar_t*)pEntry.szExeFile, w_str.c_str()) == 0) {
			ids_to_kill_processes_.push_back(pEntry.th32ProcessID);
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
}


void ProcessKiller::AddProcessId(DWORD id) {
	ids_to_kill_processes_.push_back(id);
}

void ProcessKiller::KillAllProcesses() {

	if (GetEnvironmentVariableW(L"PROC_TO_KILL", environment_variable_, sizeof(environment_variable_)) != 0) {
		std::wstring w_str(environment_variable_);
		std::wstringstream w_string_stream(w_str);
		std::wstring variable;
		wchar_t delimiter = ';';
		while (std::getline(w_string_stream, variable, delimiter)) {
			variable += L".exe";
			FindProcessesByName(variable.c_str());
		}
	}

	for (int i = 0; i < ids_to_kill_processes_.size(); ++i) {
		DWORD current_id = ids_to_kill_processes_[i];
		HANDLE h_process_to_kill = OpenProcess(PROCESS_ALL_ACCESS, FALSE, current_id);
		if (TerminateProcess(h_process_to_kill, 0)) {
			std::cout << "Process " << current_id << " terminated" << std::endl;
		}
		else {
			std::cout << "Failed to terminate: id = " << current_id << std::endl;
		}
		CloseHandle(h_process_to_kill);
	}
}
