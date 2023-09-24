// dllmain.cpp : Defines the entry point for the DLL application.
#include "windows.h"
#include "Java.h"
#include "Cheats.h"

void initialise() 
{
    jsize count;

    if (JNI_GetCreatedJavaVMs(&ct.vm, 1, &count) != JNI_OK || count == 0)
        return;

    jint rest = ct.vm->GetEnv((void**)&ct.env, JNI_VERSION_1_6);

    if (rest == JNI_EDETACHED)
        rest = ct.vm->AttachCurrentThread((void**)&ct.env, nullptr);

    if (ct.env != nullptr)
        runModules();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)initialise, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

