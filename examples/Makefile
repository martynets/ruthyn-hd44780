TARGETDIR	= ../../gconv
TARGET		= ruthyn-hd44780.so

test: ruthyn-example
	@echo "The following output should be in the ruthyn-hd44780 charset"
	./ruthyn-example

ruthyn-example: ruthyn-example.c $(TARGETDIR)/$(TARGET) $(TARGETDIR)/gconv-modules
	GCONV_PATH=$(TARGETDIR) gcc -fexec-charset=ruthyn ruthyn-example.c -o ruthyn-example

$(TARGETDIR)/$(TARGET) $(TARGETDIR)/gconv-modules &:
	@echo "Please run 'make install' before testing" && false

clean:
	$(RM) "$(TARGET)" ruthyn-example
