
all: simp

simp:
	make --directory src all

doc:
	make --directory docs all

clean-all: clean-doc clean-src

clean:
	make --directory src clean

clean-doc:
	make --directory docs clean
