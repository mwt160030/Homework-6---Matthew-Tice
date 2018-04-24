#
# Name: Matthew Tice
# E-mail: mwt160030@utdallas.edu
# Class: CS3377.502

#
# Compiler to use
CXX = g++

#
# Compuler flags
CXXFLAGS = -Wall -g

#
# Preprocessor flags 
CPPFLAGS = -I/scratch/perkins/include

#
# Library path
LDFLAGS = -L/scratch/perkins/lib

#
# Library flags
LDLIBS = -lcdk -lcurses 

#
# Name for backup tarball
PROJECTNAME = Program6

# Name of executable
EXECFILE = Program6

#
# Source files
SRCS = Program6.cc functions.cc

#
# Object files 
OBJS = Program6.o functions.o

#
# Make target
all: $(EXECFILE)

#
# Clean target that removes intermediate files
clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#*

#
# Rule for linkng executable
$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

#
# Backup Target
backup: clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to : $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
