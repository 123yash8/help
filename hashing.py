Max = 10

def linear_probing(no, hash_table1):
    pos = has(no)
    for i in range(no + 1):
        if 0 in hash_table1[pos]:
            return pos
        pos = (pos + 1) % Max
    return -1

def has(no):
    return no % Max

def quad_probing(no, hash_table1):
    pos = has(no)
    for i in range(20):
        if 0 in hash_table1[pos]:
            return pos
        pos = (pos + (i * i)) % Max
    return -1

def lin_search(hash_table1):
    count1 = 0
    no = int(input("Enter the no you want to search?"))
    ind = has(no)
    for i in range(Max + 1):
        if no in hash_table1[ind]:
            print(hash_table1[ind], "at location ", ind)
            return count1
        ind = (ind + 1) % Max
        count1 = count1 + 1
    print("Element not found")
    return count1

def quad_search(hash_table1):
    count2 = 0
    no = int(input("Enter the no you want to search?"))
    ind = has(no)
    for i in range(20):
        if no in hash_table1[ind]:
            print(hash_table1[ind], "at location ", ind)
            return count2
        ind = (ind + (i * i)) % Max
        count2 = count2 + 1
    print("Element not found")
    return count2

def main():
    while True:
        print(" Menu ")
        print("1.Add element using linear probing\n2.Add element using quadratic probing\n3.Search element added by linear probing\n4.Search element added by quadaratic probing\n5.Compare the rate\n6.Exit\n")
        ch = int(input("Enter your choice:"))
        hash_table1 = [[0] for i in range(Max)]
        if ch == 1:
            n = int(input("Enter number of clients:"))
            for i in range(n):
                a = input("Enter name: ")
                b = int(input("Enter mob number: "))
                index = linear_probing(b, hash_table1)
                if index == -1:
                    print("Memory is full")
                    break
                hash_table1[index] = [a, b]
            print(hash_table1)
        elif ch == 2:
            n = int(input("Enter number of clients:"))
            for i in range(n):
                a = input("Enter name: ")
                b = int(input("Enter mob number: "))
                index = quad_probing(b, hash_table1)
                if index == -1:
                    print("Memory is full")
                    break
                hash_table1[index] = [a, b]
            print(hash_table1)
        elif ch == 3:
            cnt1 = lin_search(hash_table1)
        elif ch == 4:
            cnt2 = quad_search(hash_table1)
        elif ch == 5:
            print("Linear search required", cnt1)
            print("Quadaratic search required", cnt2)
        elif ch == 6:
            print("Exiting")
            break

main()
