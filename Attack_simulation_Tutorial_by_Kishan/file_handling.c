#include "file_handling.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

FILE *file;

unsigned count_lines_in_csv(const char *filePath) {

    int count = 0;
    char c;

    // Open the CSV file
    file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error : opening file");
        return -1;  // Return -1 to indicate an error
    }

    // Read the file character by character
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;  // Increment count for each newline character
        }
    }

    // Close the file
    fclose(file);

    return count;
}

//For tracking missing values
char * strtok_single (char * str, char const * delims)
{
  static char  * src = NULL;
  char  *  p,  * ret = 0;

  if (str != NULL)
    src = str;

  if (src == NULL)
    return NULL;

  if ((p = strpbrk (src, delims)) != NULL) {
    *p  = 0;
    ret = src;
    src = ++p;

  } else if (*src) {
    ret = src;
    src = NULL;
  }

  return ret;
}


void field_filter(const char *filePath, unsigned *num_lines, unsigned last_line, char *end, int *srcport, int *dstport, int *seq, int *ack, int *flags, int *len, int *window_size) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    
    file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Skip lines until reaching the line number stored in *num_lines
    for (unsigned i = 0; i < (*num_lines); i++) {
        if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
            fclose(file);
        }
    }
   
    
    // File field extraction
    if ((*num_lines) >= last_line) {
        fclose(file);
        *end = '1';
        return;
    }
        else {
        // Initialize variables as default missing value
        *srcport = -1;
        *dstport = -1;
        *seq = -1;
        *ack = -1;
        *flags = -1;
        *len = -1;
        *window_size = -1;

        // Extract fields from the current line
        if (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
            char *delims = ",";
            char *token;

            // Use strtok_single to tokenize the line
            token = strtok_single(line, delims);
            if (token) {
                if (sscanf(token, "%d", srcport) != 1) {
                    *srcport = -1;
                }
            }
            token = strtok_single(NULL, delims);
            if (token) {
                if (sscanf(token, "%d", dstport) != 1) {
                    *dstport = -1;
                }
            }
            token = strtok_single(NULL, delims);
            if (token) {
                if (sscanf(token, "%d", seq) != 1) {
                    *seq = -1;
                }
            }
            token = strtok_single(NULL, delims);
            if (token) {
                if (sscanf(token, "%d", ack) != 1) {
                    *ack = -1;
                }
            }
            token = strtok_single(NULL, delims);
            if (token) {
                if (sscanf(token, "0x%x", flags) != 1) {
                    *flags = -1;
                }
            }
            token = strtok_single(NULL, delims);
            if (token) {
                if (sscanf(token, "%d", len) != 1) {
                    *len = -1;
                }
            }
            token = strtok_single(NULL, delims);
            if (token) {
                if (sscanf(token, "%d", window_size) != 1) {
                    *window_size = -1;
                }
            }
        }
    }

    fclose(file);
}

void file_close(){
    fclose(file);
}
