ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment. export DEVKITPRO=<path to>/devkitpro")
endif

TOPDIR ?= $(CURDIR)
include $(DEVKITPRO)/libnx/switch_rules

TARGET      := pikmin-switch
BUILD       := build-switch
SOURCES     := switch/source
INCLUDES    := switch/include

APP_TITLE   := Pikmin Native Switch
APP_AUTHOR  := Open Nectar Switch Port
APP_VERSION := 0.0.1

ARCH := -march=armv8-a+crc+crypto -mtune=cortex-a57 -mtp=soft -fPIE

CFLAGS   := -g -O2 -Wall -ffunction-sections -fdata-sections $(ARCH) $(DEFINES)
CFLAGS   += $(INCLUDE) -D__SWITCH__ -DPIKI_SWITCH_PORT=1
CXXFLAGS := $(CFLAGS) -std=gnu++17
ASFLAGS  := -g $(ARCH)

LDFLAGS := -specs=$(DEVKITPRO)/libnx/switch.specs -g $(ARCH) \
           -Wl,-Map,$(notdir $*.map) -Wl,--gc-sections

# Force the devkitA64 linker driver. GNU make has a built-in LD=ld, which
# otherwise selects the host x86_64 linker inside CI.
export CC  := $(DEVKITPRO)/devkitA64/bin/aarch64-none-elf-gcc
export CXX := $(DEVKITPRO)/devkitA64/bin/aarch64-none-elf-g++
export LD  := $(CXX)

LIBS    := -lnx
LIBDIRS := $(LIBNX)

ifneq ($(BUILD),$(notdir $(CURDIR)))

export OUTPUT := $(CURDIR)/$(BUILD)/$(TARGET)
export TOPDIR := $(CURDIR)

export VPATH := $(foreach dir,$(SOURCES),$(CURDIR)/$(dir))
CFILES       := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES     := $(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))

export OFILES := $(CPPFILES:.cpp=.o) $(CFILES:.c=.o)
export INCLUDE := $(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
                  $(foreach dir,$(LIBDIRS),-I$(dir)/include) \
                  -I$(CURDIR)/include -I$(CURDIR)/pc_port

export LIBPATHS := $(foreach dir,$(LIBDIRS),-L$(dir)/lib)

.PHONY: all clean

all: $(BUILD)
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/switch/Makefile

$(BUILD):
	@mkdir -p $@

clean:
	@echo clean ...
	@rm -fr $(BUILD)

else

DEPENDS := $(OFILES:.o=.d)

$(OUTPUT).nro: $(OUTPUT).elf
$(OUTPUT).elf: $(OFILES)

-include $(DEPENDS)

endif
