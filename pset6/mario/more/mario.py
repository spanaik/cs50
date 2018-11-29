"""
Prints brics from mario
height = 2 will give
 #  #
##  ##
"""


def main():
    while(True):
        try:
            height = int(input("Enter a positive number less than 23: "))
        except:
            continue
        else:
            if height <= 23 and height >= 0:
                break
    j = height - 1
    for i in range(height):
        print(" " * j, end="")# Repeat " " j times
        print("#" * (height - j), end="")# Repeat "#" height - j times
        print("  ", end="")# print space "  "
        print("#" * (height - j), end="")# Repeat "#" height - j times
        print()# for new line
        j -= 1


if __name__ == "__main__":
    main()