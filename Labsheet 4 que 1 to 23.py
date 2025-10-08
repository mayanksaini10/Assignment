# ================================
# Python Programming Task Solutions
# ================================

# 1. Print "Hello, World!"
print("1. Hello, World!")

# 2. Print multiple values
print("2.", "Python", "is", "fun")

# 3. Arithmetic operations
a, b = 10, 3
print("3. Addition:", a+b)
print("   Subtraction:", a-b)
print("   Multiplication:", a*b)
print("   Division:", a/b)
print("   Modulus:", a%b)
print("   Exponentiation:", a**b)

# 4. Odd or even
num = 7
print("4.", num, "is Even" if num % 2 == 0 else "Odd")

# 5. Categorize number
num = -5
if num > 0:
    print("5.", num, "is Positive")
elif num < 0:
    print("5.", num, "is Negative")
else:
    print("5.", num, "is Zero")

# 6. Leap year check
year = 2024
if (year % 400 == 0) or (year % 100 != 0 and year % 4 == 0):
    print("6.", year, "is a Leap Year")
else:
    print("6.", year, "is Not a Leap Year")

# 7. Print numbers 1 to N
N = 5
print("7. Numbers from 1 to N:")
for i in range(1, N+1):
    print(i, end=" ")
print()

# 8. Squares 0 to N-1
print("8. Squares:")
for i in range(N):
    print(i**2, end=" ")
print()

# 9. Reverse number using while
num = 1234
rev = 0
n = num
while n > 0:
    rev = rev*10 + n%10
    n //= 10
print("9. Reverse of", num, "is", rev)

# 10. Factorial function
def factorial(n):
    return 1 if n==0 else n*factorial(n-1)
print("10. Factorial of 5 =", factorial(5))

# 11. Prime check
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True
print("11. 17 is Prime?", is_prime(17))

# 12. Fibonacci sequence
def fibonacci(n):
    seq = [0,1]
    for i in range(2,n):
        seq.append(seq[-1] + seq[-2])
    return seq[:n]
print("12. Fibonacci 10 terms:", fibonacci(10))

# 13. List operations
lst = [3,1,4]
lst.append(5)
lst.insert(1,2)
lst.remove(4)
lst.sort()
print("13. List operations:", lst)

# 14. List comprehension (even squares)
even_squares = [x**2 for x in range(10) if x%2==0]
print("14. Even squares:", even_squares)

# 15. Tuple immutability
tup = (1,2,3)
print("15. Tuple:", tup)
# tup[0] = 5  # This would raise an error (immutable)

# 16. Set to remove duplicates
dup_list = [1,2,2,3,4,4,5]
unique = set(dup_list)
print("16. Unique values:", unique)

# 17. Dictionary operations
d = {"name":"Alice", "age":25}
d["city"] = "London"
print("17. Dictionary:", d)

# 18. Count vowels
s = "hello world"
vowels = "aeiou"
count = sum(1 for ch in s if ch in vowels)
print("18. Vowels in string:", count)

# 19. Reverse string slicing
s = "Python"
print("19. Reverse:", s[::-1])

# 20. Palindrome check
word = "madam"
print("20.", word, "is Palindrome?", word == word[::-1])

# 21. f-strings
name = "Bob"
age = 22
print(f"21. My name is {name} and I am {age} years old.")

# 22. itertools.product
import itertools
A = [1,2]
B = ['a','b']
print("22. itertools.product:", list(itertools.product(A,B)))

# 23. collections.Counter
from collections import Counter
text = "programming"
print("23. Character frequency:", Counter(text))
