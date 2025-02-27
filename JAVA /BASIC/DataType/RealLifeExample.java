package DataType;

public class RealLifeExample {
    public static void main(String[] args) {
        // Create variables of different data types
        int items = 50;
        float costPerItem = 9.99f;
        float totalCost = items * costPerItem;
        char currency = '$';

        // Print inventory details with formatting
        System.out.println("====== Store Inventory Cost ======");
        System.out.println("Number of items: " + items);
        System.out.println("Cost per item: " + currency + String.format("%.2f", costPerItem));
        System.out.println("Total cost: " + currency + String.format("%.2f", totalCost));
        System.out.println("===============================");
    }
}
