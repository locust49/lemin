#!/bin/sh
rm -rf lemin_checker_log lem-in.dSYM lem-in
mkdir lemin_checker_log
make re -C ../
cp ../lem-in .
clear
for i in `seq 0 22`
do
		echo "\n\n\t\t===========================\n\t\t|||\t$i | "Error_$i"\t|||\n\t\t===========================\n"
	valgrind --leak-check=full --log-file="lemin_checker_log/log_errorfile$i.txt" ./lem-in < "map.error$i"
	echo "\n\t\t\t=== LEAKS ==="
	grep "definitely lost:" lemin_checker_log/log_errorfile$i.txt | cut -d '=' -f 5 | cut -c5-
	sleep 1
done
for i in `seq 0 9`
do
		echo "\n\n\t\t===========================\n\t\t|||\t$i | "Correct_$i"\t|||\n\t\t===========================\n"
	valgrind --leak-check=full --log-file="lemin_checker_log/log_correctfile$i.txt" ./lem-in < "map.ok$i"
	echo "\n\t\t\t=== LEAKS ==="
	grep "definitely lost:" lemin_checker_log/log_correctfile$i.txt | cut -d '=' -f 5 | cut -c5-
	sleep 1
done
echo "\nLoop tests ? (y/n) "
read text
if [ "$text" = "y" ]
then
	for i in `seq 0 1`
	do
		echo "\n\n\t\t===========================\n\t\t|||\t$i | "Loop_$i"\t|||\n\t\t===========================\n"
		valgrind --leak-check=full --log-file="lemin_checker_log/log_loopfile$i.txt" ./lem-in < "map.loop$i"
		echo "\n\t\t\t=== LEAKS ==="
		grep "definitely lost:" lemin_checker_log/log_loopfile$i.txt | cut -d '=' -f 5 | cut -c5-
		sleep 1
	done
fi
echo "\nBig test (y/n) "
read text
if [ "$text" = "y" ]
then
		echo "\n\n\t\t===========================\n\t\t|||\tBig test\t|||\n\t\t===========================\n"
	valgrind --leak-check=full --log-file="lemin_checker_log/log_bigfile.txt" ./lem-in < "map.big"
	echo "\n\t\t\t=== LEAKS ==="
	grep "definitely lost:" lemin_checker_log/log_bigfile.txt | cut -d '=' -f 5 | cut -c5-
fi
make fclean -C ../
rm -rf lem-in.dSYM lem-in
