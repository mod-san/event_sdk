# Shenmue Event Script (for Dreamcast) Sample Makefile

# `make TYPE=EV1` will produce code compliant with EV1
# `make TYPE=EV2` will produce code compliant with EV2
# `make TYPE=EV3` will produce code compliant with EV3
# `make TYPE=MAIN` will compile the code similarly to 1ST_READ.BIN
# `make TYPE=PHYS` will compile the code similarly to 1ST_READ.BIN (using 0x0c010000 (physical addr for 0x8c010000) as VMA)
# Adding P to the end of EV1/2/3 will build with the 0x8c010000 **virtual** mapping (mainly only used on Retail)
TYPE=EV1

PHYS    := 0x0c010000
MAIN    := 0x8c010000

EV1_VMA := 0x0c328000
EV2_VMA := 0x0c338000
EV3_VMA := 0x0c348000

EV1P_VMA := 0x8c328000
EV2P_VMA := 0x8c338000
EV3P_VMA := 0x8c348000

VMA     := $(EV3_VMA)

ifeq ($(TYPE), EV3)
        VMA := $(EV3_VMA)
else ifeq ($(TYPE), EV2)
        VMA := $(EV2_VMA)
else ifeq ($(TYPE), EV1)
        VMA := $(EV1_VMA)   
else ifeq ($(TYPE), EV3P)
        VMA := $(EV3P_VMA)
else ifeq ($(TYPE), EV2P)
        VMA := $(EV2P_VMA)
else ifeq ($(TYPE), EV1P)
        VMA := $(EV1P_VMA)
else ifeq ($(TYPE), MAIN)
        VMA := $(MAIN)
else ifeq ($(TYPE), ANY)
        VMA := $(PHYS)
else
        VMA := $(TYPE)
endif

CC=sh4-elf-gcc
CFLAGS=-O2 -ml -m4 -T ../event_lib/linker.x -nostartfiles -nostdlib -Wno-builtin-declaration-mismatch -I./ -I/usr/include/ -I../event_lib/include -Ttext=$(VMA) 

ifeq ($(RETAIL), 1)
        CFLAGS += -DRETAIL_MEMORY
endif

ifeq ($(TYPE), ANY)
        CFLAGS += -fpic
endif
OBJCOPY=sh4-elf-objcopy --adjust-vma=$(VMA) -O binary -R .stack
TARGET=event.$(TYPE)