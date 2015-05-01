
# To compile stealer_sample with ../stealer.h, use the following command:
#   EXTRA_FLAG=-I.. make stealer_sample

CXXTOOL = g++
EXTRA_FLAG ?= 
CXXFLAGS = $(EXTRA_FLAG) -I../src -Wall -Wextra -fmacro-backtrace-limit=0
TARGETS := pp_test stealer_test stealer_sample

ifneq ($(MAKECMDGOALS),)
ifneq ($(wildcard $(MAKECMDGOALS).cpp),)
TARGETS := $(MAKECMDGOALS)
endif
endif

# $(1): source file
define buildrule
$(subst \,,$(shell $(CXXTOOL) -MM -MT $(1) $(CXXFLAGS) $(1).cpp))
	@echo Compiling [$$<]
	$(CXXTOOL) $(CXXFLAGS) -o $$@ $$<
endef

all: $(TARGETS)

$(foreach target, $(TARGETS), $(eval $(call buildrule,$(target))))
