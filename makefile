#
# CTime makefile to compile project on Linux
#

GPP = g++
GCC = gcc
cTime_OUTFILE = "cTime.so"

COMPILE_FLAGS = -m32 -fPIC -c -O3 -w -D LINUX -D PROJECT_NAME=\"cTime\" -I ./amx/

cTime = -D cTime $(COMPILE_FLAGS)

all: cTime

clean:
	rm -f *~ *.o *.so

cTime: clean
	$(GPP) $(cTime) samp-ctime/*.cpp
	$(GPP) $(cTime) samp-ctime/SDK/*.cpp
	$(GPP) -m32 -O2 -fshort-wchar -shared -o $(cTime_OUTFILE) *.o
