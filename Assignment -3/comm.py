#!/usr/bin/python

import random, sys
from optparse import OptionParser

def main():
    version_msg = "%prog 2.0"
    usage_msg = """ %prog [OPTION]... FILE1 FILE2
Output of the comparison between FILE1 and FILE2 in three columns."""
    parser = OptionParser(version=version_msg, usage=usage_msg
    parser.add_option("-u", action="store_true", dest="un", default=0)
    parser.add_option("-1", action="store_true", dest="one", default=0)
    parser.add_option("-2", action="store_true", dest="two", default=0)
    parser.add_option("-3", action="store_true", dest="three", default=0)
    options, args = parser.parse_args(sys.argv[1:])
    if len(args)!=2:
        parser.error("Wrong number of operands")
    file1=args[0]
    file2=args[1]
    lines1 = []
    lines2 = []
    if file2== "-":
        lines1=sys.stdin.readlines()
        
        try:
            f2 = open (file1 , 'r')
            lines2 = f2.readlines()) 
            f2.close()
        except:
            parser.error("Invalid file")
    else:
        try:
            f1 = open (file1, 'r')
            f2 = open (file2, 'r')
            lines1 = f1.readlines()
            lines2 = f2.readlines()
            f1.close()
            f2.close()
        except:
            parser.error("Invalid file")

     un=option.un
     one=option.one
     two=option.two
     three=option.three

     sp= "        "
    
     l1 = len(lines1)
     l2 = len(lines2)
     column1 =[]
     column2 =[]
     column3 =[]
     n=0
     if un==0
        column3=[i for i in lines1 if i in lines2]
        for i in column3:
            if i in lines2:
                lines2.remove(i)
        for i in columns3:
            if i in lines1:
                lines1.remove(i)
        t=sorted(lines1+column3+lines2)

        column1=lines1
        column2=lines2
        for i in t
            if i in column1 and one!=1:
                sys.stdout.write(i)

            if i in column2 and one!=1 and two!=1:
                sys.stdout.write(sp+i)
            elif i in column2 and one==1 and two!=1:
                sys.stdout.write(i)
            
            if i in column3 and one!=1 and two!=1 and three!=1:
                sys.stdout.write(sp+sp+i)
            elif i in column3 and one==1 and two!=1 and three!=1:
                sys.stdout.write(sp+i)
            elif i in column3 and one!=1 and two==1 and three!=1:
                sys.stdout.write(sp+i)
            elif i in column3 and one==1 and two==1 and three!=1:
                sys.stdout.write(i)
      if un==1:
          column3=[i for i in line1 if i in lines2]
          for i in column3:
              if i in lines2:
                  lines2.remove(i)
          for i in lines1:
              if i in column3 and one!=1 and two!=1 and three!=1:
                  sys.srdout.write(sp+sp+i)
              elif i in column3 and one==1 and two!=1 and three!=1:
                  sys.stdout.write(sp+i)
              elif i in column3 and one!=1 and two==1 and three!=1:
                  sys.stdout.write(sp+i)
              elif i in column3 and one==1 and two==1 and three!=1:
                  sys.stfout.write(i)
              elif i not in column3 and one!=1
                  sys.stdout.write(i)
          for i in lines2
              if one!=1 and two!=1:
                  sys.stdout.write(sp+i)
              elif one==1 and two!=1:
                  sys.stdout.write(i)

if _name_=="_main_":
    main()
