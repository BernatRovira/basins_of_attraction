set term postscript enhanced eps color font ',15'

set output 'basins_adaptation.eps'
#set output '| epstopdf --filter --outfile=basins_adaptation.pdf'

#set tmargin 0.1
#set bmargin 1.15
#set lmargin 2.75
#set rmargin 0.0


set cbrange [0:]
set yrange [0:100] 
set xrange [00:] 
#set logscale 
set key bottom right
set cblabel 'Hamming Distance' #offset 0,1.95
set ylabel 'Attractor Age'# offset 4.5
set xlabel 'Time step'# offset -2

#set cbtics (0,1) offset -1.49,-0.35
#set xtics ("150" 0) offset 1.20,0.5
#set ytics ("100" 1000) offset 0.95,-0.35
#set label '0' at 0,0 offset -1.05,0.35
#set label '0' at 149,0 offset -0.55,-0.48
#set title 'IE=+0, sigma=1'

#set boxwidth 0.5
#set style fill solid
p 'data_adapt' matrix with image
