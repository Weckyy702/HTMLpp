CXX = clang++
CXXFLAGS += -Wall -Wextra -Werror -O3 -std=c++20 -I./include

BIN = html++

BUILDDIR=build
SRCS = $(shell find src -name '*.cpp')
OBJS = $(SRCS:%=${BUILDDIR}/%.o)

.PHONY: all clean

all: ${BIN}

clean:
	rm -r ${BUILDDIR}/* ${BIN}

${BIN}: ${OBJS}
	${CXX} ${LDFLAGS} -o ${BIN} ${OBJS}

${BUILDDIR}/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -c $< -o $@
