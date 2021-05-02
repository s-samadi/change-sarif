all:	union bufferOverflow cwe120 unsafe globalvars cwe190 cwe134 

union:
	gcc -o union.o c-test-proj/union.c 
bufferOverflow:
	gcc -o bufferOverflow.o c-test-proj/bufferOverflow.c
cwe120:
	gcc -o cwe-120.o c-test-proj/cwe-120.c
unsafe:
	gcc -o unsafestrcat.o c-test-proj/unsafestrcat.c 
globalvars:
	gcc -o globalvars.o c-test-proj/globalvars.c
cwe190:
	gcc -o cwe-190.o c-test-proj/cwe-190.c
cwe134:
	gcc -o cwe-134.o c-test-proj/cwe-134.c
loop:
	gcc -o infiniteloop.o c-test-proj/infiniteloop.c
