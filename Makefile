Win32Skeleton.exe: main.o
	gcc -o Win32Skeleton.exe main.o
	
main.o: main.c
	gcc -c main.c
