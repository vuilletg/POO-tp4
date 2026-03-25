CC=g++
CFLAGS=-Wall -O0 -g3 -I. -MMD -MP -Werror

PROG=testAeroprt

# Retrait de graph.cpp ici car c'est un template (.h uniquement)
testAeroprt_SRCS := testGraphe.cpp airport.cpp
testAeroprt_OBJS := $(testAeroprt_SRCS:.cpp=.o)

DEPS := $(testAeroprt_SRCS:.cpp=.d)

all: $(PROG)

$(PROG): $(testAeroprt_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

-include $(DEPS)

clean:
	rm -rf *.o *.d $(PROG)

.PHONY: all clean