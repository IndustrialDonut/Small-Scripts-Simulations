
chars = {1 : 'I', 5 : 'V', 10 : 'X', 50 : 'L', 100 : 'C', 500 : 'D', 1000 : 'M', 5000: 'V̅', 10000: 'x̄'}

def int2roman(num):

    if num == 0:
        return ''

    base = _biggestBase(num)

    return base[0] + int2roman(num - base[1])


def _biggestBase(num):

    subtractor = 1
    last = 1

    for val in chars.keys():

        if num == val:  # biggest base if num is the base
            return (chars[num], num)

        if num >= val - subtractor and num < val:
            return (chars[subtractor] + chars[val], val - subtractor)

        if num > last and num < val - subtractor:
            return (chars[last], last)

        # else the loop continues to sweep

        last = val
        if str(val)[0] != '5':
            subtractor = val

    return ('x̄', 10000)

if __name__ == '__main__':
    for i in range(1, 40000):
        print(i, ' : ', int2roman(i))
