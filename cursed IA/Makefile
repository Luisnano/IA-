win: 
	gcc main.c busqueda.c puzleAlum.c listaia.c -o main -lm
wsl:	
	gcc main.c busqueda.c puzleAlum.c listaia.c -o main -lm

debug:
	gcc -g main.c busqueda.c puzleAlum.c listaia.c -o main
	gdb ./main
	
exec_wsl:
	./main
exec_win:
	./main.exe
clean_win: 
	del *.exe
clean_wsl: 
	rm *.exe
