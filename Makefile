
all: lottery

lottery: always
	clang++ -g -Wall LotteryNumberGenerator.cpp -o lotterynumbergen


.PHONY: always
