#include <iostream>
#include <windows.h> 
#include <stdio.h>
#include <string>

typedef void(__cdecl* MYPROC)(double,double,std::string&);

int main(void)
{
    std::string result;
    HINSTANCE hinstLib;
    MYPROC ProcAdd;
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

    hinstLib = LoadLibrary(TEXT("../../Vector/Debug/Vector.dll"));

    if (hinstLib != NULL)
    {
        MYPROC ProcAdd = (MYPROC)GetProcAddress(hinstLib, "TransformToPolarVector");

        if (NULL != ProcAdd)
        {
            fRunTimeLinkSuccess = TRUE;
            (ProcAdd)(1.,0.,result);
        }
        fFreeResult = FreeLibrary(hinstLib);
    }

    if (fRunTimeLinkSuccess)
    {
        std::cout << "" << result << "\n";
    }
    else {
        std::cout << "RunTimeLinkError!" << result << "\n";
    }
    return 0;
}