DFG_FILES = gp_utils.cpp sc_utils.cpp DFG.cpp DFG_main.cpp
DFGT_FILES = gp_utils.cpp sc_utils.cpp DFG.cpp DFG_test.cpp
EG_FILES = gp_utils.cpp sc_utils.cpp eager_greedy.cpp greedy_main.cpp
LG_FILES = gp_utils.cpp sc_utils.cpp lazy_greedy.cpp greedy_main.cpp
# RFGREEDY = utils.cpp rfgreedy.cpp rfgreedy_main.cpp
# RFGREEDY_TEST = utils.cpp rfgreedy.cpp rfgreedy_test.cpp
TG_FILES = gp_utils.cpp ssc_utils.cpp thgreedy.cpp thgreedy_main.cpp
SSSC_FILES = gp_utils.cpp sc_utils.cpp ssc_utils.cpp sssc.cpp sssc_main.cpp
SSSCT_FILES = gp_utils.cpp ssc_utils.cpp sssc.cpp sssc_test.cpp
ISC_FILES = gp_utils.cpp sc_utils.cpp greedy.cpp ssc_utils.cpp iter_set_cover.cpp iter_set_cover_main.cpp
PG_FILES = gp_utils.cpp sc_utils.cpp ssc_utils.cpp pgreedy.cpp pgreedy_main.cpp
PGT_FILES = gp_utils.cpp ssc_utils.cpp pgreedy.cpp pgreedy_test.cpp
# SSC_UTILS_TEST = gp_utils.cpp ssc_utils.cpp ssc_utils_test.cpp
ASSADIMP_FILES = gp_utils.cpp sc_utils.cpp greedy.cpp ssc_utils.cpp assadiMP.cpp assadiMP_main.cpp
ASSADIMPT_FILES = gp_utils.cpp sc_util.cpp greedy.cpp ssc_utils.cpp assadiMP.cpp assadiMP_test.cpp
LOWERBOUND_FILES = gp_utils.cpp sc_utils.cpp lowerbound.cpp
GEN_DATASET = gen_dataset.cpp
ALL_FILES = gp_utils.cpp sc_utils.cpp ssc_utils.cpp lazy_greedy.cpp DFG.cpp sssc.cpp pgreedy.cpp all.cpp

FLAGS=-std=c++17 -pthread -O3
# REPORT=-qopt-report=2 -qopt-report-phase=vec
# LIBS=$(shell pkg-config --libs --cflags boost)
# -I/panfs/panasas01/cosc/an15739/boost_1_69_0 -L/panfs/panasas01/cosc/an15739/boost_1_69_0 -Wl,-rpath,/panfs/panasas01/cosc/an15739/boost_1_69_0
CC=clang++

all:
	$(CC) $(FLAGS) $(ALL_FILES) -o all.out
	./all.out

pg:
	$(CC) $(FLAGS) $(PG_FILES) -o pg.out
	./pg.out

pgt:
	$(CC) $(FLAGS)  $(PGT_FILES) -o pgt.out
	./pgt

dfg:
	$(CC) $(FLAGS)  $(DFG_FILES) -o dfg.out
	./dfg.out test

dfgt:
	$(TCC) $(FLAGS)  $(DFGT_FILES) -o dfgt.out
	./dfgt.out

eg:
	$(CC) $(FLAGS)  $(EG_FILES) -o eg.out
	./eg.out

lg:
	$(CC) $(FLAGS)  $(LG_FILES) -o lg.out
	./lg.out

tg:
	$(CC) $(FLAGS)  $(TG_FILES) -o tg.out

sssc:
	$(CC) $(FLAGS) $(REPORT) $(SSSC_FILES) -o sssc.out $(LIBS)
	./sssc.out

sssct:
	$(CC) $(FLAGS)  $(SSSCT_FILES) -o sssct.out

assadiMP:
	$(CC) $(FLAGS)  $(ASSADIMP_FILES) -o assadiMP.out

assadiMPt:
	$(CC) $(FLAGS)  $(ASSADIMPT_FILES) -o assadiMPt.out

lowerbound:
	$(CC) $(FLAGS)  $(LOWERBOUND_FILES) -o lowerbound.out

gen_dataset:
	$(CC) $(FLAGS) $(GEN_DATASET) -o gen_dataset.out
	# ./gen_dataset.out 0.1 25 `pwd`/file.out

# rfgreedy:
# 	$(CC) $(FLAGS)  $(RFGREEDY) -o rfgreedy
# 	./rfgreedy

# ssc_utils_test:
# 	$(CC) $(FLAGS)  $(SSC_UTILS_TEST) -o ssc_utils_test
# 	./ssc_utils_test

# rfgreedy_test:
# 	$(CC) $(FLAGS)  $(RFGREEDY_TEST) -o rfgreedy_test
# 	./rfgreedy_test

isc:
	$(CC) $(FLAGS)  $(ISC_FILES) -o isc.out

clean:
	rm *.out

.PHONY: pg pgt dfg dfgt g gt sssc sssct assadiMP assadiMPt lowerbound isc tg gen_dataset








