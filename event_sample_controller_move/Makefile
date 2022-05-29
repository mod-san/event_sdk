include ../event_lib/Makefile
CFLAGS+=-O2 -ml -m4-single-only -mno-accumulate-outgoing-args -mpretend-cmove -mfsca -mfsrra -static -Wl,--no-undefined -Wl,-z,text -Wl,-z,norelro -Wl,-z,now -ffreestanding -ffp-contract=fast -fno-unsafe-math-optimizations -fno-finite-math-only -fomit-frame-pointer -fno-delete-null-pointer-checks -fno-common -fno-zero-initialized-in-bss -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-stack-protector -fno-stack-check -fno-strict-aliasing -fno-merge-all-constants -fno-merge-constants -Wdouble-promotion -Wpedantic -fmessage-length=0 -MMD -MP
TARGET=controller_move.$(TYPE)

all: rm-elf $(TARGET)

$(TARGET).elf: main.c
	$(CC) $(CFLAGS) -o $@ main.c

$(TARGET): $(TARGET).elf
	$(OBJCOPY) $^ $@

.PHONY : clean
clean:
	-rm -f $(TARGET) $(TARGET) $(TARGET).elf $(OBJS)

.PHONY : rm-elf
rm-elf:
	-rm -f $(TARGET) $(TARGET).elf
