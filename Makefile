# Note: to turn on debug, use -DL9P_DEBUG=L9P_DEBUG,
# and set env variable LIB9P_LOGGING to stderr or to
# the (preferably full path name of) the debug log file.

SRC=/ws/smartos-live/projects/illumos/usr/src
LIB=		9p
SHLIB_MAJOR=	1
SRCS=		pack.c \
		connection.c \
		request.c \
		log.c \
		hashtable.c \
		genacl.c \
		utils.c \
		rfuncs.c \
		threadpool.c \
		transport/socket.c \
		backend/fs.c

OBJS = $(SRCS:%.c=%.o)
CPPFLAGS = -I$(SRC)/compat/freebsd
CFLAGS = -g -DL9P_DEBUG

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<

lib9p.so: $(OBJS)

clean:
	-rm -f $(OBJS)
