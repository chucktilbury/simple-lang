TARGET	=	ast.c \
			ast.h \
			parser.c \
			parser.h \
			tokens.h

all: $(TARGET)

$(TARGET): grammar.txt
	python gen_parser.py
	cp $(TARGET) ..

clean:
	rm -f ../tokens.h \
		../ast.c ../ast.h ../pasrser.c ../parser.h
