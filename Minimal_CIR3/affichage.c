#include "affichage.h"

#include <stdio.h>

#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)

int FileExists(LPCTSTR szPath) {
    DWORD dwAttrib = GetFileAttributes(szPath);

    return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
            !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

#else
#include <unistd.h>

int FileExists(char *szPath) { return access(szPath, F_OK) != -1; }

#endif

void affichage(oxy myOxy) {
    if (access(".verrouData", F_OK) != -1) {
        // Sad
    } else {
        FILE *fp = fopen(".verrouData", "w");
        fclose(fp);

        fp = fopen("Data.txt", "w");

        fprintf(fp, "%i\n%i", myOxy.spo2, myOxy.pouls);

        fclose(fp);

        remove(".verrouData");
    }
}
