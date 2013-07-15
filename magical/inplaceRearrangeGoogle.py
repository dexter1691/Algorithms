# Source: https://code.google.com/p/g-interview/source/browse/table-swap.py?spec=svn66e58430fcbf822bcb000ece930b93e99bb7fb24&r=66e58430fcbf822bcb000ece930b93e99bb7fb24

# Given a Data Structure having first n integers and next n chars. A = i1 i2 i3 ... iN c1 c2 c3 ... cN. Write an in-place algorithm to rearrange the elements of the array ass A = i1 c1 i2 c2 ... iN cN

inputs = []
inputs += [[ 1, 'A' ]]
inputs += [[ 1, 2, 'A', 'B' ]]
inputs += [[ 1, 2, 3, 'A', 'B', 'C' ]]
inputs += [[ 1, 2, 3, 4, 'A', 'B', 'C', 'D' ]]
inputs += [[ 1, 2, 3, 4, 5, 'A', 'B', 'C', 'D', 'E' ]]
inputs += [[ 1, 2, 3, 4, 5, 6, 'A', 'B', 'C', 'D', 'E', 'F' ]]
inputs += [[ 1, 2, 3, 4, 5, 6, 7, 'A', 'B', 'C', 'D', 'E', 'F', 'G' ]]
inputs += [[ 1, 2, 3, 4, 5, 6, 7, 8, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' ]]
inputs += [[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' ]]
inputs += [[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' ]]
inputs += [[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' ]]

def swap_element(table, i, j):
        tmp = table[i]
        table[i] = table[j]
        table[j] = tmp

def swap_range(table, first, last):
        size = last - first + 1
        premiddle = first + size/2 - 1

        if size > 3:
                if 2 == size % 4:
                        # Set last 2 elements
                        tmp = table[premiddle]
                        
                        for i in xrange(premiddle, last):
                                table[i] = table[i + 1]
                                print "a->->->",table,'\n'        
                        table[last - 1] = tmp
                        print " a->-> ", table,'\n'
                        swap_range(table, first, last - 2)
                        
                else:
                        # 0 = size % 4
                        #print xrange(first + size/4, premiddle + 1)
                        for i in xrange(first + size/4, premiddle + 1):
                                swap_element(table, i, i + size/4)
                                print "b->->->",table,'\n'
                        print " b->-> ", table,'\n'

                        swap_range(table, first, premiddle)
                        swap_range(table, premiddle + 1, last)

        print " -> ", table[first:last + 1], '\n'

# O(n*log(n))
def swap_recursive(table):
        swap_range(table, 0, len(table) - 1)


def getTargetPosition(table, i):
        if i < len(table)/2:
                return 2*i
        else:
                return 2*i + 1 - len(table)

def getNextStart(table, i):
        while i < len(table)/2:
                if isinstance(table[i], str) or isinstance(table[i + 1], str):
                        i += 1
                else:
                        break
        return i + 1
        
# O(n)
def swap_cycles(table):
        sentinel = '*'
        
        i = 1
        while i < len(table)/2:
                tmp = table[i]
                table[i] = sentinel
                print 'now:', table, '\n'
                while True:
                        next = getTargetPosition(table, i)
                        
                        tmp2 = table[next]
                        table[next] = tmp
                        
                        i = next
                        
                        if tmp2 == sentinel:
                                break;

                        tmp = tmp2
                        print 'now inside:', table, '\n'
                i = getNextStart(table, i)
                print 'Now:' , table, '\n'
               
        return

for input in inputs:
        print input, " -> "
        
        swap_recursive(input)
        
        print input
'''
for input in inputs:
        print input, " -> "
        
        swap_cycles(input)
        
        print input
'''
