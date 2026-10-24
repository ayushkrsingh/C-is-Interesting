#include <stdio.h>
#include <string.h>
char *txt = "A quick brown fox jumps over the lazy dog.";
#define TXT_LEN 100

int main() {
    printf("Type: \"%s\"\n", txt);
    char typed_buffer[TXT_LEN];
    fgets(typed_buffer, TXT_LEN, stdin);
    typed_buffer[strcspn(typed_buffer, "\n")] = '\0';
    
    printf("You entered: \"%s\"", typed_buffer);
    return 0;
}