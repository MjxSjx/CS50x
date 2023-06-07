import csv
import sys

def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # initiate a "sequences" list save all subsequences
    sequences = []
    # initiate a "dnafile" dictionary 
    dnafile = {}
    with open(sys.argv[1]) as dictfile:
        for index, row in enumerate(dictfile):
            if index == 0:
                sequences = [sequence for sequence in row.strip().split(",")][1:]
            else:
                name = row.strip().split(",")
                dnafile[name[0]] = name[1:]

    with open(sys.argv[2], "r") as txtfile:
        sqcfile = txtfile.read().replace('\n', '')

    # initiate a "result" list to save results
    result = [longest_match(sqcfile, subsequence) for subsequence in sequences]

    # leave the program if there is a match, and print 
    for s in dnafile:
        count = 0
        for j in range(len(dnafile[s])):
            if result[j] == int(dnafile[s][j]):
                count += 1
        if count == len(sequences):
            return print(s)

    return print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence 
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # If match, move substring 
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update matches 
        longest_run = max(longest_run, count)

    return longest_run

main()
