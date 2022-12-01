all: q1.out q2.out q3.out remove
#Q1

q1.out: main1.o my_dll.o 
	gcc main.o my_dll.o -o q1.out

main1.o: ./Q1/main.c
	gcc -c ./Q1/main.c 

my_dll.o: ./Q1/my_dll.h ./Q1/my_dll.c
	gcc -c ./Q1/my_dll.c 


#Q2

q2.out: main2.o complex.o 
	gcc main.o complex.o -lm -o q2.out

main2.o: ./Q2/main.c 
	gcc -c ./Q2/main.c -lm

complex.o: ./Q2/complex.c ./Q2/complex.h
	gcc -c ./Q2/complex.c -lm

#Q3

q3.out: main3.o user.o musicplayer.o song.o 
	gcc main.o musicplayer.o  user.o song.o -o q3.out

main3.o: ./Q3/main.c 
	gcc -c ./Q3/main.c 

user.o: ./Q3/user.c ./Q3/user.h
	gcc -c ./Q3/user.c 

musicplayer.o: ./Q3/musicplayer.c ./Q3/musicplayer.h
	gcc -c ./Q3/musicplayer.c 

song.o: ./Q3/song.c ./Q3/song.h
	gcc -c ./Q3/song.c 
remove: 
	rm *.o