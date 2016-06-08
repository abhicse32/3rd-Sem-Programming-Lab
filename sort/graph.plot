set key right bottom
set terminal png 

set xlabel "Array Size"
set ylabel "Average Time"
set output "plot.png"
plot "./times.dat" using 1:2 title 'Mergesort' with lines, \
    "./times.dat" using 1:3 title 'Quicksort' with lines, \
    "./times.dat" using 1:4 title 'Insertionsort' with lines
