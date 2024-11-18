from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass
    
class Circle(Shape):

    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius * self.radius


class Rectangle(Shape):

    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height


class Triangle(Shape):

    def __init__(self, base, height):
        self.base = base
        self.height = height

    def area(self):
        return 0.5 * self.base * self.height
class Square(Shape):
    def __init__(self, side):
        self.side = side
    def area(self):
        return self.side * self.side

circle = Circle(5)
rectangle = Rectangle(4, 6)
triangle = Triangle(4, 7)
square = Square(5)
print(f"Area of cirlce: {circle.area()}")
print(f"Area of rectangle: {rectangle.area()}")
print(f"Area of triangle: {triangle.area()}")
print(f"Area of square: {square.area()}")
shapes = [Circle(5), Rectangle(4, 6), Triangle(4, 7),Square(5)]

# Error-prone approach without abstraction
for arman in shapes:
    if isinstance(arman, Circle):
        print(arman.area())
    elif isinstance(arman, Rectangle):
        print(arman.area())
    elif isinstance(arman, Triangle):
        print(arman.area())
    elif isinstance(arman, Square):
        print(arman.area())
