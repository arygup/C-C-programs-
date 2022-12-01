# Assignment - 4

By:
Aryan Gupta
2021113012

Operating System Used: `MacOS Monterey 12.2.1`
compiler used:
Apple clang version 13.0.0 (clang-1300.0.29.30)
Target: arm64-apple-darwin21.3.0


###### S1 - Randomness in Computation


## Q1. Deployment

Compile using:

  gcc 1.c 

Run using:

  ./a.out

The Output will be displayed on the terminal.


## Q2. Deployment

Compile using:

  gcc 2.c 

Run using:

  ./a.out

The Output will be displayed on the terminal.

## Q3. Deployment

Compile using:

  gcc 3.c

Run using:

  ./a.out
  input the number of test-cases you want to run, for example 1000000

The Output will be displayed on the terminal.


######  S2. Streaming Computations


## Q4.a Deployment

Compile using:

  gcc q4a.c 

Run using:

  ./a.out input_file_name output_file_name

The `input_file_name` is the path to the input file from which you want to read the raw data from.
The Output will be stored in a new file with the name `output_file_name`.


## Q4.b Deployment

PLEASE NOTE: 
since variance isnt defined for n = 1, the code outputs 'nan' in its place.

PLEASE NOTE:
q4b.c outputs just the final actual variace but q4b2.c outputs the entire running variance as well as actual

Compile using:

  gcc q4b.c 

Run using:

  ./a.out input_file mean_file output_file

The `input_file` is the path to the input file from which you want to read the raw data from.
The `mean_file` is the path to the file which contains the mean of the raw data from part-A.
The Output will be stored in a new file with the name `output_file`.


## Q4.c Deployment

Compile using:

  gcc q4c.c

Run using

  ./a.out input_file mean_file output_file

The `input_file` is the path to the input file from which you want to read the raw data from.
The `mean_file` is the path to the file which contains the mean of the raw data from part-A.
The Output will be stored in a new file with the name `output_file`.



######  S3. Cryptography and Bit Manipulation


## Q5.a Deployment

Compile using:

  gcc 5a.c 

Run using:

  ./a.out 

The outputs of probability distribution will be displayed on the terminal.


## Q5.b Deployment

Compile using:

  gcc 5b.c 

Run using:

  ./a.out 

The outputs of the probability asked in the question will be displayed on the terminal.


## Q5.c Deployment

PLEASE NOTE:
Ububtu was used for this perticular question as the checker script was not working properly on MacOS

If you want to encrypt a file with the path `message`, store the 127-Bit Key in the file with path `key_file`, and store the encrypted message in a file with path `cryptic`:

  gcc encrypt.c -o a
  ./a message key_file cryptic

Now to decrypt the cryptic message with the key `key_file` generated in previous step, and store the decoded message into a file with path `out`:

  gcc decrypt.c -o b
  ./b key_file cryptic out

The `out` file should be the same as the `message` file.



######  S4. Data on Disk


## Q6. Deployment

If you want to count the character frequency in given number of files `file1`, `file2`, `file3`.....

  gcc 6.c -o a
  ./a out.txt file1 file2 file3.....

The output will be generated and stored in the file with path `out.txt`.


## Q7. Deployment

If you want to count the word frequency in given number of files `file1`, `file2`, `file3`.....

  gcc 7.c -o a
 ./a.out out.txt file1 file2 file3.....

The output will be generated and stored in the file with path `out.txt`.


## Q8. Deployment

If you want to merge the 2 sorted list of names stored in files with path `file1` and `file2` :

  gcc 8.c -o a
  ./a file1 file2 out.txt 

The output is generated and stored in the file with path `out.txt`.


## Q9. Deployment

EOF