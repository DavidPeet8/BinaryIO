COMPILER=clang++
EXEC=bmanip
COMPILATION_FLAGS=-Wall -MMD -stdlib=libc++
LINKER_FLAGS=-lc++abi -lc++
CPPSTANDARD=c++17

SRCDIR=./src
OBJDIR=./obj
TEST_OBJDIR=./test_obj
TESTDIR=./test

MAIN_OBJ=main.o
MAIN_PATH=$(call addprefix, ${OBJDIR}/, ${MAIN_OBJ})
OTHER_OBJS=main.o streamer.o bin_to_bin_as_ascii_transform.o ascii_as_bin_to_bin_transform.o
OTHER_PATHS=$(call addprefix, ${OBJDIR}/, ${OTHER_OBJS})

OBJECTPATHS=${MAIN_PATH} ${OTHER_PATHS}
DEPENDSPATHS=${OBJECTPATHS:.o=.d}

.PHONY: clean compile link prod

${EXEC}: compile link
-include ${DEPENDSPATHS}

# Individual File Compilation Target
${OBJDIR}/%.o: ${SRCDIR}/%.cc
	# $@ --> is the name of the makefile target
	# $< is the name of the first prerequisite
	${COMPILER} $< -std=${CPPSTANDARD} -c -o $@ ${COMPILATION_FLAGS}

# Individual File Compilation Target
${TEST_OBJDIR}/%.o: ${TESTDIR}/%.cc
	# $@ --> is the name of the makefile target
	# $< is the name of the first prerequisite
	${COMPILER} $< -std=${CPPSTANDARD} -c -o $@ ${COMPILATION_FLAGS}

prod: COMPILATION_FLAGS+=-Ofast
prod: ${EXEC}

compile: $(OBJECTPATHS)
	@echo Compiled

link:
	${COMPILER} ${OBJDIR}/*.o -o ${EXEC} ${LINKER_FLAGS}
	@echo Linking Complete

clean:
	rm -f ${OBJDIR}/* ${EXEC}
