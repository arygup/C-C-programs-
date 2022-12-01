To sort a large file: file.txt compile 

 gcc q9.c 
 ./a.out file.txt answer.txt

Because my code is memory dependent(the above code is is optimised for 
around 400 mb/4million strings. My code breaks the files into 83 different files(each
file is made up of, for example strings that start with A or x or !) then it individually
sorts these files and prints it directly onto the answer.txt file since words that
begin with A will always come before words with B as the first letter),
if it ends up giving a segmentation fault, please run.

 gcc q9o.c 
 ./a.out file.txt answer.txt 

If the test case is of strings which are very small in length, please update 
 #define maxlength 
to desired string lenght to get optimum time bounded solution.

I have also attached my random string generating file which I used to check my code,
It can be used by (1 million ~ 100 mb)

 gcc gen.c
 ./a.out 1000000 file.txt 

The folder alternative approach using merge sort contains updated unfinished code which wasn't finished due to time limitations. 


