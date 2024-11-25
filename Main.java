public class Main {

    // Function Definition
    public static String greet(String name) {
        return "Hello, " + name + "!";
    }

    public static void main(String[] args) {
        // Variable Declaration
        String name = "Alice";
        int age = 30;

        // Control Structures
        if (age >= 18) {
            System.out.println("Adult");
        } else {
            System.out.println("Minor");
        }

        // Using the greet function
        System.out.println(greet(name));
    }
}

