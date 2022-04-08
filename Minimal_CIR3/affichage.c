#include "affichage.h"

#include <stdio.h>

/**
 * conditional compilation for windows and linux
 */
#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)

/**
 * @brief
 *
 * @param szPath
 * @return int
 */
int FileExists(LPCTSTR szPath)
{
    DWORD dwAttrib = GetFileAttributes(szPath);

    return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
            !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

#else
#include <unistd.h>
/**
 * @brief
 *
 * @param szPath
 * @return int
 */
int FileExists(char *szPath) { return access(szPath, F_OK) != -1; }

#endif

void affichage(oxy myOxy)
{
    // Check if .verrouData exists
    // If it exits, it means that we are already writting to the filke or the java interface is reading the file
    // So we only write into the file if .verrouData don't exists
    if (access(".verrouData", F_OK) == -1)
    {
        FILE *fp = fopen(".verrouData", "w");

        if (fp == NULL)
        {
            return;
        }

        fclose(fp);

        fp = fopen("Data.txt", "w");

        fprintf(fp, "%i\n%i", myOxy.spo2, myOxy.pouls);

        fclose(fp);

        int ret, tries = 0;
        do {
            ret = remove(".verrouData");
            tries++;
        } while(ret != 0 && tries < 5);
    }
}
