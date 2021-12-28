# Line width of the axes
set border linewidth 1.5
set xlabel 'Value of N'
set ylabel 'Time in Seconds(logarithmic scale)'
set logscale y 2
set yrange [0:0.00001]
# Axes ranges
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 1
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 1
set style line 3 linecolor rgb '#44ee66' linetype 1 linewidth 1
set style line 4 linecolor rgb '#cc00ff' linetype 1 linewidth 1
plot "Bottom_Data.txt" using 1:2 title "Bottom Up Case" with lines linestyle 2, \
     "Closed_Data.txt" using 1:2 title "Closed Data Case" with lines linestyle 3, \
     "Matrix_Data.txt"  using 1:2 title "Matrix Case" with lines linestyle 4, \
     "Naive_Data.txt" using 1:2 title "Naive Case" with lines linestyle 1 