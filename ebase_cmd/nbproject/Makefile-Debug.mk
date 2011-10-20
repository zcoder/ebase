#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/ebase_cmd.o \
	${OBJECTDIR}/version_cmd.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath ../ebase_lib/dist/Debug/GNU-Linux-x86 -L../ebase_lib/dist/Debug/GNU-Linux-x86 -lebase_dbg

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ebase_cmd_dbg

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ebase_cmd_dbg: ../ebase_lib/dist/Debug/GNU-Linux-x86/libebase_dbg.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ebase_cmd_dbg: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ebase_cmd_dbg ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG_OPT -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/ebase_cmd.o: nbproject/Makefile-${CND_CONF}.mk ebase_cmd.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG_OPT -MMD -MP -MF $@.d -o ${OBJECTDIR}/ebase_cmd.o ebase_cmd.cpp

${OBJECTDIR}/version_cmd.o: nbproject/Makefile-${CND_CONF}.mk version_cmd.cc version_cmd.sh
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG_OPT -D__VERSION_CMD__="\"`sh version_cmd.sh -n`\"" -D__VER_CMD__="\"`sh version_cmd.sh -VERSION`\"" -D__BUILD_CMD__="\"`sh version_cmd.sh -BUILD`\"" -MMD -MP -MF $@.d -o ${OBJECTDIR}/version_cmd.o version_cmd.cc

# Subprojects
.build-subprojects:
	cd ../ebase_lib && ${MAKE}  -f Makefile CONF=Debug

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/1310910675/error.o ${TESTDIR}/_ext/637728746/run.o ${TESTDIR}/tests/test_enc_dec.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/_ext/1310910675/error.o: ../common/error/error.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1310910675
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG_OPT -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/1310910675/error.o ../common/error/error.cpp


${TESTDIR}/_ext/637728746/run.o: ../common/run/run.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/637728746
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG_OPT -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/637728746/run.o ../common/run/run.cpp


${TESTDIR}/tests/test_enc_dec.o: tests/test_enc_dec.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -DDEBUG_OPT -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/test_enc_dec.o tests/test_enc_dec.cpp


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -DDEBUG_OPT -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/ebase_cmd_nomain.o: ${OBJECTDIR}/ebase_cmd.o ebase_cmd.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ebase_cmd.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -DDEBUG_OPT -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/ebase_cmd_nomain.o ebase_cmd.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ebase_cmd.o ${OBJECTDIR}/ebase_cmd_nomain.o;\
	fi

${OBJECTDIR}/version_cmd_nomain.o: ${OBJECTDIR}/version_cmd.o version_cmd.cc version_cmd.sh
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/version_cmd.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -DDEBUG_OPT -D__VERSION_CMD__="\"`sh version_cmd.sh -n`\"" -D__VER_CMD__="\"`sh version_cmd.sh -VERSION`\"" -D__BUILD_CMD__="\"`sh version_cmd.sh -BUILD`\"" -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/version_cmd_nomain.o version_cmd.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/version_cmd.o ${OBJECTDIR}/version_cmd_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ebase_cmd_dbg

# Subprojects
.clean-subprojects:
	cd ../ebase_lib && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
