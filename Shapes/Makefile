TARGETS=static_test hourglass_test octagon_test star_test circle_test pentagon_test

CXXFLAGS=-g `pkg-config sdl2 --cflags`
LDLIBS=`pkg-config sdl2 --libs`
CXX=g++
LD=g++
CC=g++

all: $(TARGETS)
static_test: canvas.o drawable.o static.o static_test.o
hourglass_test: canvas.o drawable.o hourglass.o hourglass_test.o
circle_test: circle.o circle_test.o canvas.o drawable.o
octagon_test: canvas.o drawable.o octagon.o octagon_test.o
star_test: canvas.o drawable.o star.o star_test.o
rectangle_test: canvas.o drawable.o rectangle.o rectangle_test.o
pentagon_test: canvas.o drawable.o pentagon.o pentagon_test.o

clean:
	rm -f $(TARGETS) *.o