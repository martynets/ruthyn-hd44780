#############################################################################################################
# Project, libraries and installation pathes
#############################################################################################################
# The directory below needs to be adjusted for the target system.
# The module must be added to/removed from the gconv-modules file located in the target directory.
# It is expected the module is installed in to a custom directory which is later passed to iconv based
# application (e.g. gcc) in GCONV_PATH variable. If one decides to install the module to the system default
# gconv directory the iconvconfig command must be issued then.

TARGETDIR	= ../gconv

# List directories to look for prerequisites in
VPATH		 = ./

#############################################################################################################
# Commands and their arguments
#############################################################################################################
# Declare GNU toolchain command line tools
CC	 	= gcc
INSTALL		= install -m 755 -p -s -D -t
SED		= sed

# Declare command line flags
CFLAGS_SO  = $(addprefix -I, $(VPATH)) -O3 -fpic -shared

#############################################################################################################
# Prerequisites and targets
#############################################################################################################

TARGET		= ruthyn-hd44780.so

# Name of the codepage implemented by the target
CODEPAGE	= RUTHYN-HD44780
# Convenient alias to the codepage
ALIAS		= ruthyn

# List header files
HEADER_FILES	 = ruthyn_alphabet_hd44780.h


#############################################################################################################
# Rules
#############################################################################################################

$(TARGET):

# Generic rules
.PHONY: clean uninstall install

install: $(TARGET)
	$(INSTALL) "$(TARGETDIR)" "$(TARGET)"
	@touch "$(TARGETDIR)/gconv-modules"
	@$(SED) --in-place --follow-symlinks /$(CODEPAGE)/d "$(TARGETDIR)/gconv-modules"
	@echo "alias	$(ALIAS)//		$(CODEPAGE)//" >> "$(TARGETDIR)/gconv-modules"
	@echo "module	INTERNAL		$(CODEPAGE)//	$(basename $(TARGET))	1" >> "$(TARGETDIR)/gconv-modules"

uninstall:
	$(RM) "$(TARGETDIR)/$(TARGET)"
	@$(SED) --in-place --follow-symlinks /$(CODEPAGE)/d "$(TARGETDIR)/gconv-modules"

test: ruthyn-example
	@echo "The following output should be in the ruthyn-hd44780 charset"
	./ruthyn-example

ruthyn-example: ruthyn-example.c $(TARGETDIR)/$(TARGET) $(TARGETDIR)/gconv-modules
	GCONV_PATH=$(TARGETDIR) gcc -fexec-charset=ruthyn ruthyn-example.c -o ruthyn-example

$(TARGETDIR)/$(TARGET) $(TARGETDIR)/gconv-modules &: $(TARGET)
	@echo "Please run 'make install' before testing" && false

clean:
	$(RM) "$(TARGET)" ruthyn-example

# Build rules
%.so: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS_SO) -o $@ $<
