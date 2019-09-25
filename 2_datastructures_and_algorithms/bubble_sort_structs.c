#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct student {
    char * name;
    char mark;
};

void bubble_sort_students(struct student students[], int size){
    for(unsigned int i = 0; i < size; i++){
        bool sorted = true;
        for(unsigned int j = 0; j < size-i-1; j++) {
            if (students[j].mark > students[j + 1].mark) {
                sorted = false;
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
        if(sorted)
            break;
    }
}

int main() {
    
    struct student students[] = {
        {"Mindaugas",9},
        {"Marius",8},
        {"Marytė",10},
        {"Mykolas",7}
    };
    
    printf("%s", "Printing the array of structs before sorting: ");
    for(unsigned int i = 0; i < sizeof(students)/sizeof(struct student); i++)
        printf("%s - %d ; ", students[i].name, students[i].mark);
    printf("\n");
    
    bubble_sort_students(students, sizeof(students)/sizeof(struct student));
    
    printf("%s", "Printing the array of structs after sorting: ");
    for(unsigned int i = 0; i < sizeof(students)/sizeof(struct student); i++)
        printf("%s - %d ; ", students[i].name, students[i].mark);
    
    return EXIT_SUCCESS;
}
