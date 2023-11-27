/*
2MP3 QUIZ-6 : THE FINAL ROUND

- You are provided a list of car names, a list of max speeds (in mph) and a list of prices (in $).
- The first line of the names.txt file contains the number of cars.
- You are also provided a 'car' structure, which has the following members:

struct car {
   char name[20];
   int max_speed;
   int price;
};

- You have to read the data from the files and store them in the structure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car {
   char name[20];
   int max_speed;
   int price;
};

/*
PART-A : (5 marks)
- You have to sort the cars in the following order:
   - First sort by price (ascending)
   - Then sort by max_speed (descending) ONLY IF the prices are equal.

-  code to print the sorted list of cars in the following format has been provided to you:
      <name> <max_speed> <price>
- You also have to output the sorted list of cars in a file named 'output_a.txt' INSIDE THE MAIN function.

*/

// function which sorts the cars and returns a list of sorted cars:
struct car* sort_cars(struct car* cars, int n)
{
   /* write your sorting code here:
   .
   .
   .
   */

   // return the sorted list of cars:
   return cars;
}

/*
PART-B : (5 marks)
- Find the fastest car & the slowest car, the cheapest & the most expensive car.
- Ouput the results in a txt file named 'output_b.txt' in the following format within the same function:
      Fastest car: <name> <max_speed> <price>
      Slowest car: <name> <max_speed> <price>
*/

// function which prints/outputs the fasters, slowest, cheapest and the most expensive cars:
void find_cars(struct car* cars, int n, int index)
{
   struct car fastest_car = cars[0]; // default value
   struct car slowest_car = cars[0]; // default value

   /* write your code here:
   .
   .
   .
   */

   // print the results to the console:
   printf("\nResults:\n");
   printf("Fastest car: < Build: %s, Top-Speed: %d mph, Price: %d >\n", fastest_car.name, fastest_car.max_speed, fastest_car.price);
   printf("Slowest car: < Build: %s, Top-Speed: %d mph, Price: %d >\n", slowest_car.name, slowest_car.max_speed, slowest_car.price);

   // write the results to the output file:
   FILE *fp;
   char output_file_name[100];
   sprintf(output_file_name, "output_b_%d.txt", index);
   fp = fopen(output_file_name, "w");

   /* 
   (write your code here to) output the results to the file in the same way as printed to the console above:
   .
   .
   .
   .
   */ 

   fclose(fp);
}

// main function:
int main(int argc, char const *argv[]) {
   // check if the user provided the correct number of command-line arguments
   if (argc != 5) {
      printf("Usage: ./program_name index names_file max_speeds_file prices_file\n");
      return 1;
   }

   // used for testing, use 1 for testing your code with the sample input files:
   int index = atoi(argv[1]);

   // read input data from the text files:
   FILE *fp1, *fp2, *fp3;
   fp1 = fopen(argv[2], "r");
   fp2 = fopen(argv[3], "r");
   fp3 = fopen(argv[4], "r");

   if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
      printf("Error in opening the files!\n");
      exit(1);
   }

   int n = 1; // default value for number of cars

   /*
   (write your code here for) reading the number of cars ie. first line of the names.txt file:
   .
   .
   */

   struct car* cars = (struct car*)malloc(n * sizeof(struct car));
   cars[0].name[0] = '\0'; // default value for name
   cars[0].max_speed = 0; // default value for max_speed
   cars[0].price = 0; // default value for price

   /*
   (write your code here for) storing the all the cars in a list of structures:
   .
   .
   .
   .
   */


   // close the files:
   fclose(fp1), fclose(fp2), fclose(fp3);

   // print the list of cars:
   printf("\nList of cars:\n");
   for (int i = 0; i < n; i++) {
      printf("< Build: %s, Top Speed: %d mph, Price: $%d >\n", cars[i].name, cars[i].max_speed, cars[i].price);
   }

   // sort the cars using the function you wrote:
   struct car* sorted_cars = sort_cars(cars, n);

   // print the sorted list of cars:
   printf("\nSorted list of cars:\n");
   for (int i = 0; i < n; i++) {
      printf("< Build: %s, Top Speed: %d mph, Price: $%d >\n", sorted_cars[i].name, sorted_cars[i].max_speed, sorted_cars[i].price);
   }

   // write the sorted list of cars to the output file:
   FILE *fp4;
   char output_file_name[100];
   sprintf(output_file_name, "output_a_%d.txt", index);
   fp4 = fopen(output_file_name, "w");

   /*
   write the sorted list of cars to the file in the same way as printed to the console above:
   .
   .
   .
   */ 

   fclose(fp4);

   // find and print fastest and slowest cars
   find_cars(cars, n, index);

   return 0;
}