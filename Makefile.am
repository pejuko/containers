LIBTOOL_DEPS = @LIBTOOL_DEPS@

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck

lib_LTLIBRARIES = libcontainers.la
include_HEADERS = list.h tree.h

libcontainers_la_SOURCES = list.c tree.c

