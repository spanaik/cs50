

def main():
    while(True):
        try:
            credit_card = int(input("Enter valid Credit Card no:"))
        except:
            continue
        else:
            break
    sumOdd, sumEven,count, product = 0, 0, 0, 1
    credit_card_list = str(credit_card)
    for index,digit in enumerate(credit_card_list[::-1]):
        if index % 2 != 0:
            product = int(digit) * 2
            if product >= 10:
                sumOdd += product % 10
                sumOdd += product // 10
            else:
                sumOdd += product
        else:
            sumEven += int(digit)
        count+=1
    checSum = sumEven + sumOdd
    if str(checSum).endswith("0"):
        valid = True
    else:
        valid = False
    if valid:
        if credit_card_list.startswith("4") and (count == 13 or count == 16):
            print("VISA")
        elif (credit_card_list.startswith("34") or credit_card_list.startswith("37")) and count == 15:
            print("AMEX")
        elif (credit_card_list.startswith("51") or credit_card_list.startswith("52") or credit_card_list.startswith("53") or credit_card_list.startswith("54") or credit_card_list.startswith("55")) and count == 16:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()