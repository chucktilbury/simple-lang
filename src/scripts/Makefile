
FILES	=	ast.c \
			ast.h \
			parser.c \
			parser.h \
			tokens.c \
			tokens.h

TARGET	=	../ast.c \
			../ast.h \
			../parser.c \
			../parser.h \
			../tokens.c \
			../tokens.h

all: $(TARGET)

$(TARGET): grammar.txt gen_parser.py
	python gen_parser.py
	cp $(FILES) ..

clean:
	-rm -f ../tokens.h ../tokens.c \
		../ast.c ../ast.h ../parser.c ../parser.h

very_clean: clean
	-rm -f *.c *.h *.bak
