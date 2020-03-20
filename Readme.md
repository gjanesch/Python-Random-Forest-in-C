Short bits of code which demonstrate the basic implementation of a (fairly specific) random forest in C.  To use:

1. Compile the C code on your machine.
2. Run through the cells in the Jupyter notebook until a collection of CSV files are produced.
3. Call the compiled tree_to_binary module with the CSV files as arguments (or just <tt>tree*.csv</tt>, if appropriate).
4. Call the compiled predict module with the contents of one row of the dataframe (from Python) as arguments.
