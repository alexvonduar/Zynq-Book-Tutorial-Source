
##############################################
# Project settings

# Create project
open_project	-reset matrix_mult_prj

# Add source files and test bench
add_files			matrix_mult.cpp
add_files			matrix_mult.h
add_files -tb	matrix_mult_test.cpp
# Specify the top-level function for synthesis
set_top				matrix_mult

###########################
# Solution settings

# Create solution1
open_solution -reset solution1

# Specify a Xilinx device and clock period
# - Do not specify a clock uncertainty (margin)
# - Let the  margin to default to 12.5% of clock period
set_part  {xc7z010clg400-1}
create_clock -period 5
#set_clock_uncertainty 1.25

# Simulate the C code 
csim_design

# Do not perform any other steps
# - The basic project will be opened in the GUI 
exit

