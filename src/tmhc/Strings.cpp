#include "common.h"

struct Strings {
    char* table;
    int numStrings;

    Strings(char* pTable, int count) {
        table = pTable;
        numStrings = count;
    }
};

extern char DNAS_EULA_TEXT[];
extern char ENGLISH_STRINGS[];

Strings g_strings(ENGLISH_STRINGS, 0x33b);
Strings g_DNAS_strings(DNAS_EULA_TEXT, 5);
