class Jar:
    def __init__(self, capacity=12):
        if capacity > 12:
            capacity = 12
        elif capacity < 0:
            raise ValueError("Invalid Input")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        if n > self.capacity or n + self.size > self.capacity:
            raise ValueError("Capacity max")
        self._size += n

    def withdraw(self, n):
        if n > self.size:
            raise ValueError("Capacity low than min")
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

def main():
    jar = Jar()
    jar.deposit(5)
    jar.withdraw(1)
    print(str(jar))

if __name__ == "__main__":
    main()
