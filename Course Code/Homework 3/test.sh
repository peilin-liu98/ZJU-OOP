#! /bin/bash
echo -e "Show all records of personal diary below:"
./pdlist

echo -e "Search entities by command line parameters: "
echo "Input form: year month day, e.g. 2021 11 24"
echo "Start:"
read year1 month1 day1
echo "End:"
read year2 month2 day2
./pdlist -start $year1 $month1 $day1 -end $year2 $month2 $day2

echo -e "Show the content of the date: "
read year3 month3 day3
./pdshow $year3 $month3 $day3

echo -e "Add new diary. Please specify the date: "
read year4 month4 day4
./pdadd $year4 $month4 $day4 < input.txt
./pdshow $year4 $month4 $day4
echo -e "After adding diary, all records listed below: \n"
./pdlist

echo -e "Remove the diary of the date: "
read year5 month5 day5
./pdremove $year5 $month5 $day5

