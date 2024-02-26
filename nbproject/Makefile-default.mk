#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=lib_test_lib_uart_ll_pic24.c lib_uart_pic24_ll.c test_lib_uart_ll_pic24_main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o ${OBJECTDIR}/lib_uart_pic24_ll.o ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o.d ${OBJECTDIR}/lib_uart_pic24_ll.o.d ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o ${OBJECTDIR}/lib_uart_pic24_ll.o ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o

# Source Files
SOURCEFILES=lib_test_lib_uart_ll_pic24.c lib_uart_pic24_ll.c test_lib_uart_ll_pic24_main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA010
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o: lib_test_lib_uart_ll_pic24.c  .generated_files/flags/default/8ae2fd93e39877f2b84f61bf5a39e450653e446b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o.d 
	@${RM} ${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib_test_lib_uart_ll_pic24.c  -o ${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o.d"      -g -D__DEBUG     -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)     -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib_uart_pic24_ll.o: lib_uart_pic24_ll.c  .generated_files/flags/default/8473bf1ff2a6933211ce25f13a22a0e06a0266dc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lib_uart_pic24_ll.o.d 
	@${RM} ${OBJECTDIR}/lib_uart_pic24_ll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib_uart_pic24_ll.c  -o ${OBJECTDIR}/lib_uart_pic24_ll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib_uart_pic24_ll.o.d"      -g -D__DEBUG     -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)     -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/test_lib_uart_ll_pic24_main.o: test_lib_uart_ll_pic24_main.c  .generated_files/flags/default/a9e3e6304744054d801a88babaf13272739ad3d2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o.d 
	@${RM} ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  test_lib_uart_ll_pic24_main.c  -o ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/test_lib_uart_ll_pic24_main.o.d"      -g -D__DEBUG     -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)     -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o: lib_test_lib_uart_ll_pic24.c  .generated_files/flags/default/2a1113a1fb507b08052ea1b7bdc4565d2e5ed75d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o.d 
	@${RM} ${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib_test_lib_uart_ll_pic24.c  -o ${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib_test_lib_uart_ll_pic24.o.d"        -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)     -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lib_uart_pic24_ll.o: lib_uart_pic24_ll.c  .generated_files/flags/default/8110eb5cc08ae404b0cea5d13ab886caa6c76764 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lib_uart_pic24_ll.o.d 
	@${RM} ${OBJECTDIR}/lib_uart_pic24_ll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lib_uart_pic24_ll.c  -o ${OBJECTDIR}/lib_uart_pic24_ll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lib_uart_pic24_ll.o.d"        -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)     -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/test_lib_uart_ll_pic24_main.o: test_lib_uart_ll_pic24_main.c  .generated_files/flags/default/a87bb5c7527e2aed4a72d6d9bfe537848b76f8b4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o.d 
	@${RM} ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  test_lib_uart_ll_pic24_main.c  -o ${OBJECTDIR}/test_lib_uart_ll_pic24_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/test_lib_uart_ll_pic24_main.o.d"        -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)     -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/MCU_AP6_uart.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a    -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
