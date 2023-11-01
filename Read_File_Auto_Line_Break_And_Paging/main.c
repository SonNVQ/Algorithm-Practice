#include <stdio.h>
#include <string.h>
#include <malloc.h>

void breakLine(char *input, int lineLength);

const int MAX_LINES = 100;
const int MAX_LINE_LENGTH = 1000;

void readDataFromFile(char *path) {
    //Read file
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Read file error!");
        return;
    }

    char *data[MAX_LINES]; //Array of data
    int n = 0; //Line count

    // Initialize the data array with NULL pointers
    for (int i = 0; i < MAX_LINES; i++) {
        data[i] = NULL;
    }

    char buffer[MAX_LINE_LENGTH];

    //Read each line from file
    while (n < MAX_LINES && fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        //Remove new line(\n) character at the end of line
        buffer[strcspn(buffer, "\n")] = '\0';

        // Allocate memory for data[n]
        data[n] = (char *) malloc(strlen(buffer) + 1);

        //Copy string from buffer to data[n]
        strcpy(data[n], buffer);

        //Reset buffer
        strcpy(buffer, "");

        //Increase n
        n++;
    }

    //Process to print data to console
    int outputLineMaxLength = 0;
    while (outputLineMaxLength < 40 || outputLineMaxLength > 80) {
        printf("Input max length for each line: ");
        scanf("%d", &outputLineMaxLength);
    }

    //Limit to print(each time print only 20 rows)
    int limit = 20;
    if (n < 20)
        limit = n;

    //Start point
    int oldLimit = 0;

    while (limit <= n) {
        //Print from oldLimit to limit
        int i;
        for (i = oldLimit; i < limit; ++i) {
            //If data[i] length is <= max length
            if (strlen(data[i]) <= outputLineMaxLength) {
                printf("%s\n", data[i]);
            } else {
                breakLine(data[i], outputLineMaxLength);
            }
        }

        //If limit equal to n then no need to ask anymore
        if (limit == n)
            break;

        //Read Y/N
        char answer = ' ';
        while (!(answer == 'Y' || answer == 'y' || answer == 'N' || answer == 'n')) {
            printf("Do you want to continue? (Y/N): ");
            fflush(stdin);
            scanf("%c", &answer);
        }
        //If input 'Y' then assign oldLimit to current limit and increase limit, else break
        if (answer == 'Y' || answer == 'y') {
            oldLimit = limit;
            limit += 20;
            if (limit > n)
                limit = n;
        } else {
            break;
        }
    }

}

void breakLine(char *input, int lineLength) {
    int length = strlen(input);
    int currentPosition = 0;

    while (currentPosition < length) {
        int nextBreak = currentPosition + lineLength;
        if (nextBreak >= length) {
            nextBreak = length;
        } else {
            // Find the last whitespace character before the line length limit
            while (nextBreak > currentPosition && input[nextBreak] != ' ') {
                nextBreak--;
            }
            if (nextBreak == currentPosition) {
                // No whitespace found within the line length, so break at the line length.
                nextBreak = currentPosition + lineLength;
            }
        }

        // Print the current line
        for (int i = currentPosition; i < nextBreak; i++) {
            printf("%c", input[i]);
        }

        printf("\n");

        currentPosition = nextBreak + 1;  // Move to the next word
    }
}

int main() {
    readDataFromFile("scada1.txt");
    return 0;
}
