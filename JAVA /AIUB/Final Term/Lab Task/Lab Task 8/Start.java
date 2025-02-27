abstract class Book {
    private String isbn;
    private String bookTitle;
    private String authorName;
    private double price;
    private int availableQuantity;

    public Book() {}

    public Book(String isbn, String bookTitle, String authorName, double price, int availableQuantity) {
        this.isbn = isbn;
        this.bookTitle = bookTitle;
        this.authorName = authorName;
        this.price = price;
        this.availableQuantity = availableQuantity;
    }

    public void setIsbn(String isbn) { this.isbn = isbn; }
    public void setBookTitle(String bookTitle) { this.bookTitle = bookTitle; }
    public void setAuthorName(String authorName) { this.authorName = authorName; }
    public void setPrice(double price) { this.price = price; }
    public void setAvailableQuantity(int availableQuantity) { this.availableQuantity = availableQuantity; }

    public String getIsbn() { return isbn; }
    public String getBookTitle() { return bookTitle; }
    public String getAuthorName() { return authorName; }
    public double getPrice() { return price; }
    public int getAvailableQuantity() { return availableQuantity; }

    public abstract void showDetails();
}

class StoryBook extends Book {
    private String category;

    public StoryBook() {}

    public StoryBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, String category) {
        super(isbn, bookTitle, authorName, price, availableQuantity);
        this.category = category;
    }

    public void setCategory(String category) { this.category = category; }
    public String getCategory() { return category; }

    @Override
    public void showDetails() {
        System.out.println("StoryBook Details:");
        System.out.println("ISBN: " + getIsbn());
        System.out.println("Title: " + getBookTitle());
        System.out.println("Author: " + getAuthorName());
        System.out.println("Price: " + getPrice());
        System.out.println("Available Quantity: " + getAvailableQuantity());
        System.out.println("Category: " + category);
    }
}

class TextBook extends Book {
    private int standard;

    public TextBook() {}

    public TextBook(String isbn, String bookTitle, String authorName, double price, int availableQuantity, int standard) {
        super(isbn, bookTitle, authorName, price, availableQuantity);
        this.standard = standard;
    }

    public void setStandard(int standard) { this.standard = standard; }
    public int getStandard() { return standard; }

    @Override
    public void showDetails() {
        System.out.println("TextBook Details:");
        System.out.println("ISBN: " + getIsbn());
        System.out.println("Title: " + getBookTitle());
        System.out.println("Author: " + getAuthorName());
        System.out.println("Price: " + getPrice());
        System.out.println("Available Quantity: " + getAvailableQuantity());
        System.out.println("Standard: " + standard);
    }
}

interface BookOperations {
    void addQuantity(int amount);
    void sellQuantity(int amount);
}

interface BookShopOperations {
    boolean insertBook(Book b);
    boolean removeBook(Book b);
    void showAllBooks();
    Book searchBook(String isbn);
}

class BookShop implements BookShopOperations {
    private String name;
    private Book[] listOfBooks;
    private int bookCount;

    public BookShop() {
        listOfBooks = new Book[100];
        bookCount = 0;
    }

    public BookShop(String name) {
        this();
        this.name = name;
    }

    public void setName(String name) { this.name = name; }
    public String getName() { return name; }

    @Override
    public boolean insertBook(Book b) {
        if (bookCount < 100) {
            listOfBooks[bookCount++] = b;
            return true;
        }
        return false;
    }

    @Override
    public boolean removeBook(Book b) {
        for (int i = 0; i < bookCount; i++) {
            if (listOfBooks[i] == b) {
                listOfBooks[i] = listOfBooks[--bookCount];
                listOfBooks[bookCount] = null;
                return true;
            }
        }
        return false;
    }

    @Override
    public void showAllBooks() {
        for (int i = 0; i < bookCount; i++) {
            listOfBooks[i].showDetails();
            System.out.println();
        }
    }

    @Override
    public Book searchBook(String isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (listOfBooks[i].getIsbn().equals(isbn)) {
                return listOfBooks[i];
            }
        }
        return null;
    }
}

public class Start {
    public static void main(String[] args) {
        StoryBook s1 = new StoryBook("S101", "Fairy Tales", "Grimm Brothers", 250.0, 20, "Fiction");
        StoryBook s2 = new StoryBook("S102", "Harry Potter", "J.K. Rowling", 500.0, 15, "Fantasy");


        TextBook t1 = new TextBook("T101", "Mathematics", "R.D. Sharma", 400.0, 25, 10);
        TextBook t2 = new TextBook("T102", "Physics", "H.C. Verma", 350.0, 20, 12);
  
        BookShop shop = new BookShop("AIUB BookShop");

        shop.insertBook(s1);
        shop.insertBook(s2);
     

        shop.insertBook(t1);
        shop.insertBook(t2);
  

        shop.showAllBooks();

        Book searchedBook = shop.searchBook("T101");
        if (searchedBook != null) {
            System.out.println("Book Found:");
            searchedBook.showDetails();
        } else {
            System.out.println("Book not found!");
        }
    }
}
