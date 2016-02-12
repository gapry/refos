cmd_tools/kbuild/kconfig/zconf.tab.o := /usr/bin/ccache gcc -Wp,-MD,tools/kbuild/kconfig/.zconf.tab.o.d -Itools/kbuild/kconfig -Wall -DCURSES_LOC="<ncurses.h>" -DLOCALE  -I/home/chi-wai/Workspaces/microkernel/refos/tools/kbuild/kconfig -Itools/kbuild/kconfig -c -o tools/kbuild/kconfig/zconf.tab.o tools/kbuild/kconfig/zconf.tab.c

deps_tools/kbuild/kconfig/zconf.tab.o := \
  tools/kbuild/kconfig/zconf.tab.c \
  /usr/include/stdc-predef.h \
  /usr/include/ctype.h \
  /usr/include/features.h \
  /usr/include/x86_64-linux-gnu/sys/cdefs.h \
  /usr/include/x86_64-linux-gnu/bits/wordsize.h \
  /usr/include/x86_64-linux-gnu/gnu/stubs.h \
  /usr/include/x86_64-linux-gnu/gnu/stubs-64.h \
  /usr/include/x86_64-linux-gnu/bits/types.h \
  /usr/include/x86_64-linux-gnu/bits/typesizes.h \
  /usr/include/endian.h \
  /usr/include/x86_64-linux-gnu/bits/endian.h \
  /usr/include/x86_64-linux-gnu/bits/byteswap.h \
  /usr/include/x86_64-linux-gnu/bits/byteswap-16.h \
  /usr/include/xlocale.h \
  /usr/lib/gcc/x86_64-linux-gnu/4.8/include/stdarg.h \
  /usr/include/stdio.h \
  /usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h \
  /usr/include/libio.h \
  /usr/include/_G_config.h \
  /usr/include/wchar.h \
  /usr/include/x86_64-linux-gnu/bits/stdio_lim.h \
  /usr/include/x86_64-linux-gnu/bits/sys_errlist.h \
  /usr/include/stdlib.h \
  /usr/include/x86_64-linux-gnu/bits/waitflags.h \
  /usr/include/x86_64-linux-gnu/bits/waitstatus.h \
  /usr/include/x86_64-linux-gnu/sys/types.h \
  /usr/include/time.h \
  /usr/include/x86_64-linux-gnu/sys/select.h \
  /usr/include/x86_64-linux-gnu/bits/select.h \
  /usr/include/x86_64-linux-gnu/bits/sigset.h \
  /usr/include/x86_64-linux-gnu/bits/time.h \
  /usr/include/x86_64-linux-gnu/sys/sysmacros.h \
  /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h \
  /usr/include/alloca.h \
  /usr/include/x86_64-linux-gnu/bits/stdlib-float.h \
  /usr/include/string.h \
  /usr/lib/gcc/x86_64-linux-gnu/4.8/include/stdbool.h \
  tools/kbuild/kconfig/lkc.h \
    $(wildcard include/config/.h) \
    $(wildcard include/config/list.h) \
  tools/kbuild/kconfig/expr.h \
  /usr/include/libintl.h \
  tools/kbuild/kconfig/lkc_proto.h \
  tools/kbuild/kconfig/zconf.hash.c \
  tools/kbuild/kconfig/lex.zconf.c \
  /usr/include/errno.h \
  /usr/include/x86_64-linux-gnu/bits/errno.h \
  /usr/include/linux/errno.h \
  /usr/include/x86_64-linux-gnu/asm/errno.h \
  /usr/include/asm-generic/errno.h \
  /usr/include/asm-generic/errno-base.h \
  /usr/lib/gcc/x86_64-linux-gnu/4.8/include-fixed/limits.h \
  /usr/lib/gcc/x86_64-linux-gnu/4.8/include-fixed/syslimits.h \
  /usr/include/limits.h \
  /usr/include/x86_64-linux-gnu/bits/posix1_lim.h \
  /usr/include/x86_64-linux-gnu/bits/local_lim.h \
  /usr/include/linux/limits.h \
  /usr/include/x86_64-linux-gnu/bits/posix2_lim.h \
  /usr/include/unistd.h \
  /usr/include/x86_64-linux-gnu/bits/posix_opt.h \
  /usr/include/x86_64-linux-gnu/bits/environments.h \
  /usr/include/x86_64-linux-gnu/bits/confname.h \
  /usr/include/getopt.h \
  tools/kbuild/kconfig/util.c \
  tools/kbuild/kconfig/confdata.c \
    $(wildcard include/config/config.h) \
    $(wildcard include/config/autoconfig.h) \
    $(wildcard include/config/overwriteconfig.h) \
    $(wildcard include/config/notimestamp.h) \
    $(wildcard include/config/autoheader.h) \
    $(wildcard include/config/tristate.h) \
  /usr/include/x86_64-linux-gnu/sys/stat.h \
  /usr/include/x86_64-linux-gnu/bits/stat.h \
  /usr/include/fcntl.h \
  /usr/include/x86_64-linux-gnu/bits/fcntl.h \
  /usr/include/x86_64-linux-gnu/bits/fcntl-linux.h \
  tools/kbuild/kconfig/expr.c \
  tools/kbuild/kconfig/symbol.c \
  /usr/include/regex.h \
  /usr/include/x86_64-linux-gnu/gnu/option-groups.h \
  /usr/include/x86_64-linux-gnu/sys/utsname.h \
  /usr/include/x86_64-linux-gnu/bits/utsname.h \
  tools/kbuild/kconfig/menu.c \

tools/kbuild/kconfig/zconf.tab.o: $(deps_tools/kbuild/kconfig/zconf.tab.o)

$(deps_tools/kbuild/kconfig/zconf.tab.o):
