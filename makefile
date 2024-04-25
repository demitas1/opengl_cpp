CC = g++
CFLAGS = -Wall
LIBS = -ldl -lglfw -lGLEW -lGL -lX11 -lXrandr -lpthread -lXi
#LIBS = -ldl -lglfw3 -lGLEW -lGL -lX11 -lXrandr -lpthread -lXi

SRCDIR = src
BUILDDIR = build
GLADDIR = glad/src

SRCEXT = cpp
SRCS = $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SRCS:.$(SRCEXT)=.o))


all: hello ex1 hello_window

hello: $(BUILDDIR)/hello.o
	$(CC) $^ $(GLADDIR)/glad.c $(LIBS) -o $(BUILDDIR)/hello

ex1: $(BUILDDIR)/ex1.o
	$(CC) $^ $(LIBS) -o $(BUILDDIR)/ex1

hello_window: $(BUILDDIR)/hello_window.o
	$(CC) $^ $(GLADDIR)/glad.c  $(LIBS) -o $(BUILDDIR)/hello_window

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)

