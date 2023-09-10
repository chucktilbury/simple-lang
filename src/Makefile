
TARGET	=	simp
OBJS	=	main.o \
			cmdline.o \
			errors.o \
			filebuf.o \
			import.o \
			mem.o \
			ptrlst.o \
			scanner.o \
			str.o \
			tokens.o \
			ast.o \
			parser.o

GEN_FILES	=	parser.c \
			parser.h \
			ast.c \
			ast.h \
			token_struct.h \
			token_types.h

WARNS	=	-Wno-unused-variable -Wno-maybe-uninitialized
COPTS	=	-Wall -Wextra -Wpedantic
DEBUG 	=	-g
CFG		=	-DENABLE_GC -DENABLE_TRACE
LIBS	= 	-lgc

all: $(TARGET)

%.o:%.c
	gcc $(DEBUG) $(WARNS) $(COPTS) $(CFG) -c -o $@ $<

$(TARGET): $(OBJS)
	gcc $(DEBUG) -o $@ $(OBJS) $(LIBS)

$(GEN_FILES): scripts/grammar.txt scripts/gen_parser.py
	make --directory scripts all

main.o: main.c parser.h
cmdline.o: cmdline.c cmdline.h
errors.o: errors.c errors.h
filebuf.o: filebuf.c filebuf.h
import.o: import.c import.h
mem.o: mem.c mem.h
ptrlst.o: ptrlst.c ptrlst.h
scanner.o: scanner.c scanner.h
str.o: str.c str.h
tokens.o: tokens.c tokens.h
ast.o: ast.c ast.h
parser.o: parser.c parser.h

clean:
	-rm -f $(TARGET) $(OBJS)
	make --directory scripts clean