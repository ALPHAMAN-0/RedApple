package OOP;

// Abstract class
abstract class Animal {
    // Abstract method (does not have a body)
    public abstract void sound();

    // Regular method
    public void sleep() {
        System.out.println("This animal is sleeping.");
    }
}

// Subclass (inherits from Animal)
class Dog extends Animal {
    @Override
    public void sound() {
        System.out.println("Dog barks");
    }
}

// Subclass (inherits from Animal)
class Cat extends Animal {
    @Override
    public void sound() {
        System.out.println("Cat meows");
    }
}

public class AbstractionExample {
    public static void main(String[] args) {
        // Create objects of Dog and Cat
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        // Call the abstract method
        myDog.sound();
        myCat.sound();

        // Call the regular method
        myDog.sleep();
        myCat.sleep();
    }
}
