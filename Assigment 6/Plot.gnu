# Line width of the axes
set border linewidth 1.5
set xlabel 'Size of N'
set ylabel 'Time in Microseconds'
# Axes ranges
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 1
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 1
plot "Data.txt" using 1:2 title "Normal Case" with lines linestyle 1, \
     "Data.txt" using 1:3 title "Variant Case" with lines linestyle 2