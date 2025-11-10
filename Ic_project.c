#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int match(const char *a, const char *b, int ignoreCase) {
    while (*a && *b) {
        if (ignoreCase) {
            if (tolower(*a) != tolower(*b)) return 0;
        } else {
            if (*a != *b) return 0;
        }
        a++; b++;
    }
    return (*b == '\0');
}

int isWholeWord(const char *str, int start, int end) {
    char before = (start == 0) ? ' ' : str[start - 1];
    char after = str[end];
    return (!isalnum(before) && !isalnum(after));
}

void replaceLine(char *line, const char *old, const char *new, int ignoreCase, int wholeWord, FILE *out) {
    int i = 0, oldLen = strlen(old);
    while (line[i]) {
        if ((ignoreCase ? tolower(line[i]) == tolower(old[0]) : line[i] == old[0])) {
            if (match(&line[i], old, ignoreCase)) {
                int end = i + oldLen;
                if (!wholeWord || isWholeWord(line, i, end)) {
                    fputs(new, out);
                    i += oldLen;
                    continue;
                }
            }
        }
        fputc(line[i++], out);
    }
}

int main() {
    char inFile[50], outFile[50], old[30], new[30], ch;
    int ignoreCase = 0, wholeWord = 0;

    printf("Enter input file name: ");
    scanf("%s", inFile);
    printf("Enter output file name: ");
    scanf("%s", outFile);
    printf("Enter word to replace: ");
    scanf("%s", old);
    printf("Enter new word: ");
    scanf("%s", new);

    printf("Case-insensitive replacement? (y/n): ");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') ignoreCase = 1;

    printf("Whole-word replacement only? (y/n): ");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y') wholeWord = 1;

    FILE *in = fopen(inFile, "r");
    FILE *out = fopen(outFile, "w");
    if (!in || !out) {
        printf("Error opening files!\n");
        return 1;
    }

    char line[MAX];
    while (fgets(line, sizeof(line), in))
        replaceLine(line, old, new, ignoreCase, wholeWord, out);

    fclose(in);
    fclose(out);

    printf("Replacement done. Output in %s\n", outFile);
    return 0;
}
