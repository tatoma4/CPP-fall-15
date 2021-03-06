GTEST_DIR = $(HOME)/gtest-1.7.0

# Where to find user code.
USER_DIR = ../src
TEST_DIR = .

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -std=c++0x -g -Wall -Wextra -pthread -Wno-missing-field-initializers

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS = dragon_test

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o tmc_test_results.xml in.txt out.txt tmc_available_points.txt

get-points :
	./dragon_test --gtest_output="xml:./tmc_test_results.xml" > /dev/null 2>&1; ./gen_points.sh

run: dragon_test
	./dragon_test --gtest_output="xml:./tmc_test_results.xml" 2> /dev/null; true

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.


dragon.o :  $(USER_DIR)/dragon.cpp $(USER_DIR)/dragon.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/dragon.cpp

cdragon.o :  $(USER_DIR)/cdragon.cpp $(USER_DIR)/cdragon.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/cdragon.cpp

fdragon.o :  $(USER_DIR)/fdragon.cpp $(USER_DIR)/fdragon.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/fdragon.cpp

mdragon.o :  $(USER_DIR)/mdragon.cpp $(USER_DIR)/mdragon.hpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/mdragon.cpp

test_source.o : $(TEST_DIR)/test_source.cpp \
                     $(USER_DIR)/dragon.hpp $(USER_DIR)/cdragon.hpp $(USER_DIR)/fdragon.hpp $(USER_DIR)/mdragon.hpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/test_source.cpp

dragon_test : dragon.o cdragon.o fdragon.o mdragon.o test_source.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
