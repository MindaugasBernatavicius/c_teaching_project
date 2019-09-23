#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// TODO ::
//  1. Add logic to convert int to string and float to string for the person_to_string method.
//  2. Implement a loop to loop through all the people and call the _to_string() method.
//  3. Measure the performance of my implementation
//  4. Check this library to improve the example: https://github.com/boyerjohn/rapidstring
//  5. Implement quick sort for sorting array of person structs

typedef struct {
    char * fname;
    char * lname;
    unsigned char age;
    unsigned char height;
    float total_balance;
} person;

int string_length(char * s) {
   int c = 0;
   while (s[c] != '\0')
      c++;
      
   return c;
}

char * person_to_sring(person p){
    // ref: https://stackoverflow.com/questions/2218290/concatenate-char-array-in-c
    char * str;
    if(!(str = malloc(
            string_length((char[]){"{ firstname: "}) + string_length(p.fname) +
            string_length((char[]){", lastname: "}) + string_length(p.lname) 
            + string_length((char[]){" }"}) + 1)))
    {
        fprintf(stderr,"Insufficient memory");
        exit(EXIT_FAILURE);
    }

    strcat(strcat(str, (char[]){"{ firstname: "}), p.fname);
    strcat(strcat(str, (char[]){", lastname: "}), p.lname);
    strcat(str, (char[]){" }"});
    
    printf("Size of string: %d\n", string_length(str));
    return str;
}

int main() {
    // another way to initialize an array of structures
    // my_data data[]={
    //     { .name = "Peter" },
    //     { .name = "James" },
    //     { .name = "John" },
    //     { .name = "Mike" }
    // };
    
    // initialize a bunch of people using the possition independent struct initialization
    person jack = { .fname = "Jack", .lname = "Black", .age = 23, .height = 179, .total_balance = 20011.50 };
    person tom = { .fname = "Tom", .lname = "Claw", .age = 34, .height = 169, .total_balance = 199.50 };
    person blake = { .fname = "Blake", .lname = "Banche", .age = 65, .height = 187, .total_balance = 4566.50 };
    person bart = { .fname = "Bart", .lname = "Simpson", .age = 15, .height = 166, .total_balance = 0.50 };
    
    // initialize a struct using possition dependent struct initialization
    person mindaugas = { "Mindaugas", "Bernatavičius", 30, 193, 150000 };
    person a = { "c", "d", 30, 193, 150000 };
    
    // initialize an array of structs w/ mixed notation
    person people[] = { 
        jack, tom, blake, bart, mindaugas, 
        { .fname = "Beata", .lname = "Nicholson", .age = 44, .height = 166, .total_balance = 0.50 }
    };

    printf("Age of %s is %d\n", mindaugas.fname, mindaugas.age);
    
    // call the to_string function
    char * person_str = person_to_sring(mindaugas);
    printf(">> %s", person_str);
    
    free(person_str);
    return EXIT_SUCCESS;
}
