CC = gcc

.SUFFIXES: .c
.c.o:
        
	$(CC) $(CFLAGS) -c $*.c

OPTFLAGS = -O3 
ARCHFLAGS = -lm #(if CC==gcc) 
DBFLAGS = -g
DEFINES = 
INCLUDES = -I.
CFLAGS =  $(DEFINES) $(OPTFLAGS) $(ARCHFLAGS) $(INCLUDES)


SRCS = test_case.c indices.c io.c counter.c

APP = run.exe

OBJS = $(SRCS:.c=.o)


$(APP): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(APP)
clean:
	-rm -f $(APP) $(OBJS) core

