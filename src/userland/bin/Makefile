
all: _cat _echo _grep _init _kill _ln _ls _mkdir _rm _sh _stressfs\
	 _usertests _wc _zombie _forktest

_cat: cat.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_echo: echo.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_grep: grep.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_init: init.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_kill: kill.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_ln: ln.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_ls: ls.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_mkdir: mkdir.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_rm: rm.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_sh: sh.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_stressfs: stressfs.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_usertests: usertests.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_wc: wc.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_zombie: zombie.o $(ULIB)
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^ $(ULIB)
	cp $@ $(ROOT)

_forktest: forktest.o $(ULIB)
	# forktest has less library code linked in - needs to be small
	# in order to be able to max out the proc table.
	$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o _forktest forktest.o $(LIB)ulib.o $(LIBARCH)usys.o
	cp $@ $(ROOT)

clean:
	rm -f *.o *.d *.asm $(UPROGS)

include ../../../common.mk

ULIB = $(addprefix $(LIB), ulib.o umalloc.o printf.o) $(addprefix $(LIBARCH), usys.o memset.o)
