#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================================
   BCA C-PROGRAMMING MASTER ARCHIVE
   =========================================================
   This file contains the complete journey from Basics to 
   Advanced System Development.
*/

// ---------------------------------------------------------
// DAY 3: FUNCTIONS 
// Topic: Definition, Parameters, and Return Values
// ---------------------------------------------------------
int calculate_area(int lenght, int breadth) {
  int area = lenght * breadth;
  return area;
}

// ---------------------------------------------------------
// DAY 5 & 6: ADVANCED STRUCTURES
// Topic: Nested Structures (Struct inside a Struct)
// ---------------------------------------------------------
struct allmarks {
  int Eng;
  int Math;
  int ip;
};

struct std_var {
  char name[50];
  int roll;
  struct allmarks amarks; // Nested structure
};

// ---------------------------------------------------------
// FINAL GRADUATION TASK: FUNCTIONS & POINTERS
// Topic: Passing Pointer to Function & File I/O
// ---------------------------------------------------------
int avg_save(struct std_var *savg, int nstd, FILE *file) {

  for (int i = 0; i < nstd; i++) {
    // Pointer Logic: Accessing data via savg[i]
    int total = savg[i].amarks.Eng + savg[i].amarks.Math + savg[i].amarks.ip;
    float avg = total / 3.0;

    // Writing to Permanent Storage (File Handling)
    fprintf(file, "Student %d\n", i + 1);
    fprintf(file, "Name- %s\n", savg[i].name);
    fprintf(file, "Roll no.- %d\n", savg[i].roll);
    fprintf(file, "Eng marks- %d\n", savg[i].amarks.Eng);
    fprintf(file, "Maths marks- %d\n", savg[i].amarks.Math);
    fprintf(file, "IP marks- %d\n", savg[i].amarks.ip);
    fprintf(file, "Total marks- %d \n", total);
    fprintf(file, "Average marks- %f\n\n", avg); // Labeled as Average for clarity
  }

  fclose(file);
  return 0;
}

int main(void) {

  /* ---------------------------------------------------------
  DAY 1: THE BASICS
  Topic: Basic Input/Output (I/O)
  ---------------------------------------------------------
  printf("enter the year you are");
  int year;
  scanf("%d",&year);
  printf("ohh you are in %d",year);
  */

  /*
  ---------------------------------------------------------
  DAY 2: CONTROL FLOW
  Topic: Conditional Statements & Logical Operators
  ---------------------------------------------------------
  // (If-Else Ladder, &&, and || logic went here)
  */

  /* ---------------------------------------------------------
  DAY 3: LOOPS
  Topic: For/While Loops & Mathematical Logic
  ---------------------------------------------------------
  // (Multiplication tables and choice loops went here)
  */

  /*
  ---------------------------------------------------------
  DAY 4: ARRAYS & COLLECTIONS
  Topic: Integer Arrays and Strings (shop_name)
  ---------------------------------------------------------
  */

  /*
  ---------------------------------------------------------
  DAY 5: STRUCTURES & FILES (PART 1)
  Topic: Single Structs and static Array of Structs
  ---------------------------------------------------------
  */

  // ---------------------------------------------------------
  // FINAL GRADUATION TASK: THE COMPLETE SYSTEM
  // Topics: FILE I/O, DMA (malloc), and POINTERS
  // ---------------------------------------------------------

  FILE *file;
  file = fopen("students.txt", "w");

  int nstd = 0;
  printf("enter no. of students:-");
  scanf("%d", &nstd);

  // TOPIC: Dynamic Memory Allocation (DMA)
  // Reserves memory based on user input 'nstd'
  struct std_var *stdp = (struct std_var*)malloc(nstd * sizeof(struct std_var));

  // Input Loop
  for (int i = 0; i < nstd; i++) {
    printf("----------------------\n");
    printf("Enter the student %d name- ", i + 1);
    scanf("%s", stdp[i].name);
    printf("Enter the Roll number- ");
    scanf("%d", &stdp[i].roll);
    printf("Enter the Eng marks:- ");
    scanf("%d", &stdp[i].amarks.Eng);
    printf("Enter the Maths marks:- ");
    scanf("%d", &stdp[i].amarks.Math);
    printf("Enter the IP marks:- ");
    scanf("%d", &stdp[i].amarks.ip);
  }

  fprintf(file, "The all data of students \n");

  // TOPIC: Calling Function with Pointer
  avg_save(stdp, nstd, file);

  // TOPIC: Memory Cleanup
  free(stdp); 

  printf("\nSystem Finished. Data saved and memory freed.\n");

  return 0;
}
