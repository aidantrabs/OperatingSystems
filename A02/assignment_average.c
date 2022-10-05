/**
--------------------------------------
Authors: Aidan Traboulay & Aleksander Neceski
IDs: 200115590 & 
Emails: trab5590@mylaurier.ca & 
--------------------------------------
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <errno.h>


int main(int argc, char *argv[]) { 
    if (argc != 1) { 
        printf("Program must be run with only one arg being fileName")
        exit(EXIT_FAILURE);
    }
    const char *name = "sample_in_grades.txt";	// file name

    int GTA1, GTA2, GTA3;

    // Teacher Process spawns GTA processes
    
    int GTA1 = fork();
    printf("GTA 1 %s \n", GTA1);
    wait();
    if (GTA1 == 0) {
        int GTA2 = fork();
        printf("GTA 2 %s \n", GTA2);
        wait();
        if (GTA2 == 0) {
            int GTA3 = fork();
            printf("GTA3 %s \n", GTA3);
            wait();
        }
    } 

    // Teacher Process 
        // info pull from pipe
        // Spawn GTA Child Process
            // get information 
            // print information

    // GTA Process
        // info pull from pipe
        // spawn child processes and have them write to their memory space 
    
    // TA Process
        // Open and read memory space 
        // Open and read file 
        // Read starting char -> increment to same char at next line up until no more file 
        // Increment total -> get average
        // pass up through pipe
}