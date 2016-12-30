1.
unmodified version:
time ./srt 1-test.ppm >1-test.ppm.tmp

real	0m42.838s
user	0m42.833s
sys	0m0.001s
mv 1-test.ppm.tmp 1-test.ppm

2. Mutlthreads version:
time ./srt 1-test.ppm >1-test.ppm.tmp

real	0m44.018s
user	0m44.013s
sys	0m0.000s
mv 1-test.ppm.tmp 1-test.ppm
time ./srt 2-test.ppm >2-test.ppm.tmp

real	0m44.649s
user	1m28.933s
sys	0m0.003s
mv 2-test.ppm.tmp 2-test.ppm
time ./srt 4-test.ppm >4-test.ppm.tmp

real	0m44.568s
user	2m57.883s
sys	0m0.003s
mv 4-test.ppm.tmp 4-test.ppm
time ./srt 8-test.ppm >8-test.ppm.tmp

real	0m44.654s
user	5m56.445
sys	0m0.010s
mv 8-test.ppm.tmp 8-test.ppm

In contrast, we can see that the modified and unmodified version are very similar in terms of one thread in real and user time. As we increase numbers of threads, we can obviously see the users’ time and systems’ time are also increasing. In terms of real time, the modified version that uses multithreaded has very consistent time in 2, 4, 8 threads, so we can see that although as the number of threads is increasing, the reals’ time remains consistent. 

issue that I experienced:
I have the segmentation vault when I ran ‘make clean check’, in this case, I need to use the gdb debugger to step in and set the breakpoint of the function that it seems has the error, since the segmentation vault arise primarily due to errors in use of pointers for virtual memory addressing, particularly illegal access, i found that when i use pthread_create to create the threads using forloop,but I forgot to write another forloop to free the threads, which can the cause of this segmentation vault. 
 