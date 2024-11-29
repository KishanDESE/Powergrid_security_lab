#ifndef file_handling
#define file_handling
#include <stdio.h>


#define MAX_LINE_LENGTH 1024
#define DATA_OUTPUT_NO 3  // We will return sqNum , stNum, and timestamp

//////////////////////////////////////////////////////////////////////////////////
// University: Indian Institute of science 
// Research Project: Advanced Intrusion detection system
// Author: Kishan Baranwal
//
// Create Date: 28.08.2024 07:17:59
// Design Name: file_handling.h
// Target Devices: Linux, Windows systems with gcc compiler
// Description: 
//
// Dependencies: 
// 
// Revision:
// Please provide suggestions or modifications as necessary, whether made by yourself or anyone else using the library
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


// Function to count the number of lines in the CSV file
unsigned count_lines_in_csv(const char *filePath);

// Function to extract field values
void field_filter(const char *filePath, unsigned *num_lines, unsigned last_line, char *end, int *srcport, int *dstport, int *seq, int *ack, int *flags, int *len, int *window_size);

void file_close();


#endif
