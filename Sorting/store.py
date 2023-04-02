list1 = [1, 2, 3, 4, 5]
list2 = [2, 4, 6, 8, 10]
list3 = [3, 6, 9, 12, 15]

# Combine the lists into a list of tuples
data = list(zip(list1, list2, list3))
print(data)
# Open a file to write the data
with open("data.dat", "w") as f:
    # Write each tuple in a separate line
    for row in data:
        f.write("{}\t{}\t{}\n".format(*row))