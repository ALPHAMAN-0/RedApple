package OOP;

// Superclass
class Animal {
    public void sound() {
        System.out.println("Animal makes a sound");
    }
}

// Subclass
class Dog extends Animal {
    @Override
    public void sound() {
        System.out.println("Dog barks");
    }
}

// Subclass
class Cat extends Animal {
    @Override
    public void sound() {
        System.out.println("Cat meows");
    }
}

// Main class to demonstrate polymorphism
public class PolymorphismExample {
    public static void main(String[] args) {
        // Compile-time polymorphism (Method Overloading)
        PolymorphismExample example = new PolymorphismExample();
        example.display(10);
        example.display("Hello");

        // Runtime polymorphism (Method Overriding)
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        myDog.sound(); // Calls the Dog's sound method
        myCat.sound(); // Calls the Cat's sound method
    }

    // Method Overloading
    public void display(int num) {
        System.out.println("Display method with integer: " + num);
    }

    public void display(String message) {
        System.out.println("Display method with string: " + message);
    }
}