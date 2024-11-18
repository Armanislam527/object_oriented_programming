

//defiine a class called Person
public class Person {

    //attributes (variable ) to store name and age
    private String name;
    private int age;

    //construct or to initialize attributes
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void introduce() {
        System.out.println("Hi I'm " + name + "and I'm " + age + " years old");
    }

    public static void main(String[] args) {
        Person person1 = new Person("arman", 22);
        Person person2 = new Person("bob", 30);
        person1.introduce();
        person2.introduce(); 
    }
}
