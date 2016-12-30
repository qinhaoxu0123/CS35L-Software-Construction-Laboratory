#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  //check number of arugments 
  if(argc != 3)
    {
      fprintf(stderr, "Please input the correct arguments.\n");
      exit(1);
    }
  //check the length of arugement 
  char* from= argv[1];
  char* to= argv[2];

  if(strlen(from)!=strlen(to))
    {
      fprintf(stderr, "Two operands are not the same lenght.\n");
      exit(1);
    }
  //check dupulication
 
  for(size_t i = 0; i < strlen(from); ++i)
    {
      for( size_t j = i+1;  j < strlen(from); ++j)
	{
	  if(from[j]==from[i])
	    {
	      fprintf(stderr, "this operand has duplicated characters");
		exit(1);
	    }
	} 
    }

  //replace the first operand for second operand
  
  char current= getchar();
  int match = 0;
 
  while(current != EOF)
    {
      for(size_t i =0; i<strlen(from); ++i)
	{
	  if(current= from[i])
	    {
	      putchar(to[i]);
	      match=1;
	      break;
	    }
	  else
	    {
	      match=0;
	    }
	}
      if(!match)
	{
	  putchar(current);
	}

	  current = getchar();
    }
  return 0;

}
