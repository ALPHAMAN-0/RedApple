#include <iostream>
#include <map>
#include <vector>

using namespace std;
class OrderedMap {
private:
    map<int, string> map;

public:
    void add(int key, const string& value) {
        map[key] = value;
    }

    string get_time() const {
        // Return the time complexity of the map operations
        return "O(log n) for access, O(log n) for insertion, O(log n) for deletion";
    }

    string get_benefits() const {
        // Return the benefits of using an ordered map
        return "Preserves insertion order, fast lookups, efficient insertion and deletion";
    }

    string get_memory() const {
        // Return the memory usage of the map
        return "Currently using " + to_string(map.size()) + " key-value pairs";
    }

    vector<std::string> get_all_functions() const {
        // Return a list of all functions available on the map
        return {"add", "get_time", "get_benefits", "get_memory", "get_all_functions"};
    }

    void print_map() const {
        // Print the contents of the map
        for (const auto& pair : map) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

// Example usage
int main() {
    OrderedMap ordered_map;
    ordered_map.add(1, "one");
    ordered_map.add(2, "two");
    ordered_map.add(3, "three");

    cout << "Time complexity: " << ordered_map.get_time() << endl;
    cout << "Benefits: " << ordered_map.get_benefits() << endl;
    cout << "Memory usage: " << ordered_map.get_memory() << endl;
    cout << "All functions: ";
    for (const auto& func : ordered_map.get_all_functions()) {
        cout << func << " ";
    }
    cout << endl;
    cout << "Map contents:" << endl;
    ordered_map.print_map();

    return 0;
}