#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "NativeInjector.h"

DWORD GetProcessIdByWindowName(const char* windowName) {
    HWND hWnd = FindWindowA(NULL, windowName);
    if (hWnd == NULL) {
        return 0;
    }

    DWORD processId;
    GetWindowThreadProcessId(hWnd, &processId);

    return processId;
}

int main(int argc, char* argv[]) {
    printf("=+= =================== =+=\nDevilSight client injector\nversion: testing prototype\n=+= =================== =+=\n\n");

    if (argc != 2) {
        printf("Usage: %s <path_to_dll>\n", argv[0]);
        return 1;
    }

    char windowName[256];
    printf("Enter client window name: ");
    fgets(windowName, sizeof(windowName), stdin);

    // Remove the newline character at the end of the input
    size_t len = strlen(windowName);
    if (len > 0 && windowName[len - 1] == '\n') {
        windowName[len - 1] = '\0';
    }

    DWORD processId = GetProcessIdByWindowName(windowName);

    if (processId == 0) {
        printf("Window not found\n");
        return 1;
    }

    LPCSTR dllPath = NULL;
    HANDLE hTargetProcess = NULL;

    dllPath = argv[1];

    hTargetProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION |
        PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
        FALSE, processId);

    RtlCreateUserThread(hTargetProcess, dllPath);

    printf("Client has been injected successfully.\n");

    return 0;
}
