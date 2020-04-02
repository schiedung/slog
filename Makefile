all:
	make --no-print-directory -C examples

test:
	./examples/release

clean:
	make --no-print-directory -C examples clean
