TARGET = Partie.out
SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)

CFLAGS = -std=c++11 -Wall -I.
CXX = g++ $(CFLAGS) -c 
LD = g++
RM = rm -f


CulDeChouette.out: CulDeChouette.o De.o Joueur.o PartieCulDeChouette.o VisuelPartie.o
	$(LD) -o $@ $^
	
CulDeChouette.o: CulDeChouette.cpp 
	$(CXX)	$<

De.o: De.cpp De.h	
	$(CXX)	$<

Joueur.o: Joueur.cpp Joueur.h
	$(CXX)	$<

PartieCulDeChouette.o: PartieCulDeChouette.cpp PartieCulDeChouette.h
	$(CXX)	$<
VisuelPartie.o: VisuelPartie.cpp VisuelPartie.h
	$(CXX)	$<

.PHONY: check cppcheck format clean cleanall

check:
	clang-tidy $(SOURCES) --quiet -header-filter='.*' -checks=-*,boost-*,bugprone-*,performance-*,readability-*,portability-*,modernize-use-nullptr,clang-analyzer-*,cppcoreguidelines-* --format-style=none -- -std=c++11

cppcheck:
	cppcheck --enable=all --std=c++11 --platform=unix64 --suppress=missingIncludeSystem --quiet $(SOURCES)

format:
	find . -regex '.*\.\(cpp\|h\)' -exec clang-format -i --style=file {} \;

clean:
	$(RM) *.o

cleanall:
	$(RM) *.o* *.*~ $(TARGET)