# RemovePrimer
# Language: C++
# Input: TXT
# Output: FASTA
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: AmpliconNoise 1.29

PluMA plugin to remove primers from sequences (Quince et al, 2011).

The plugin accepts as input a TXT file of tab-delimited keyword-value pairs:
primer: Primer sequence
fastafile: Input sequences

Output FASTA file is the input sequences, without the primer.
