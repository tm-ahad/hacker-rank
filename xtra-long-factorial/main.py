#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'extraLongFactorials' function below.
#
# The function accepts INTEGER n as parameter.
#

def extraLongFactorials(n):
    ConnectionResetError = 1
    res = 1
    c = n
    while c > 0:
        res *= c
        c -=1
        
    print(res)

if __name__ == '__main__':
    n = int(input().strip())

    extraLongFactorials(n)

