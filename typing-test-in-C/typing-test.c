#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>
char *txt = "A quick brown fox jumps over the lazy dog";
#define TXT_LEN 100
typedef unsigned long int timestamp;



//  --- current timestamp in miscroseconds ----
timestamp get_time_microsec() {
    struct timeval time;
    int res = gettimeofday(&time, NULL);
    if(res != 0) { 
        perror("Failed getting the Start Time !");
        return -1;
    }
    unsigned long int timestamp = time.tv_sec * 1000 * 1000 + time.tv_usec;
    // for milliseconds use the below one (but then change formula in WPM)-
    // unsigned long int timestamp = time.tv_sec * 1000 + time.tv_usec/1000;
    return timestamp;
}


// get number of words in the string ---
int word_count(char *s) {
    int count = 0;
    bool word_counted = false;
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] != ' ') {
            if(word_counted == false) {
                count++;
                word_counted = true;
            }
        } else {
            if(word_counted == true) {
                word_counted = false;
            }
        }
    }
    return count;
}


// ----- calculate Accuracy ---
float calc_accuracy(char *ref, char *entered) {
    int n1 = strlen(ref);
    int n2 = strlen(entered);
    int limit = n1;
    int errors = n2-n1;
    if(n1>n2) {
        limit = n2;
        errors = (n1-n2);
    }
    for(int i=0; i<limit; i++) {
        if(ref[i] != entered[i]) {
            errors++;
        }
    }
    if(errors>n1) {
        errors = n1;
    }
    return (((float)n1-(float)errors)/(float)n1) * 100;
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
// -------------- main ---------------

int main(int argc, char *argv[]) {
    printf("Type: \"%s\"\n", txt);
    char typed_buffer[TXT_LEN];

    // Prompt-----
    printf("Press Enter to start Timer: ");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}   // this is to start timer when user only hits enter, and besides that no other character inputted shall be counted in the fgets
    timestamp start_ts = get_time_microsec();
    printf("- Timer Started -\n");
    
    fgets(typed_buffer, TXT_LEN, stdin);
    int buffer_len = strlen(typed_buffer);
    typed_buffer[buffer_len-1] = '\0';

    timestamp end_ts = get_time_microsec();
    timestamp diff_ts = end_ts - start_ts;      // Time taken while typing.

    // --- Calculate WPM ------
    int wc = word_count(typed_buffer);
    float wpm = (float)wc * 60000000.0f / (float)diff_ts;

    // Accuracy--
    float accuracy = calc_accuracy(txt, typed_buffer);


    // OUTPUTS ---

    printf("You entered: \"%s\" \n", typed_buffer);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("WPM: %.2f words/min\n", wpm);


    return 0;
}