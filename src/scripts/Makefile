
FILES	=	ast.c \
			ast.h \
			parser.c \
			parser.h \
			token_types.c \
			token_types.h

TARGET	=	../ast.c \
			../ast.h \
			../parser.c \
			../parser.h \
			../token_types.c \
			../token_types.h

all: $(TARGET)

$(TARGET): grammar.txt gen_parser.py
	python gen_parser.py
	cp $(FILES) ..

clean:
	-rm -f ../token_types.h ../token_types.c \
		../ast.c ../ast.h ../parser.c ../parser.h

very_clean: clean
	-rm -f *.c *.h *.bak
