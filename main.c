#include <stdio.h>
#include <stdlib.h>

char* intToBinaryString(int number);

int main()
{
   int integer[3] = {0, 0, 0};                                          //Where we will store input integers
   char** string = (char**)malloc(3*sizeof(char*));//Where we will store the int to binary strings

   for (int i = 1; i < 3; ++i)
   {
      printf("Please enter integer number %d: ", i); //Capture 2 ints from user
      scanf("%i", &integer[i]);
   }
   printf("\n");

   for (int i = 1; i < 3; ++i)
   {
      string[i] = ((char*)malloc(40*sizeof(char))); //Allocate memory for individual int to binary strings
      string[i] = intToBinaryString(integer[i]);   //Convert inputted ints to binary strings
   }

   for (int i = 1; i < 3; ++i)                                      //Print the binary strings and
   {                                                                             //And print the output of applying ~ operator to the ints
      string[0] = intToBinaryString(~integer[i]);
      printf("\n%37.d in binary is %s", integer[i], string[i]);
      printf("\n%11.d after applying ~ operator in binary is %s\n", integer[i], string[0]);
   }
//Print the binary strings and the result of applying the & operator to them
   string[0] = intToBinaryString(integer[1] & integer[2]);
   printf("\nResult = applying the & operator to the two numbers:\n\n");
   printf("%11.d = %s\n",  integer[1], string[1]);
   printf("%11.d = %s\n", integer[2], string[2]);
   printf("     Result = %s\n", string[0]);
//Print the binary strings and the result of applying the | operator to them
   string[0] = intToBinaryString(integer[1] | integer[2]);
   printf("\nResult = applying the | operator to the two numbers:\n\n");
   printf("%11.d = %s\n",  integer[1], string[1]);
   printf("%11.d = %s\n", integer[2], string[2]);
   printf("     Result = %s\n", string[0]);
//Print the binary strings and the result of applying the ^ operator to them
   string[0] = intToBinaryString(integer[1] ^ integer[2]);
   printf("\nResult = applying the ^ operator to the two numbers:\n\n");
   printf("%11.d = %s\n",  integer[1], string[1]);
   printf("%11.d = %s\n", integer[2], string[2]);
   printf("     Result = %s\n", string[0]);
//Print the first binary string and the result of applying the << operator to it
   string[0] = intToBinaryString(integer[1]  << 4);
   printf("\nResult = applying the  << operator to %i by the value of 4:\n\n", integer[1]);
   printf("%11.d = %s\n",  integer[1], string[1]);
   printf("     Result = %s\n", string[0]);
//Print the second binary string and the result of applying the >> operator to it
   string[0] = intToBinaryString(integer[2]  >>  2);
   printf("\nResult = applying the  >> operator to %i by the value of 2:\n\n", integer[2]);
   printf("%11.d = %s\n",  integer[2], string[2]);
   printf("     Result = %s\n", string[0]);

   free (string); //Free allocated memory
   string = NULL;

    return 0;
}

char* intToBinaryString(int number)
{
   int i=-1, index=32, negative = 0;

  char* answer  = (char*)malloc((size_t)33*sizeof(char)); //Buffer where we will initially store string
  char* fAnswer = (char*)malloc((size_t)40*sizeof(char)); //Where final answer will be stored

  if(number<0)                   //If the int is negative
  {
     negative=1;                  //Store that it is negative for later reference during output
     number=number/-1;  //Make the negative number positive to work with more easily
     number -= 1;                //-1 from it as it will have the exact opposite bits of its positive counterpart -1
  }

  answer[index] = '\0'; //Set end of buffer as null character as
  while(number>0)       //we will be working backwards starting with the last digit of input number
  {                                     //treating number as binary, work from smallest bit to largest bit
      if(negative)
          answer[--index] = (((number%2)-1)/-1)+'0';//if negative, change 0's to 1's and 1's to 0's
      else
          answer[--index] = (number%2)+'0';  //otherwise capture the bit as it is

     number=number/2;                  //Remove binary digit you just captured from end of the input
  }                                                         //so that the next iteration brings the next digit to be captured

  while(index>0) answer[--index] = 'x'; //Indicate with 'x' characters that rest of string is not part of final answer

  while(i++<40)                       //Now starting at beginning of buffer
  {
      if(i!=0&&(i+1)%5==0)  //add a space between every 4 bits in final answer
      {
          fAnswer[i] = ' ';
          continue;
      }
      if(answer[index]=='x') //for the bits to the left of the numbers indicated value
      {
          if(negative)
              fAnswer[i] = '1';    //fill in with 1's for a negative number
          else
              fAnswer[i] = '0';    //fill in with 0's for a positive number

          ++index;
          continue;
      }                                                  //when you reach the chars that define the number
      fAnswer[i]=answer[index]; //Copy the desired string from buffer to your final answer string
      ++index;
  }
  fAnswer[39]='\0'; //Set last char in final answer string to null charcter
  free(answer); //Free buffer
  answer = NULL;
  return fAnswer; //Return final answer.
  }















