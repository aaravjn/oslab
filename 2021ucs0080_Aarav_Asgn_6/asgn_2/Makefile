MYDIR = .
list: $(MYDIR)/*
	for file in $(wildcard *.c) ; do \
		gcc -c $${file} ; \
	done
clean:
	rm *.o
