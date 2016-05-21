CFLAGS := \
	-Weverything \
	-Wno-reserved-id-macro \
	-Wno-padded \
	-Wno-gnu-zero-variadic-macro-arguments \
	-Wno-format-nonliteral \
	-Werror \
	-g \
	-O0
# Note: to turn on debug, use -DL9P_DEBUG=L9P_DEBUG

LIB_SRCS := \
	pack.c \
	connection.c \
	request.c \
	log.c \
	hashtable.c \
	utils.c \
	rfuncs.c \
	sbuf/sbuf.c \
	transport/socket.c \
	backend/fs.c

SERVER_SRCS := \
	example/server.c

BUILD_DIR := build
LIB_OBJS := $(addprefix build/,$(LIB_SRCS:.c=.o))
SERVER_OBJS := $(SERVER_SRCS:.c=.o)
LIB := lib9p.dylib
SERVER := server

all: build $(LIB) $(SERVER)

$(LIB): $(LIB_OBJS)
	cc -dynamiclib $^ -o build/$@

$(SERVER): $(SERVER_OBJS) $(LIB)
	cc $< -o build/$(SERVER) -Lbuild/ -l9p

clean:
	rm -rf build
	rm -f $(SERVER_OBJS)
build:
	mkdir build
	mkdir build/sbuf
	mkdir build/transport
	mkdir build/backend

build/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
