class Circle:
    def __init__(self,radius):
        self.radius = radius
    def area(self):
        return 3.14 * self.radius*self.radius
class Rectangle:
    def __init__(self,width,height):
        self.width = width
        self.height = height
    def area(self):
        return self.width*self.height
class Triangle:
    def __init__(self,base,height):
        self.base = base
        self.height = height
    def area(self):
        return 0.5 *self.base*self.height
circle = Circle(5)
rectangle = Rectangle(4,6)
triangle = Triangle(4,7)
print(f"Area of cirlce: {circle.area()}")
print(f"Area of rectangle: {rectangle.area()}")
print(f"Area of triangle: {triangle.area()}")