#include "file_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int srcport, dstport, seq, ack, flags, len, window_size;

int main(){

	char filePath[256];

//  USER INPUT
                printf("Enter csv file location\n");
                scanf("%s",filePath);
                
// Calculating last line of csv file
        unsigned last_line = count_lines_in_csv(filePath);

	char end = '0';
	for(unsigned int num_lines = 1; end!='1'; num_lines++){
	    field_filter(filePath, &num_lines, last_line, &end, &srcport, &dstport, &seq, &ack, &flags, &len, &window_size);
	    printf("Source Port: %d\t", srcport);
            printf("Destination Port: %d\t", dstport);
            printf("Sequence Number: %d\t", seq);
            printf("Acknowledgment Number: %d\t", ack);
            printf("Flags: 0x%x\t", flags);
            printf("Length: %d\t", len);
            printf("Window Size: %d\n", window_size);
	}
	
	printf("\033[0;35mNo more messages in %s\033[0m\n", filePath);
	
}
