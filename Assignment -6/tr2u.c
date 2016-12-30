#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
  char current [1];
  ssize_t ret = read(0,current,1);
  int match =0 ;
    while (ret > 0)
      {
	for ( size_t i =0; i< strlen(from);++i)
	  {
	    if(current[0]== from[i])
	      {
		current[0]=to[i];
		write(1 ,current,1);
		match =1;
		break;
	      }
	    else
	      {
		match=0;
	      }
	  }
	if (!match)
	  {
	    write (1 ,current ,1);
	  }
	ret = read (0, current, 1);
      }
  return 0;
}
