compile: pipe_networking.c client.c server.c pipe_networking.h
    gcc pipe_networking.c -o pipe_networking; gcc client.c -o client; gcc server.c -o server

clean:
    rm *~