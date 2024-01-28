CROSS_COMPILE ?=

all:
	$(CROSS_COMPILE)gcc -std=c89 -c ./writer.c -o ./writer.o
	$(CROSS_COMPILE)gcc ./writer.o -o ./writer

clean: 
	@echo "Cleaning up build files:"
	rm -f ./*.o
	rm -f ./writer
