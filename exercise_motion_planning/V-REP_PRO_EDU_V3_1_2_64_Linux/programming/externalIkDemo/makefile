CFLAGS = -I../remoteApi -I../externalIk -I../include -DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255
LDFLAGS = -lpthread

OBJS = ../remoteApi/extApi.o ../remoteApi/extApiPlatform.o externalIkDemo.o ../externalIk/Vector.o ../externalIk/Tt.o ../externalIk/Registerediks.o ../externalIk/ObjCont.o ../externalIk/MyMath.o ../externalIk/MMatrix.o ../externalIk/MainCont.o ../externalIk/ikRoutine.o ../externalIk/ikGroup.o ../externalIk/ikEl.o ../externalIk/extIkSer.o ../externalIk/extIk.o ../externalIk/Dummy.o ../externalIk/Ct.o ../externalIk/jointObject.o ../externalIk/7Vector.o ../externalIk/6X6Matrix.o ../externalIk/6Vector.o ../externalIk/4X4Matrix.o ../externalIk/4X4FullMatrix.o ../externalIk/4Vector.o ../externalIk/3X3Matrix.o ../externalIk/3Vector.o ../externalIk/3DObject.o
OUTPUT = bin/externalIkDemo

OS = $(shell uname -s)
ECHO = @

ifeq ($(OS), Linux)
	CFLAGS += -D__linux
else
	CFLAGS += -D__APPLE__
endif

all: $(OBJS)
		@mkdir -p bin
		@echo "Linking $(OBJS) to $(OUTPUT)"
		$(ECHO)$(CXX) $(CFLAGS) $(OBJS) -o $(OUTPUT) $(LDFLAGS)

%.o: %.cpp
		@echo "Compiling $< to $@"
		$(ECHO)$(CXX) $(CFLAGS) -c $< -o $@

%.o: %.c
		@echo "Compiling $< to $@" 
		$(ECHO)$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS) bin/externalIkDemo
