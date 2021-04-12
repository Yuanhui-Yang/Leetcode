1195. Fizz Buzz Multithreaded
https://leetcode.com/problems/fizz-buzz-multithreaded/

Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.

import threading

class FizzBuzz:
    def __init__(self, n: int):
        self.n = n

        self.flag = True
        
        self.lock4Main = threading.Lock()
        
        self.lock4fizz = threading.Lock()
        self.lock4fizz.acquire()
        
        self.lock4buzz = threading.Lock()
        self.lock4buzz.acquire()
        
        self.lock4fizzbuzz = threading.Lock()
        self.lock4fizzbuzz.acquire()

    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        while True:
            self.lock4fizz.acquire()
            if not self.flag:
                return
            printFizz()
            if self.lock4Main.locked():
                self.lock4Main.release()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        while True:
            self.lock4buzz.acquire()
            if not self.flag:
                return
            printBuzz()
            if self.lock4Main.locked():
                self.lock4Main.release()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        while True:
            self.lock4fizzbuzz.acquire()
            if not self.flag:
                return
            printFizzBuzz()
            if self.lock4Main.locked():
                self.lock4Main.release()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1, self.n + 1):
            self.lock4Main.acquire()
            if i % 15 == 0:
                if self.lock4fizzbuzz.locked():
                    self.lock4fizzbuzz.release()
            elif i % 3 == 0:
                if self.lock4fizz.locked():
                    self.lock4fizz.release()
            elif i % 5 == 0:
                if self.lock4buzz.locked():
                    self.lock4buzz.release()
            else:
                printNumber(i)
                if self.lock4Main.locked():
                    self.lock4Main.release()
        
        self.lock4Main.acquire()
        self.flag = False
        if self.lock4Main.locked():
            self.lock4Main.release()
        if self.lock4fizzbuzz.locked():
            self.lock4fizzbuzz.release()
        if self.lock4fizz.locked():
            self.lock4fizz.release()
        if self.lock4buzz.locked():
            self.lock4buzz.release()

def printFizz():
    print("fizz")

def printBuzz():
    print("buzz")

def printFizzBuzz():
    print("fizzbuzz")

def printNumber(x):
    print(x)

def main():
    n = 15
    instanceOfFizzBuzz = FizzBuzz(n)
    A = threading.Thread(target=instanceOfFizzBuzz.fizz, args=(printFizz,))
    B = threading.Thread(target=instanceOfFizzBuzz.buzz, args=(printBuzz,))
    C = threading.Thread(target=instanceOfFizzBuzz.fizzbuzz, args=(printFizzBuzz,))
    D = threading.Thread(target=instanceOfFizzBuzz.number, args=(printNumber,))

    pools = [A, B, C, D]

    for i in pools:
        i.start()

    for i in pools:
        i.join()

if __name__ == "__main__":
    main()