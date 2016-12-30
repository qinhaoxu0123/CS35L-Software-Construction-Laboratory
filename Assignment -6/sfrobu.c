//
//  sfrobu.c
//  kk
//
//  Created by Qinhao Xu on 11/6/16.
//  Copyright © 2016 Qinhao Xukk. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int comparison = 0;
//function to compare unfrobnicared words
int frobcmp (char const *a, char const *b)
{
    for(;; a++, b++) // go to the entire words
    {
        if(*a == ' ' && *b == ' ' ) {return 0;}
        else if(*a == ' ' || ((*a^42) < (*b^42)) ) {return -1;}
        else if(*b  == ' '|| ((*a^42) > (*b^42)) ) {return 1;}
    }
}
//function to use within qsort without having to cast
int cmp (const void * n1, const void * n2)
{
    //casting pointers to pointers
    const void * a = *(char const**)n1;
    const void * b = *(char const**)n2;
    
    comparison++;
    return frobcmp(a,b);
}

//function to check for reading error
void checkerr(ssize_t s)
{
    if(s < 0)
    {
        fprintf(stderr,"reading error!");
        exit(1);
    }
}

int main (void)
{
    struct stat start;
    if(fstat(0, &start)<0)
    {
        fprintf(stderr, "Error!");
    }
    char* word;
    char** words;
    size_t wordsiterator=0;
    if(S_ISREG(start.st_mode))
       {
           word=(char*)malloc(start.st_size*sizeof(char));// allocated enough memeoy
           ssize_t s = read(0, word,start.st_size);
           int ptrcount=0;
           int count =1;
           if(s>0)//check error
           {
               for(size_t i=0; i<start.st_size;i+=count)
               {
                   count = 1;
                   if(i == start.st_size -1)
                   {
                       word[i] = ' ';
                   }
                   if(word[i] == ' ')
                   {
                       for(size_t k= i;word[k]!= ' ';k++)
                       {
                           count++;
                       }
                       ptrcount++;
                   }
               }
           }
           words=(char**)malloc(ptrcount*sizeof(char*));
           int pin =0;
           for(size_t i=0; i<start.st_size; i++)
           {
               if(pin==0 && word[i]!= ' ')
               {
                   words[wordsiterator] = &word[i];
                   wordsiterator++;
                   pin=1;
               }
               else if (pin ==1 && word [i] == ' ')
               {
                   pin = 0;
               }
           }
       }
       else
       {
           words = (char**)malloc(sizeof(char*));
       }
       
       char* word_h;// hold one word at a time
       word_h = (char*)malloc(sizeof(char));
       //current and next are iterators to use for indicating
       //EOF and auto adding spaces the end of file
       char current[1];
       ssize_t curpos = read(0, current, 1);
       checkerr(curpos);
       
       char next[1];
       ssize_t nextpos = read(0, next, 1);
       checkerr(nextpos);
       
       int letteriterator=0;
       while ( curpos >0)
       {
           word_h[letteriterator] = current[0]; // add letters to the words
           char* temp_memo = realloc(word_h, (letteriterator+2)*sizeof(char));
           if ( temp_memo != NULL)
           {
               word_h= temp_memo;
           }
           else //allocating error print error and then exit
           {
               free(word_h);
               fprintf(stderr, "allocating error!");
               exit(1);
           }
           if (current[0] == ' ')// at the end of the word
           {
               words[wordsiterator] = word_h; // add word to the words array
               char** temp1 = realloc(words, (wordsiterator+2)*sizeof(char*));
               if(temp1 != NULL)
               {
                   words=temp1;//make sures words equal to reallocated spaces
                   wordsiterator++;
                   //let the word points to other space
                   word_h=NULL;
                   word_h =(char*)malloc(sizeof(char));
                   letteriterator = -1; //-1 back to 0
               }
               else //allocating error print error and then exit
               {
                   free(words);
                   fprintf(stderr, "allocating error!");
                   exit(1);
               }
           }
           
           if(nextpos == 0 && current[0] == ' ')
           {
               break;
           }
           else if ( current[0] ==  ' ' && next[0] == ' ' ) //skip extra spaces
           {
               while(current[0] == ' ')
               {
                   curpos = read(0,current, 1);
                   checkerr(curpos);
               }
               nextpos = read(0,next,1);
               checkerr(nextpos);
               letteriterator++;
               continue;
           }
           else if ( nextpos == 0 ) // if next is at the end of the file
           {
               current[0] = ' ';
               letteriterator++;
               continue;
           }
           current[0] = next[0];
           nextpos = read (0, next, 1);
           checkerr(nextpos);
           letteriterator++;
       }
       
       // sort the frobnicated word from the words array
       qsort(words, wordsiterator, sizeof(char*), cmp);
       
       // output the words to stdoutt using puchar
       for(size_t i = 0; i < wordsiterator; i++)
       {
           long word_size= 0;
           for(size_t j = 0;; j++)
           {
               word_size++;
               if (words[i][j]== ' ')
               {
                   break;
               }
           }   
           if (write(1, words[i],word_size) == 0)
           {
               fprintf(stderr, "writing error!");
               exit(1);
           }
       }
       
       fprintf(stderr, "Comparison: %i\n", comparison);
       free(words);
       exit(0);
}
