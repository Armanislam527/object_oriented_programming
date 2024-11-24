// Variable Declaration
String name = "Alice";
int age = 30;

// Control Structures
if (age >= 18) {
    System.out.println("Adult");
} else {
    System.out.println("Minor");
}

// Function Definition
public static String greet(String name) {
    return "Hello, " + name + "!";

}

// Class Definition
class Animal {

    String name;

    public Animal(String name) {
        this.name = name;
    }

    public String speak() {
        return "I am an animal.";
    }
}

// Main Method and Object Creation
public class Main {

    public static void main(String[] args) {
        Animal dog = new Animal("Dog");
        System.out.println(dog.speak());  // Output: I am an animal.
    }
}
