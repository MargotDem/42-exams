#include "../exam.h"

/*

ok so how did i do it
first count words
then alloc array of pointers to pointers to char with the size, plus one
then go over the array a second time, for each word: calc word size, malloc enough space for it, copy the str, null terminate it
then put it in the array
if malloc fail: go back and free the prevs and also the array
at the end null terminate this array
mmkkayyyy


*/