CC=g++
CFLAGS=-Wall -O0 -g3 -I. -MMD -MP -Werror

PROG=testAeroprt

# Sources et objets
testAeroprt_SRCS := testAeroprt.cpp aeroprt.cpp
testAeroprt_OBJS := $(testAeroprt_SRCS:.cpp=.o)

# Fichiers .d générés
DEPS := $(testAeroprt_SRCS:.cpp=.d)

# Cible par défaut
all: $(PROG)

# Règle pour le programme final
$(PROG): $(testAeroprt_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour les fichiers objets
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

# Inclusion des dépendances
-include $(DEPS)

# Nettoyage
clean:
	rm -rf *.o *.d $(PROG)

.PHONY: all clean