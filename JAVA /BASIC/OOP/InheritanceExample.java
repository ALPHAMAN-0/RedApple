package OOP;

// Superclass
class Animal {
    String name;

    public void eat() {
        System.out.println(name + " is eating.");
    }

    public void sleep() {
        System.out.println(name + " is sleeping.");
    }
}

// Subclass
class Dog extends Animal {
    public void bark() {
        System.out.println(name + " is barking.");
    }
}

public class InheritanceExample {
    public static void main(String[] args) {
        // Create an object of the subclass
        Dog dog = new Dog();
        dog.name = "Buddy";

        // Call methods from the superclass
        dog.eat();
        dog.sleep();
        System.out.println("Dog's name is " + dog.getClass().getSuperclass().getName());
        // Call method from the subclass
        dog.bark();
    }
}
