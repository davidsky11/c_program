#Makefile

TARGET := main
RM := rm

CC := gcc

MK := make

SRCS := rbtree.c map.c main.c

OBJS := $(subst .c,.o,$(SRCS))


$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

default: 
	$(MK) $(TARGET)

clean: 
	$(RM) $(OBJS) $(TARGET)

# common part
%.o: %.c
	$(CC) -c $< -Wall -o $@
