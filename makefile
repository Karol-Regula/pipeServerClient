compile: pipe_networking.c pipe_networking.h client.c server.c
	gcc pipe_networking.c -o pipe_networking; gcc client.c -o client; gcc server.c -o server

clean:
	rm *~
