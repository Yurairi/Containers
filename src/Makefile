CC=gcc
CXXFLAGS=-std=c++17 -lstdc++
CFLAGS=-c -Wall -Werror -Wextra $(CXXFLAGS)
AR=ar
ARFLAGS=rcs
LDFLAGS=-lgtest -pthread -lgtest_main $(CXXFLAGS)

TEST_FILE=tests/test

REPORT=gcov_report
REPORT_DIR=report
GCOV_REPORT=gcov/$(REPORT)
GCOV_INFO=$(GCOV_REPORT).info
GCOV_FILES=*.gcno *.gcda gcov
GCOV_FLAGS=--coverage

SOURCES=s21_map/s21_map.cc \
				s21_set/s21_set.cc \
				s21_tree/s21_tree.cc \
				s21_deque/s21_deque.cc \
				s21_queue/s21_queue.cc \
				s21_stack/s21_stack.cc \
				s21_vector/s21_vector.cc \
				s21_list/s21_list.cc
TEST_SOURCES=$(wildcard tests/*.cc)

OBJECTS=$(SOURCES:.cc=.o)
TEST_OBJECTS=$(TEST_SOURCES:.cc=.o)

HEADERS=$(SOURCES:.cc=.h)

LIBRARY=s21_containers.a

all : $(LIBRARY)
 
$(LIBRARY): $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

.cc.o:
	$(CC) -I../src $(CFLAGS) $< -o $@

test: $(TEST_OBJECTS) $(LIBRARY)
	$(CC) -I../src $(TEST_OBJECTS) -o $(TEST_FILE) $(LDFLAGS) $(LIBRARY)
	$(TEST_FILE)

$(REPORT): clean
	mkdir -p gcov
	$(CC) -I../src $(TEST_SOURCES) $(GCOV_FLAGS) -o $(GCOV_REPORT) $(LDFLAGS)
	./$(GCOV_REPORT)
	mv $(GCOV_FILES)
	lcov -t "$(REPORT)" -o $(GCOV_INFO) -c -d gcov
	genhtml -o $(REPORT_DIR) $(GCOV_INFO)
	open $(REPORT_DIR)/index-sort-l.html

style:
	clang-format --style=Google -n $(SOURCES) $(TEST_SOURCES) $(HEADERS)

clean:
	rm -rf $(LIBRARY)
	rm -rf $(OBJECTS) $(TEST_OBJECTS)
	rm -rf $(TEST_FILE)
	rm -rf $(GCOV_FILES) 
	rm -rf report *.info
