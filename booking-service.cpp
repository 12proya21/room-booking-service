#include <iostream>
#include <string>
#include <vector>

class Product {
public:
    Product(const std::string& name, double price)
        : name_(name), price_(price) {}

    const std::string& getName() const {
        return name_;
    }

    double getPrice() const {
        return price_;
    }

private:
    std::string name_;
    double price_;
};

class ProductSearchService {
public:
    void addProduct(const Product& product) {
        products_.push_back(product);
    }

    std::vector<Product> searchProductsByName(const std::string& query) const {
        std::vector<Product> searchResults;
        for (const auto& product : products_) {
            if (containsSubstringIgnoreCase(product.getName(), query)) {
                searchResults.push_back(product);
            }
        }
        return searchResults;
    }

private:
    bool containsSubstringIgnoreCase(const std::string& str, const std::string& substr) const {
        auto it = std::search(str.begin(), str.end(), substr.begin(), substr.end(),
                              [](char ch1, char ch2) { return std::toupper(ch1) == std::toupper(ch2); });
        return it != str.end();
    }

    std::vector<Product> products_;
};

int main() {
    ProductSearchService productSearchService;

    // Adding some products to the search service
    productSearchService.addProduct(Product("iPhone 12 Pro", 999.99));
    productSearchService.addProduct(Product("Samsung Galaxy S21", 899.99));
    productSearchService.addProduct(Product("Google Pixel 5", 799.99));
    productSearchService.addProduct(Product("Sony WH-1000XM4", 349.99));
    productSearchService.addProduct(Product("Logitech G Pro X", 129.99));

    // Searching products by name
    std::cout << "Enter the product name to search: ";
    std::string query;
    std::getline(std::cin, query);

    std::vector<Product> searchResults = productSearchService.searchProductsByName(query);
    if (searchResults.empty()) {
        std::cout << "No products found matching the search query." << std::endl;
    } else {
        std::cout << "Search Results:" << std::endl;
        for (const auto& product : searchResults) {
            std::cout << product.getName() << " - $" << product.getPrice() << std::endl;
        }
    }

    return 0;
}
