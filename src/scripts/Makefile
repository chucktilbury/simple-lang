
FILES	=	ast.c \
			ast.h \
			parser.c \
			parser.h \
			token_struct.h \
			token_types.h

TARGET	=	../ast.c \
			../ast.h \
			../parser.c \
			../parser.h \
			../token_struct.h \
			../token_types.h

all: $(TARGET)

$(TARGET): grammar.txt gen_parser.py
	python gen_parser.py
	cp $(FILES) ..

clean:
	-rm -f $(TARGET)

very_clean: clean
	-rm -f *.c *.h *.bak
