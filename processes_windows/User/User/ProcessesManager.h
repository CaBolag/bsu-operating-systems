#pragma once
#include<iostream>
#include <windows.h>
#include<winbase.h>
#include <tlhelp32.h>
#include <iomanip>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>

class ProcessesManager {

public:
	void CreateProcessW(LPCSTR process_path, std::wstring argument);
	bool IsActiveProccess(DWORD id);
    bool IsActiveProccess(std::wstring name);

private:
    void UpdateActiveProcessesList();

	std::vector<std::pair<DWORD,std::wstring>> active_processes_;
};

void ProcessesManager::CreateProcessW(LPCSTR process_path, std::wstring argument) {
    STARTUPINFOA startUpInf = { 0 };
    PROCESS_INFORMATION procInf = { 0 };
    if (CreateProcessA(process_path, (char*)argument.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &startUpInf, &procInf)) {
        WaitForSingleObject(procInf.hProcess, INFINITE);
        CloseHandle(procInf.hProcess);
        CloseHandle(procInf.hThread);
    } else {
        std::cout << "Failed to create process: " << GetLastError() << std::endl;
    }
}

void ProcessesManager::UpdateActiveProcessesList() {

    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(PROCESSENTRY32);
    auto hRes = Process32First(hSnapShot, &pEntry);
    active_processes_.clear();
    while (hRes) {
        active_processes_.push_back(std::make_pair(pEntry.th32ProcessID, std::wstring(pEntry.szExeFile)));
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

bool ProcessesManager::IsActiveProccess(DWORD id) {
    UpdateActiveProcessesList();
    for (std::pair<DWORD, std::wstring> process : active_processes_) {
        if (process.first == id) {
            return true;
        }
    }
    return false;
}

bool ProcessesManager::IsActiveProccess(std::wstring name) {
    UpdateActiveProcessesList();
    for (std::pair<DWORD, std::wstring> process : active_processes_) {
        if (process.second == name) {
            return true;
        }
    }
    return false;
}