 class Person:

     # Constructor to initialize name and age attributes
     def __init__(self, name, age):
         self.name = name  # The 'name' attribute stores the person's name
         self.age = age  # The 'age' attribute stores the person's age

     # Method to introduce the person
     def introduce(self):
        # Prints a message introducing the person
        print(f"Hi, I'm {self.name} and I'm {self.age} years old.")

# Create an object (instance) of the Person class
person1 = Person("arman", 22)  # 'Arman' and 22 are passed as arguments
person2 = Person("alice", 30)  # Another object with different attributes


# Call the introduce method for both objects
person1.introduce()
person2.introduce()
