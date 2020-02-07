exe := stack_test

sources := $(wildcard *.c)

objects := $(sources:.c=.o)

deps := $(sources:.c=.d)

CC := gcc
RM := rm -rf

$(exe) : $(objects)
	$(CC) -o $@ $^

$(objects):%.o:%.c
	$(CC) -o $@ -c $<

.PHONY:clean

clean:
	$(RM) $(exe) $(objects) $(deps)

sinclude $(deps)

$(deps):%.d:%.c
	$(CC) -MM $< > $@
	
